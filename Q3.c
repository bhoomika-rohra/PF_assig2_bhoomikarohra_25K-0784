#include <stdio.h>

void updateSectorStatus();
void querySectorStatus();
void runSystemDiagnostic();

int rows, cols;
int grid[100][100];
int POWER = 0;
int OVERLOAD = 1;
int MAINTENANCE = 2;

int main() {
    printf("Enter number of rows in the grid: ");
    scanf("%d", &rows);
    printf("Enter number of columns in the grid: ");
    scanf("%d", &cols);

    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            grid[i][j] = 0;

    int choice = 0;

    while(choice != 4) {
        printf("\n--- IESCO Power Grid Monitoring ---\n");
        printf("1. Update Sector Status\n");
        printf("2. Query Sector Status\n");
        printf("3. Run System Diagnostic\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 1) updateSectorStatus();
        else if(choice == 2) querySectorStatus();
        else if(choice == 3) runSystemDiagnostic();
        else if(choice == 4) printf("Exiting...\n");
        else printf("Invalid choice!\n");
    }

    return 0;
}

void updateSectorStatus() {
