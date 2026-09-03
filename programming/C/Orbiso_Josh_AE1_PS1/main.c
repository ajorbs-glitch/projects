#include <stdio.h>

#define MAX 40

// Function Prototypes
void cleanSignals(int arr[], int n);
void printSignals(int arr[], int n);
int countPattern(int arr[], int n, int k);
int longestNonDecreasingStreak(int arr[], int n);
int recursiveSumMagnitude(int arr[], int n);
int getMagnitude(int value);
void clearInputBuffer();


int main() {
    int n, k;
    int signals[MAX];

    printf("\n\t--Lighthouse Log Analyzer--\n\n\n");
    do {
    printf("Enter number of log entries (1-40): ");
    scanf("%d", &n);


    if (n < 1 || n > 40) {
        printf("Invalid number of entries.\n");

        }
    } while (n < 1 || n > 40);

    printf("Enter %d signal values:\n", n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &signals[i]);
    }

    // Clear extra input after the required n numbers to avoid interfering the next prompt
    clearInputBuffer();

    printf("Enter pattern value k: ");
    scanf("%d", &k);
    clearInputBuffer();

    // Clean signals (Pass-by-Reference)
    cleanSignals(signals, n);

    printf("\nCleaned Signals:\n");
    printSignals(signals, n);

    int total = recursiveSumMagnitude(signals, n);
    int patternCount = countPattern(signals, n, k);
    int longestStreak = longestNonDecreasingStreak(signals, n);

    printf("\nTotal Signal Strength (Sum of Magnitudes): %d\n", total);
    printf("Occurrences of %d: %d\n", k, patternCount);
    printf("Longest Non-Decreasing Streak: %d\n", longestStreak);

    return 0;
}


// Clear leftover input
void clearInputBuffer() {
    while (getchar() != '\n');
}


// Cleaning (Pass-by-Reference)
void cleanSignals(int arr[], int n) {
    int *ptr = arr;

    for (int i = 0; i < n; i++) {
        if (*(ptr + i) < -100)
            *(ptr + i) = -100;
        else if (*(ptr + i) > 100)
            *(ptr + i) = 100;
    }
}


// Print signals
void printSignals(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


// Count signal pattern
int countPattern(int arr[], int n, int k) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == k)
            count++;
    }

    return count;
}


// Longest Non-Decreasing Streak
int longestNonDecreasingStreak(int arr[], int n) {
    int maxStreak = 1;
    int currentStreak = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] >= arr[i - 1])
            currentStreak++;
        else {
            if (currentStreak > maxStreak)
                maxStreak = currentStreak;
            currentStreak = 1;
        }
    }

    if (currentStreak > maxStreak)
        maxStreak = currentStreak;

    return maxStreak;
}


// Recursive Sum of Magnitudes
int recursiveSumMagnitude(int arr[], int n) {
    if (n == 0)
        return 0;

    return getMagnitude(arr[n - 1]) +
           recursiveSumMagnitude(arr, n - 1);
}


// Pass-by-Value Function
int getMagnitude(int value) {
    if (value < 0)
        value = -value;

    return value;
}
