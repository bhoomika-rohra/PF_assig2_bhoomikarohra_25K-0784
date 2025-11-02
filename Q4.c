#include <stdio.h>

void pushStack(int stack[], int *top, int maxSize);
void popStack(int stack[], int *top);
void peekStack(int stack[], int top);
void displayStack(int stack[], int top);

int main() {
    int maxSize;
    printf("Enter the maximum size of the stack: ");
    scanf("%d", &maxSize);

    int stack[maxSize];
    int top = -1;
    int choice = 0;

    while(choice != 5) {
        printf("\n--- Stack Operations Menu ---\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. PEEK\n");
        printf("4. DISPLAY\n");
        printf("5. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                pushStack(stack, &top, maxSize);
                break;
            case 2:
                popStack(stack, &top);
                break;
            case 3:
                peekStack(stack, top);
                break;
            case 4:
                displayStack(stack, top);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

void pushStack(int stack[], int *top, int maxSize) {
    if(*top >= maxSize - 1) {
        printf("Stack Overflow! Cannot push element.\n");
        return;
    }
    int element;
    printf("Enter element to push: ");
    scanf("%d", &element);
    (*top)++;
    stack[*top] = element;
    printf("%d pushed to stack.\n", element);
}

void popStack(int stack[], int *top) {
    if(*top == -1) {
        printf("Stack Underflow! Cannot pop element.\n");
        return;
    }
    printf("%d popped from stack.\n", stack[*top]);
    (*top)--;
}

void peekStack(int stack[], int top) {
    if(top == -1) {
        printf("Stack is empty. Nothing to peek.\n");
        return;
    }
    printf("Top element: %d\n", stack[top]);
}

void displayStack(int stack[], int top) {
    if(top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements (top to bottom): ");
    for(int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

