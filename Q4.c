#include <stdio.h>

int stack[100];
int top = -1;
int maxSize;

void pushStack();
void popStack();
void peekStack();
void displayStack();

int main() {
    printf("Enter the maximum size of the stack: ");
    scanf("%d", &maxSize);

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

        if(choice == 1){ 
            pushStack();
        }    
        else if(choice == 2){
            popStack();
        }    
        else if(choice == 3){ 
            peekStack();
        }    
        else if(choice == 4){ 
            displayStack();
        }    
        else if(choice == 5){ 
            printf("Exiting...\n");
        }    
        else{ 
            printf("Invalid choice!\n");
        }    
    }

    return 0;
}

void pushStack() {
    if(top >= maxSize - 1) {
        printf("Stack Overflow! Cannot push element.\n");
        return;
    }
    int element;
    printf("Enter element to push: ");
    scanf("%d", &element);
    top++;
    stack[top] = element;
    printf("%d pushed to stack.\n", element);
}

void popStack() {
    if(top == -1) {
        printf("Stack Underflow! Cannot pop element.\n");
        return;
    }
    printf("%d popped from stack.\n", stack[top]);
    top--;
}

void peekStack() {
    if(top == -1) {
        printf("Stack is empty. Nothing to peek.\n");
        return;
    }
    printf("Top element: %d\n", stack[top]);
}

void displayStack() {
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
