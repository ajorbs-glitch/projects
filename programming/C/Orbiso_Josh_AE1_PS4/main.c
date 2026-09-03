#include <stdio.h>

#define MAX_TAGS 60

// Function Prototypes
int sanitizeAndRemoveDuplicates(int tags[], int p, int *removedCount);
int computeChecksum(int tags[], int size);              // pass-by-value
int searchTarget(int tags[], int size, int target);
int countEvenRecursive(int tags[], int size);           // recursion

int main() {
    int p, target;

    printf("\t--Museum Artifact Code Sanitization System--\n\n\n");

    do{
    printf("Enter number of scanned tags (1-60): ");
    scanf("%d", &p);

        if (p < 1)
            printf("Invalid number of tags. Please input positive number.\n");

        else if (p > MAX_TAGS)
            printf("Number of tags out of maximum tags. Please input 1 to 60.\n");

    } while (p < 1 || p > MAX_TAGS);

    int tags[MAX_TAGS];

    printf("Enter %d integer tags:\n", p);
    for (int i = 0; i < p; i++) {
        scanf("%d", &tags[i]);
    }

    printf("Enter target tag to search: ");
    scanf("%d", &target);

    int removedCount = 0;

    // Sanitize + Remove duplicates (in-place)
    int newSize = sanitizeAndRemoveDuplicates(tags, p, &removedCount);

    // Search target
    int position = searchTarget(tags, newSize, target);

    // Iterative checksum
    int checksum = computeChecksum(tags, newSize);

    // Recursive even counter
    int evenCount = countEvenRecursive(tags, newSize);

    // OUTPUTS
    printf("\n--- Artifact Integrity Report ---\n");

    printf("Sanitized Tags:\n");
    for (int i = 0; i < newSize; i++) {
        printf("%d ", tags[i]);
    }

    printf("\nRemoved duplicates: %d\n", removedCount);

    if (position != -1)
        printf("Target found at position: %d\n", position);
    else
        printf("Target not found.\n");

    printf("Checksum (iterative): %d\n", checksum);
    printf("Even tag frequency (recursive): %d\n", evenCount);

    return 0;
}

// Pass-by-reference: modifies array and removedCount
int sanitizeAndRemoveDuplicates(int tags[], int p, int *removedCount) {
    int newSize = 0;

    for (int i = 0; i < p; i++) {

        // Corrupted tag fix
        if (*(tags + i) < 0) {
            *(tags + i) = 0;
        }

        int isDuplicate = 0;

        // Check duplicate among already accepted values
        for (int j = 0; j < newSize; j++) {
            if (*(tags + j) == *(tags + i)) {
                isDuplicate = 1;
                break;
            }
        }

        if (!isDuplicate) {
            *(tags + newSize) = *(tags + i);
            newSize++;
        } else {
            (*removedCount)++;
        }
    }

    return newSize;
}

// Pass-by-value: does not modify original data
int computeChecksum(int tags[], int size) {
    int sum = 0;

    for (int i = 0; i < size; i++) {
        sum += tags[i];
    }

    return sum;
}

// Iterative search
int searchTarget(int tags[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (tags[i] == target) {
            return i;
        }
    }
    return -1;
}

// Recursive count of even numbers
int countEvenRecursive(int tags[], int size) {
    if (size == 0)
        return 0;

    int countRest = countEvenRecursive(tags, size - 1);

    if (tags[size - 1] % 2 == 0)
        return 1 + countRest;
    else
        return countRest;
}
