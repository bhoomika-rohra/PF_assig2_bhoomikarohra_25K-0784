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
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            grid[i][j] = 0;

    int choice = 0;

    while (choice != 4) {
        printf("\n--- IESCO Power Grid Monitoring ---\n");
        printf("1. Update Sector Status\n");
        printf("2. Query Sector Status\n");
        printf("3. Run System Diagnostic\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
            updateSectorStatus();
        else if (choice == 2)
            querySectorStatus();
        else if (choice == 3)
            runSystemDiagnostic();
        else if (choice == 4)
            printf("Exiting...\n");
        else
            printf("Invalid choice!\n");
    }

    return 0;
}

void updateSectorStatus() {
    int r, c, flag, action;
    printf("Enter row and column: ");
    scanf("%d %d", &r, &c);

    if (r < 0 || r >= rows || c < 0 || c >= cols) {
        printf("Invalid coordinates!\n");
        return;
    }

    printf("Select flag to modify:\n");
    printf("0. Power (ON/OFF)\n");
    printf("1. Overload Warning\n");
    printf("2. Maintenance Required\n");
    printf("Enter flag: ");
    scanf("%d", &flag);

    printf("Enter 1 to SET or 0 to CLEAR flag: ");
    scanf("%d", &action);

    if (action == 1)
        grid[r][c] = grid[r][c] | (1 << flag);
    else
        grid[r][c] = grid[r][c] & ~(1 << flag); 

    printf("Status updated\n");
}

void querySectorStatus() {
    int r, c;
    printf("Enter sector row and column: ");
    scanf("%d %d", &r, &c);

    if (r < 0 || r >= rows || c < 0 || c >= cols) {
        printf("Invalid coordinates!\n");
        return;
    }

    int status = grid[r][c];
    printf("\n--- Sector (%d,%d) Status ---\n", r, c);

    if (status & (1 << POWER))
        printf("Power: ON\n");
    else
        printf("Power: OFF\n");

    if (status & (1 << OVERLOAD))
        printf("Overload Warning: YES\n");
    else
        printf("Overload Warning: NO\n");

    if (status & (1 << MAINTENANCE))
        printf("Maintenance Required: YES\n");
    else
        printf("Maintenance Required: NO\n");
}

void runSystemDiagnostic() {
    int overloadCount = 0, maintenanceCount = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] & (1 << OVERLOAD))
                overloadCount++;
            if (grid[i][j] & (1 << MAINTENANCE))
                maintenanceCount++;
        }
    }

    printf("\n--- System Diagnostic Report ---\n");
    printf("Total Overloaded Sectors: %d\n", overloadCount);
    printf("Total Sectors Requiring Maintenance: %d\n", maintenanceCount);
}
