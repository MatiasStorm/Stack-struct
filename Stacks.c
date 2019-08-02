#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


typedef struct stackElem{
  int val;
  struct stackElem *next;
}stackElem;


stackElem* initStackElem(int val){
  stackElem *elem;
  elem = (stackElem*) malloc(sizeof(stackElem));
  elem->val = val;
  elem->next = NULL;
  return elem;  
}

typedef struct stack{
  struct stackElem *top;
}stack;


stack* initStack(){
  stack *s;
  s = (stack*) malloc(sizeof( stack));
  s->top = NULL;
  return s;
} 

void push(stack *s, int val){
  stackElem *elem = initStackElem(val);
  if(s->top == NULL){
    s->top = elem;
  }
  else{
    elem->next = s->top;
    s->top = elem;
  }
}

int pop(stack *s){
  if(s->top == NULL){
    printf("Underflow Error");
    return -1;
  }
  int r = s->top->val;
  s->top = s->top->next;
  return r;
}

int peek(stack *s){
  return s->top->val;
}

bool isEmpty(stack *s){
  return (s->top == NULL);
}

void printStack(stack *s){
  stackElem *x = s->top;
  printf("[%d, ", x->val);
  
  do {
    x = x->next;
    printf("%d, ", x->val);
  } while(x->next->next != NULL);
  
  printf("%d]", x->next->val);
}


int main(){
  stack *s = initStack();
  push(s, 2);
  push(s, -1);
  push(s, 5);
  push(s, 6);
  push(s, 7);
  printf("POP: %d\n", pop(s));
  printf("Peek: %d\n", peek(s));
  printf("The stack: ");
  printStack(s);
  
  return 0;
}
