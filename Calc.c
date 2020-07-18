#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include"Header.h"


void init_calc(Queue*q, Calc* c) {

	int u = 0;
	for (int i = 0; i < q->amount; i++) {
		if (q->elem[i].type == NUMBER) {
			u++;
		}
	}

	c->amount = 0;
	c->arr = (float*)malloc(u*sizeof(float));

}


int number(char a) {

	switch (a) {
	case '0':
		return 0;
	case '1':
		return 1;
	case '2':
		return 2;
	case '3':
		return 3;
	case '4':
		return 4;
	case '5':
		return 5;
	case '6':
		return 6;
	case '7':
		return 7;
	case '8':
		return 8;
	case '9':
		return 9;
	}
}


float transform(QueueElem* qe) {

	int k = strlen(qe->content);

	float res = 0;

	for (int i = 0; i < k; i++) {

		int a = pow(10, (k - 1 - i));
		a = a * number(qe->content[i]);
		res += a;
	}


	return res;
}


void calculating(Calc* c, QueueElem* q) {

	float res = 0;

	switch (q->content[0]) {
	case '+':
		res = c->arr[c->amount - 2] + c->arr[c->amount - 1];
		break;
	case '-':
		res = c->arr[c->amount - 2] - c->arr[c->amount - 1];
		break;
	case '*':
		res = c->arr[c->amount - 2] * c->arr[c->amount - 1];
		break;
	case '/':
		res = c->arr[c->amount - 2] / c->arr[c->amount - 1];
		break;
	}

	c->amount--;
	c->arr[c->amount - 1] = res;
}


void process(Queue* q, Calc* c) {

	int k = q->amount;
	for (int i = 0; i < k; i++) {

		while (q->elem[0].type != OPERATION) {
			c->arr[c->amount] = transform(pop_queue(q));
			c->amount++;
			i++;
		}

		calculating(c, pop_queue(q));
	}

}
