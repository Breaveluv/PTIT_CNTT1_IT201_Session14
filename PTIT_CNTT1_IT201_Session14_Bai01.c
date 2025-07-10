#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *next;

}Node;
typedef struct Stack {
    Node *top;
}Stack;
Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
Stack *createStack() {
    Stack *newStack = (Stack *)malloc(sizeof(Stack));
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
    printf("Pushed %d onto the stack.\n", data);

}
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return -1;
    }
    Node *temp = stack->top;
    int data = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return data;

}
void display(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    Node *curr = stack->top;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");

}
int main() {
    Stack *myStack = createStack();
    if (isEmpty(myStack)) {
        printf("Stack is empty.\n");
    }
    push(myStack, 10);
    push(myStack, 20);
    push(myStack, 30);
    push(myStack, 40);
    printf("\n");
    display(myStack);
    printf("\n");
    int value = pop(myStack);
    if (value == -1) {
        printf("Popped element %d from the stack\n");

    }
    display(myStack);
    printf("\n");
    pop(myStack);
    pop(myStack);
    display(myStack);
    free(myStack);
    return 0;
}