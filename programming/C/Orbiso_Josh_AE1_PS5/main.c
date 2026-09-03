#include <stdio.h>

#define MAX_RUNNERS 20

// Struct Definition
typedef struct {
    int bib;
    int splitTime;
    int flag;
    int finalTime;
} Runner;

// Function Prototypes
void applyFlagAdjustment(Runner *r);                     // pass-by-reference
int simulateWhatIf(Runner r);                            // pass-by-value
void sortFinalTimes(Runner runners[], int size);
int countBelowAverageRecursive(Runner runners[], int size, float avg);

int main() {

    int r;

    printf("\t--Mountain Relay Performance Analyzer--\n\n\n");


    do{
    printf("Enter number of runners (2-20): ");
    scanf("%d", &r);

    if (r < 2) {
        printf("Invalid number of runners. Please input more than 1.\n");
        }
    else if (r > MAX_RUNNERS) {
        printf("Number out of range. Please input no more than 60.\n");
        }
    } while (r < 2 || r > MAX_RUNNERS);

    Runner runners[MAX_RUNNERS];

    // Input
    for (int i = 0; i < r; i++) {
        printf("\nRunner %d\n", i + 1);
        printf("Bib: ");
        scanf("%d", &runners[i].bib);

        printf("Split Time (seconds): ");
        scanf("%d", &runners[i].splitTime);

        printf("Flag (-1 penalty, 0 none, 1 bonus): ");
        scanf("%d", &runners[i].flag);

        runners[i].finalTime = runners[i].splitTime;

        // Apply actual adjustment (pass-by-reference)
        applyFlagAdjustment(&runners[i]);
    }

    // Compute total and fastest
    int total = 0;
    int fastestIndex = 0;

    for (int i = 0; i < r; i++) {
        total += runners[i].finalTime;

        if (runners[i].finalTime < runners[fastestIndex].finalTime) {
            fastestIndex = i;
        }
    }

    float average = (float) total / r;

    // Recursive below-average count
    int belowAvgCount = countBelowAverageRecursive(runners, r, average);

    // Sort runners by final time
    sortFinalTimes(runners, r);

    // OUTPUTS
    printf("\n--- Mountain Relay Results ---\n");

    printf("\nFinal Times per Runner:\n");
    for (int i = 0; i < r; i++) {
        printf("Bib %d : %d sec\n", runners[i].bib, runners[i].finalTime);
    }

    printf("\nTeam Total Time: %d sec\n", total);
    printf("Team Average Time: %.2f sec\n", average);

    printf("\nFastest Runner: Bib %d with %d sec\n",
           runners[fastestIndex].bib,
           runners[fastestIndex].finalTime);

    printf("\nSorted Final Times (Ascending):\n");
    for (int i = 0; i < r; i++) {
        printf("%d ", runners[i].finalTime);
    }

    printf("\n\nRunners below team average (recursive): %d\n",
           belowAvgCount);

    return 0;
}

// Pass-by-reference: modifies original struct
void applyFlagAdjustment(Runner *r) {

    if (r->flag == -1) {
        r->finalTime += 15;
    }
    else if (r->flag == 1) {
        r->finalTime -= 10;

        if (r->finalTime < 1) {
            r->finalTime = 1;
        }
    }
}

// Pass-by-value: simulation only (does NOT modify original)
int simulateWhatIf(Runner r) {

    if (r.flag == -1)
        r.splitTime += 15;
    else if (r.flag == 1)
        r.splitTime -= 10;

    if (r.splitTime < 1)
        r.splitTime = 1;

    return r.splitTime;
}

// Manual bubble sort (ascending by finalTime)
void sortFinalTimes(Runner runners[], int size) {

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {

            if (runners[j].finalTime > runners[j + 1].finalTime) {

                Runner temp = runners[j];
                runners[j] = runners[j + 1];
                runners[j + 1] = temp;
            }
        }
    }
}

// Recursive count of runners below average
int countBelowAverageRecursive(Runner runners[], int size, float avg) {

    if (size == 0)
        return 0;

    int countRest =
        countBelowAverageRecursive(runners, size - 1, avg);

    if (runners[size - 1].finalTime < avg)
        return 1 + countRest;
    else
        return countRest;
}
