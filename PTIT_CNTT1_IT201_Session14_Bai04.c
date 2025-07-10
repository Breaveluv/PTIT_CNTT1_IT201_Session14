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

void display(Stack *stack) {
    printf("stack={");
    Node *curr = stack->top;
    while (curr != NULL) {
        printf("%d->", curr->data);
        curr = curr->next;
    }
    printf("NULL}\n");
}


int pop(Stack *stack) {
    
    if (isEmpty(stack)) {
        printf("Ngăn xếp trống\n");
        return -1;
    }

    Node *temp = stack->top;
    int popped_data = temp->data;

    stack->top = stack->top->next;

   
    free(temp);


    return popped_data;
}

void freeStack(Stack *stack) {

    while (!isEmpty(stack)) {
        pop(stack);
    }
    
    free(stack);
}

int main() {

    printf("--- Truong hop 1 ---\n");
    Stack *stack1 = createStack();

    push(stack1, 5);
    push(stack1, 4);
    push(stack1, 3);
    push(stack1, 2);
    push(stack1, 1);

    printf("Input:\n");
    display(stack1);

    printf("\nOutput:\n");
    int popped_value = pop(stack1); 
    if (popped_value != -1) {
        printf("Gia tri duoc lay ra: %d\n", popped_value);
    }
    printf("Ngan xep sau khi lay ra:\n");
    display(stack1); 

    freeStack(stack1);

    printf("\n=============================\n\n");

    
    printf("--- Truong hop 2 ---\n");
    Stack *stack2 = createStack();

    printf("Input:\n");
    display(stack2);

    printf("\nOutput:\n");
    pop(stack2); 

    freeStack(stack2);

    return 0;
}
