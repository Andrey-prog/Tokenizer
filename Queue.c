#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include"Header.h"


void init_queue(Queue* q, int a) {

	q->amount = 0;
	q->elem = (QueueElem*)malloc(a * sizeof(QueueElem));
}


void push_queue(Queue* q, char* str) {

	int k = strlen(str);
	q->elem[q->amount].content = (char*)malloc((k + 1) * sizeof(char));

	strcpy(q->elem[q->amount].content, str);
	q->elem[q->amount].content[k] = '\0';
	q->amount++;

}

QueueElem* pop_queue(Queue* q) {

	int m = strlen(q->elem[0].content);

	QueueElem* zero;
	zero = (QueueElem*)malloc(sizeof(QueueElem));
	zero->content = (char*)malloc((m + 1) * sizeof(char));

	strcpy(zero->content, q->elem[0].content);
	zero->content[m] = '\0';
	zero->type = q->elem[0].type;
	q->amount--;

	if (q->amount != 0) {

		QueueElem* temp = (QueueElem*)malloc(q->amount * sizeof(QueueElem));
		for (int i = 0; i < q->amount; i++) {

			int k = strlen(q->elem[i + 1].content);

			temp[i].content = (char*)malloc((k + 1) * sizeof(char));
			strcpy(temp[i].content, q->elem[i + 1].content);
			temp[i].content[k] = '\0';
			temp[i].type = q->elem[i + 1].type;
		}
		free(q->elem);
		q->elem = temp;
	}

	return zero;
}


void type(Queue* q) {

	for (int i = 0; i < q->amount; i++) {
		q->elem[i].type = check_type(q->elem[i].content[0]);
	}

}


void print_queue(Queue* q) {

	for (int i = 0; i < q->amount - 1; i++) {
		printf_s("%s ", q->elem[i].content);
	}
	printf_s("%s = ", q->elem[q->amount - 1].content);
}
