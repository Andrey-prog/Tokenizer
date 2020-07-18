#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include"Header.h"


void init_stack(Stack* st, int c) {

	st->elem = (StackElem*)malloc(c * sizeof(StackElem));
	st->amount = 0;
	for (int i = 0; i < c; i++) {
		st->elem[i].content = (char*)malloc(2 * sizeof(char));
	}
}


char* pop_stack(Stack* st) {

	st->amount--;
	return st->elem[st->amount].content;
}


int find(Stack* st) {

	int c = -1;
	for (int i = st->amount; i > 0; i--) {
		if (st->elem[i - 1].pr == LEFT_BRACKET) {
			c = i - 1;
			break;
		}
	}

	return c;
}


void push_stack(Stack* st, Token* token) {

	st->elem[st->amount].pr = token->pr;
	st->elem[st->amount].content[0] = token->content[0];
	st->elem[st->amount].content[1] = '\0';
	st->amount++;
}


void add_to_stack(Stack* st, Token* token, Queue* q) {

	if (st->amount != 0) {
		if (token->pr > st->elem[st->amount - 1].pr) {
			push_stack(st, token);

		}
		else {

			int f = find(st);
			if (f != -1) {

				if (token->pr == RIGHT_BRACKET) {
					while (st->elem[st->amount - 1].pr != LEFT_BRACKET) {
						push_queue(q, pop_stack(st));
					}
					st->amount--;
				}

				else {
					for (int i = st->amount - 1; i > f; i--) {
						if (st->elem[i].pr >= token->pr) {
							push_queue(q, pop_stack(st));
						}
					}
					push_stack(st, token);
				}
			}
			else {

				for (int i = st->amount; i > 0; i--) {
					if (st->elem[st->amount - 1].pr >= token->pr) {
						push_queue(q, pop_stack(st));
					}
				}
				push_stack(st, token);
			}
		}
	}
	else {

		push_stack(st, token);
	}
}