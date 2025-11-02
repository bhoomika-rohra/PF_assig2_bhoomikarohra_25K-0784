#include <stdio.h>

void getcustomerinfo(char name[], char cnic[]);
void displayinventory(int productCodes[], int quantities[], float prices[], int size);
void updateinventory(int quantities[], int index, int q);
void additem(int productCodes[], int quantities[], float prices[], int cartitem[], int qty[], int *cartcount, int size);
float displaybill(int productCodes[], float prices[], int cartitem[], int qty[], int cartcount);
void showinvoice(char name[], char cnic[], int productCodes[], float prices[], int cartitem[], int qty[], int cartcount);

int main() {
    int productCodes[4] = {1, 2, 3, 4};
    int quantities[4] = {50, 10, 20, 8};
    float prices[4] = {100, 200, 300, 150};
    char name[20], cnic[30];
    int cartitem[100], qty[100], cartcount = 0;
    int choice = 0;
    int size = 4;

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

        switch(choice) {
            case 1:
                getcustomerinfo(name, cnic);
                break;
            case 2:
                displayinventory(productCodes, quantities, prices, size);
                break;
            case 3:
                additem(productCodes, quantities, prices, cartitem, qty, &cartcount, size);
                break;
            case 4:
                displaybill(productCodes, prices, cartitem, qty, cartcount);
                break;
            case 5:
                showinvoice(name, cnic, productCodes, prices, cartitem, qty, cartcount);
                break;
            case 7:
                printf("Exiting.\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

void getcustomerinfo(char name[], char cnic[]) {
    printf("Enter customer name: ");
    scanf(" %[^\n]", name);
    printf("Enter CNIC number: ");
    scanf(" %[^\n]", cnic);
}

void displayinventory(int productCodes[], int quantities[], float prices[], int size) {
    printf("\nCode\tQuantity\tPrice\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%d\t\t%.2f\n", productCodes[i], quantities[i], prices[i]);
    }
}

void updateinventory(int quantities[], int index, int q) {
    quantities[index] -= q;
}

void additem(int productCodes[], int quantities[], float prices[], int cartitem[], int qty[], int *cartcount, int size) {
    int code, q, found = 0;
    printf("Enter product code to add to cart: ");
    scanf("%d", &code);
    for (int i = 0; i < size; i++) {
        if (productCodes[i] == code) {
            found = 1;
            printf("Enter quantity: ");
            scanf("%d", &q);
            if (q > quantities[i]) {
                printf("Insufficient stock!\n");
                return;
            }
            cartitem[*cartcount] = i;
            qty[*cartcount] = q;
            (*cartcount)++;
            updateinventory(quantities, i, q);
            printf("%d item(s) of code %d added to cart!\n", q, code);
            return;
        }
    }
    if (!found) {
        printf("Item not available!\n");
    }
}

float displaybill(int productCodes[], float prices[], int cartitem[], int qty[], int cartcount) {
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

    // Manual comparison with "Eid2025"
    if (promocode[0]()
