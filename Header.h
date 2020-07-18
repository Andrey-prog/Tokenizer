#ifndef HEADER_H
#define HEADER_H

#define NUMBER 1
#define OPERATION 0

#define LOW 0
#define HIGH 1
#define LEFT_BRACKET 5
#define RIGHT_BRACKET -1

typedef struct Token {
	char* content;
	int type;
	int pr;
}Token;


typedef struct Head {
	Token* list;
	int lenght;
}Head;


typedef struct StackElem {
	char* content;
	int pr;
}StackElem;


typedef struct Stack {
	StackElem* elem;
	int amount;
}Stack;


typedef struct QueueElem {
	char* content;
	int type;
}QueueElem;


typedef struct Queue {
	QueueElem* elem;
	int amount;
}Queue;


typedef struct Calc {
	float* arr;
	int amount;
}Calc;

int check_type(char);
void add_to_token(Head*, char*, int );
void create_token(Head*, char*);
int precedence(char*);
int add_pr(Head*);

void init_stack(Stack*, int);
char* pop_stack(Stack*);
int find(Stack*);
void init_queue(Queue*, int);
void push_queue(Queue*, char*);
void push_stack(Stack*, Token*);

void add_to_stack(Stack*, Token*, Queue*);
void station(Stack*, Head*, Queue*);
void init_calc(Queue*, Calc*);
QueueElem* pop_queue(Queue*);
int number(char);

float transform(QueueElem*);
void calculating(Calc*, QueueElem*);
void process(Queue*, Calc*);
void print_queue(Queue*);

#endif