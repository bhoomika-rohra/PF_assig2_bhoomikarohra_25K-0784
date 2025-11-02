#include <stdio.h>

void updateSectorStatus(int rows, int cols, int grid[100][100]);
void querySectorStatus(int rows, int cols, int grid[100][100]);
void runSystemDiagnostic(int rows, int cols, int grid[100][100]);

int main() {
    int rows, cols;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    int grid[100][100];
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

        switch(choice) {
            case 1:
                updateSectorStatus(rows, cols, grid);
                break;
            case 2:
                querySectorStatus(rows, cols, grid);
                break;
            case 3:
                runSystemDiagnostic(rows, cols, grid);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

void updateSectorStatus(int rows, int cols, int grid[100][100]) {
    int POWER = 0, OVERLOAD = 1, MAINTENANCE = 2;
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
        grid[r][c] |= (1 << flag);
    else
        grid[r][c] &= ~(1 << flag);

    printf("Status updated\n");
}

void querySectorStatus(int rows, int cols, int grid[100][100]) {
    int POWER = 0, OVERLOAD = 1, MAINTENANCE = 2;
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

void runSystemDiagnostic(int rows, int cols, int grid[100][100]) {
    int OVERLOAD = 1, MAINTENANCE = 2;
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
