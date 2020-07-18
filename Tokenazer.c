#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include"Header.h"


int check_type(char a) {

	int c = 0;

	if ((unsigned)a >= (unsigned)'0' && (unsigned)a <= (unsigned)'9') {
		c++;
	}

	return c;
}


void add_to_token(Head* head, char* temp, int type) {

	int k = strlen(temp);

	if (head->lenght == 0) {
		head->list = (Token*)malloc(sizeof(Token));
	}
	else {
		head->list = (Token*)realloc(head->list, (head->lenght + 1) * sizeof(Token));
	}

	head->list[head->lenght].content = (char*)malloc((k + 1) * sizeof(char));
	strcpy(head->list[head->lenght].content, temp);
	head->list[head->lenght].content[k] = '\0';

	head->list[head->lenght].type = type;
	head->lenght++;

}


void create_token(Head* head, char* s) {

	int k = strlen(s);
	for (int i = 0; i < k; i++) {

		if (check_type(s[i]) == 0) {
			char* temp = (char*)malloc(2 * sizeof(char));
			temp[0] = s[i];
			temp[1] = '\0';
			add_to_token(head, temp, OPERATION);
		}
		else {

			int c = 0;
			while (check_type(s[i + c]) != 0) {
				c++;
			}
			char* temp = (char*)malloc((c + 1) * sizeof(char));
			for (int j = 0; j < c; j++) {
				temp[j] = s[i + j];
			}
			temp[c] = '\0';
			i += c - 1;
			add_to_token(head, temp, NUMBER);
		}
	}
}


int precedence(char* a) {

	switch (a[0]) {
	case '+':
		return LOW;
	case '-':
		return LOW;
	case '*':
		return HIGH;
	case '/':
		return HIGH;
	case '(':
		return LEFT_BRACKET;
	case ')':
		return RIGHT_BRACKET;
	}
}


int add_pr(Head* h) {

	int c = 0;

	for (int i = 0; i < h->lenght; i++) {
		if (h->list[i].type == OPERATION) {
			h->list[i].pr = precedence(h->list[i].content);
			c++;
		}
	}
	return c;
}


void station(Stack* st, Head* h, Queue* q) {

	for (int i = 0; i < h->lenght; i++) {

		if (h->list[i].type == OPERATION) {
			add_to_stack(st, &(h->list[i]), q);
		}
		else {
			push_queue(q, h->list[i].content);
		}
	}

	while (st->amount != 0) {
		push_queue(q, pop_stack(st));
	}
}