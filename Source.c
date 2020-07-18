#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include"Header.h"


int main() {

	Stack st;
	Head h;
	Queue q;
	Calc c;

	h.lenght = 0;

	char* s = (char*)malloc(100 * sizeof(char));
	fgets(s, 100, stdin);
	int y = strlen(s) - 1;
	s[y] = '\0';

	create_token(&h, s);
	init_stack(&st, add_pr(&h));
	init_queue(&q, h.lenght);

	station(&st, &h, &q);
	print_queue(&q);

	type(&q);

	init_calc(&q, &c);
	process(&q, &c);

	printf_s("%f", c.arr[0]);

}
