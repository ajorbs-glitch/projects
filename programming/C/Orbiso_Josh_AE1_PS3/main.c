#include <stdio.h>

#define MAX_VEHICLES 50

// Function Prototypes //
void applyCorrection(int *w, int limit);
int countOverloaded(int weights[], int t, int limit, int *firstIndex);
int computeTotal(int weights[], int t);          // pass-by-value
int findMaxRecursive(int arr[], int size);      // recursion

int main() {
    int t, limit;

    printf("\t--Bridge Toll Weight Monitoring System--\n\n");

    do{
    printf("Enter number of vehicles (1-50): ");
    scanf("%d", &t);

    if (t < 1 || t > MAX_VEHICLES) {
        printf("Invalid number of vehicles. Program terminated.\n");
        return 1;
        }
    } while (t < 1 || t > MAX_VEHICLES);

    do{
    printf("Enter overload limit (positive): ");
    scanf("%d", &limit);

    if (limit <= 0) {
        printf("Invalid limit. Program terminated.\n");
        return 1;
        }
    } while (limit <= 0);

    int weights[MAX_VEHICLES];

    printf("Enter %d vehicle weights (kg):\n", t);
    for (int i = 0; i < t; i++) {
        scanf("%d", &weights[i]);
    }

    // Count overloads BEFORE correction
    int firstIndex = -1;
    int overloadedCount = countOverloaded(weights, t, limit, &firstIndex);

    // Apply safety correction using pointer arithmetic
    for (int i = 0; i < t; i++) {
        applyCorrection(weights + i, limit);   // pointer arithmetic
    }

    // Compute total corrected weight
    int total = computeTotal(weights, t);

    // Recursive maximum corrected weight
    int maxWeight = findMaxRecursive(weights, t);

    // OUTPUTS
    printf("\n--- Toll Audit Report ---\n");
    printf("Overloaded vehicles: %d\n", overloadedCount);
    printf("First overload index: %d\n", firstIndex);

    printf("Adjusted Weights:\n");
    for (int i = 0; i < t; i++) {
        printf("%d ", weights[i]);
    }

    printf("\nTotal corrected weight: %d kg\n", total);
    printf("Maximum corrected weight: %d kg\n", maxWeight);

    return 0;
}

// Applies safety correction (pass-by-reference)
void applyCorrection(int *w, int limit) {
    if (*w > limit) {
        *w = limit;
    }
}

// Counts overloaded vehicles and records first index
int countOverloaded(int weights[], int t, int limit, int *firstIndex) {
    int count = 0;

    for (int i = 0; i < t; i++) {
        if (weights[i] > limit) {
            count++;
            if (*firstIndex == -1) {
                *firstIndex = i;
            }
        }
    }

    return count;
}

// Computes total weight (pass-by-value demonstration)
int computeTotal(int weights[], int t) {
    int sum = 0;

    for (int i = 0; i < t; i++) {
        sum += weights[i];
    }

    return sum;
}

// Recursive function to find maximum element
int findMaxRecursive(int arr[], int size) {
    if (size == 1) {
        return arr[0];
    }

    int maxRest = findMaxRecursive(arr, size - 1);

    return (arr[size - 1] > maxRest) ? arr[size - 1] : maxRest;
}
