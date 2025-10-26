#include <stdio.h>

void getcustomerinfo();
void displayinventory();
void updateinventory(int index, int q);
void additem();
float displaybill();
void showinvoice();

int productCodes[4] = {1, 2, 3, 4};
int quantities[4] = {50, 10, 20, 8};
float prices[4] = {100, 200, 300, 150};
char name[20];
char cnic[30];
int cartitem[100];
int qty[100];
int cartcount = 0;

int main() {
    int choice = 0;
    while (choice != 7) {
        printf("\n--- Supermarket Menu ---\n");
        printf("1. Customer Information\n");
        printf("2. Display Inventory\n");
        printf("3. Add Item to Cart\n");
        printf("4. Display Total Bill\n");
        printf("5. Show Invoice\n");
        printf("6. (Optional/Unused)\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            getcustomerinfo();
        } else if (choice == 2) {
            displayinventory();
        } else if (choice == 3) {
            additem();
        } else if (choice == 4) {
            displaybill();
        } else if (choice == 5) {
            showinvoice();
        } else if (choice == 7) {
            printf("Exiting.\n");
        } else {
            printf("Invalid choice!\n");
        }
    }
    return 0;
}

void getcustomerinfo() {
    printf("Enter customer name: ");
    scanf(" %[^\n]", name);
    printf("Enter CNIC number: ");
    scanf(" %[^\n]", cnic);
}

void displayinventory() {
    printf("\nCode\tQuantity\tPrice\n");
    for (int i = 0; i < 4; i++) {
        printf("%d\t%d\t\t%.2f\n", productCodes[i], quantities[i], prices[i]);
    }
}

void updateinventory(int index, int q) {
    quantities[index] -= q;
}

void additem() {
    int code, q, found = 0;
    printf("Enter product code to add to cart: ");
    scanf("%d", &code);
    for (int i = 0; i < 4; i++) {
        if (productCodes[i] == code) {
            found = 1;
            printf("Enter quantity: ");
            scanf("%d", &q);
            if (q > quantities[i]) {
                printf("Insufficient stock!\n");
                return;
            }
            cartitem[cartcount] = i;
            qty[cartcount] = q;
            cartcount++;
            updateinventory(i, q);
            printf("%d item(s) of code %d added to cart!\n", q, code);
            return;
        }
    }
    if (!found) {
        printf("Item not available!\n");
    }
}

float displaybill() {
    float total = 0;
    char promocode[20];
    printf("\nCode\tQuantity\tPrice\tSubtotal\n");
    for (int i = 0; i < cartcount; i++) {
        float subtotal = prices[cartitem[i]] * qty[i];
        total += subtotal;
        printf("%d\t%d\t\t%.2f\t%.2f\n", productCodes[cartitem[i]], qty[i], prices[cartitem[i]], subtotal);
    }
    printf("Total: %.2f\n", total);

    printf("Enter promocode (if any): ");
    scanf(" %[^\n]", promocode);
    if (promocode[0] == 'E' && promocode[1] == 'i' && promocode[2] == 'd' &&
        promocode[3] == '2' && promocode[4] == '0' && promocode[5] == '2' &&
        promocode[6] == '5' && promocode[7] == '\0') {
        total *= 0.75;
        printf("25%% discount applied!\n");
    }

    printf("Final Bill: %.2f\n", total);
    return total;
}

void showinvoice() {
    printf("\n--- Invoice ---\n");
    printf("Name: %s\nCNIC: %s\n", name, cnic);
    displaybill();
}
