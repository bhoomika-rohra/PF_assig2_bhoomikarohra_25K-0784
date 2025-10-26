#include <stdio.h>

int addbook(int isbns[100], char titles[100][50], float prices[100], int quantities[100], int count);
void ProcessSale(int isbns[100], int quantities[100], int count);
void GenerateReport(int isbns[100], char titles[100][50], float prices[100], int quantities[100], int count);

int main() {
    int isbns[100];
    char titles[100][50];
    float prices[100];
    int quantities[100];
    int count = 0;
    int choice = 0;

    printf("----- Liberty Books Inventory System ------\n");

    while (choice != 4) {
        printf("\n1. Add New Book\n");
        printf("2. Process Sale\n");
        printf("3. Generate Low Stock Report\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                count = addbook(isbns, titles, prices, quantities, count);
                break;
            case 2:
                ProcessSale(isbns, quantities, count);
                break;
            case 3:
                GenerateReport(isbns, titles, prices, quantities, count);
                break;
            case 4:
                printf("Exiting.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

int addbook(int isbns[100], char titles[100][50], float prices[100], int quantities[100], int count) {
    int newIsbn, i, newQuantity;
    float newPrice;

    if (count >= 100) {
        printf("Inventory full. Cannot add more books.\n");
        return count;
    }

    printf("Enter ISBN: ");
    scanf("%d", &newIsbn);

    for (i = 0; i < count; i++) {
        if (isbns[i] == newIsbn) {
            printf("Error: ISBN already exists.\n");
            return count;
        }
    }

    printf("Enter Title: ");
    scanf("%49s", titles[count]);
    printf("Enter Price: ");
    scanf("%f", &newPrice);
    printf("Enter Quantity: ");
    scanf("%d", &newQuantity);

    isbns[count] = newIsbn;
    prices[count] = newPrice;
    quantities[count] = newQuantity;

    printf("Book added successfully!\n");

    return count + 1;
}

void ProcessSale(int isbns[100], int quantities[100], int count) {
    int isbn, sold, i, found = 0;

    if (count == 0) {
        printf("No books available.\n");
        return;
    }

    printf("Enter ISBN: ");
    scanf("%d", &isbn);
    printf("Enter number of copies sold: ");
    scanf("%d", &sold);

    for (i = 0; i < count; i++) {
        if (isbns[i] == isbn) {
            found = 1;
            if (quantities[i] >= sold) {
                quantities[i] = quantities[i] - sold;
                printf("Sale processed. Remaining quantity: %d\n", quantities[i]);
            } else {
                printf("Not enough stock.\n");
            }
            break;
        }
    }

    if (!found) {
        printf("Book with ISBN %d not found.\n", isbn);
    }
}

void GenerateReport(int isbns[100], char titles[100][50], float prices[100], int quantities[100], int count) {
    int i;
    int lowStockFound = 0;

    if (count == 0) {
        printf("No books found.\n");
        return;
    }

    printf("\n--- LOW STOCK REPORT ---\n");

    for (i = 0; i < count; i++) {
        if (quantities[i] < 5) {
            printf("ISBN: %d | Title: %s | Price: %.2f | Quantity: %d\n",
                   isbns[i], titles[i], prices[i], quantities[i]);
            lowStockFound = 1;
        }
    }

    if (!lowStockFound) {
        printf("No books are low in stock.\n");
    }
}
