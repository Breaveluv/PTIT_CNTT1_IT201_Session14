#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Stack {
    Node *top;
} Stack;

Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Stack *createStack() {
    Stack *newStack = (Stack *)malloc(sizeof(Stack));
    if (newStack == NULL) {
        exit(1);
    }
    newStack->top = NULL;
    return newStack;
}

int isEmpty(Stack *stack) {
    return stack->top == NULL;
}

void push(Stack *stack, int data) {
    Node *newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(Stack *stack) {
    if (isEmpty(stack)) {
        return -1;
    }
    Node *temp = stack->top;
    int data = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

void freeStack(Stack *stack) {
    while (!isEmpty(stack)) {
        pop(stack);
    }
    free(stack);
}

int peek(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Ngan xep trong\n");
        return -1;
    }
    return stack->top->data;
}

int main() {
    Stack *stack1 = createStack();
    push(stack1, 5);
    push(stack1, 4);
    push(stack1, 3);
    push(stack1, 2);
    push(stack1, 1);

    int topValue = peek(stack1);
    if (topValue != -1) {
        printf("%d\n", topValue);
    }
    freeStack(stack1);

    printf("\n");

    Stack *stack2 = createStack();
    peek(stack2);
    freeStack(stack2);

    return 0;
}