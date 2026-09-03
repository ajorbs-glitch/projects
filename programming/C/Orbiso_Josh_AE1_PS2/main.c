#include <stdio.h>

#define MAX 30

// STRUCT DEFINITION
typedef struct {
    int id;
    int age;
    int priorityFlag; // 1 = priority, 0 = regular
} Patient;

//  FUNCTION PROTOTYPES
void groupByPriority(Patient arr[], int m);
void swapPatients(Patient *a, Patient *b); // pass-by-reference
void printQueue(Patient arr[], int m);
void servePatients(Patient arr[], int m, int serveCount);
char getAgeCategory(Patient p); // pass-by-value
void printReverse(int servedIDs[], int index); // recursion

//  MAIN FUNCTION
int main() {
    Patient patients[MAX];
    int m, serveCount;

    printf("\t--Herbal Clinic Queue Management System--\n\n\n");

    // Validate number of patients
    do {
        printf("Enter number of patients (1-30): ");
        scanf("%d", &m);

        if (m < 1 || m > 30)
            printf("Out of limit. Please input 1 to 30.\n");
    } while (m < 1 || m > 30);

    // Input patient data
    for (int i = 0; i < m; i++) {
        printf("\nPatient %d\n", i + 1);

        printf("ID: ");
        scanf("%d", &patients[i].id);

        do {
            printf("Age (1-120): ");
            scanf("%d", &patients[i].age);

            if (patients[i].age < 1 || patients[i].age > 120)
                printf("Invalid age. Please input 1 to 120.\n");

        } while (patients[i].age < 1 || patients[i].age > 120);

        do {
            printf("Priority (1 = Yes, 0 = No): ");
            scanf("%d", &patients[i].priorityFlag);

            if (patients[i].priorityFlag != 0 && patients[i].priorityFlag != 1)
                printf("Invalid number. Please input 1 for Yes or 0 for No\n");

        } while (patients[i].priorityFlag != 0 && patients[i].priorityFlag != 1);
    }

    // Validate serveCount
    do {
        printf("\nHow many patients can be served today? ");
        scanf("%d", &serveCount);

        if (serveCount < 0)
            printf("Invalid number of services. Please input 0 or a positive number.\n");
        else if(serveCount > m)
            printf("Out of range. Please input less than or equal the available patients to serve. \n");
    } while (serveCount < 0 || serveCount > m);

    // Apply priority rule
    groupByPriority(patients, m);

    printf("\n===== FINAL QUEUE ORDER =====\n");
    printQueue(patients, m);

    // Serve patients
    servePatients(patients, m, serveCount);

    return 0;
}

// PRIORITY GROUPING
// Stable grouping using bubble-like approach
void groupByPriority(Patient arr[], int m) {
    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < m - i - 1; j++) {
            if (arr[j].priorityFlag < arr[j + 1].priorityFlag) {
                swapPatients(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// SWAP FUNCTION
// Pass-by-reference using pointer-to-struct
void swapPatients(Patient *a, Patient *b) {
    Patient temp = *a;
    *a = *b;
    *b = temp;
}

// PRINT QUEUE
void printQueue(Patient arr[], int m) {
    for (int i = 0; i < m; i++) {
        printf("ID: %d | Age: %d | Priority: %d\n",
               arr[i].id,
               arr[i].age,
               arr[i].priorityFlag);
    }
}

// SERVE PATIENTS
void servePatients(Patient arr[], int m, int serveCount) {
    int servedIDs[MAX];
    int totalAge = 0;

    printf("\n===== SERVED TODAY =====\n");

    for (int i = 0; i < serveCount; i++) {
        servedIDs[i] = arr[i].id;
        totalAge += arr[i].age;

        // Pass-by-value function call
        char category = getAgeCategory(arr[i]);

        printf("ID: %d ", arr[i].id);

        if (category == 'C')
            printf("(Child)\n");
        else if (category == 'A')
            printf("(Adult)\n");
        else
            printf("(Senior)\n");
    }

    if (serveCount > 0)
        printf("\nAverage Age: %.2f\n",
               (float)totalAge / serveCount);
    else
        printf("\nNo patients served.\n");

    printf("Unserved Patients: %d\n", m - serveCount);

    // Recursive reverse print
    printf("\nServed IDs in Reverse Order:\n");
    printReverse(servedIDs, serveCount - 1);
    printf("\n");
}

// PASS-BY-VALUE FUNCTION
// Receives struct by value (copy)
char getAgeCategory(Patient p) {
    if (p.age < 18)
        return 'C'; // Child
    else if (p.age < 60)
        return 'A'; // Adult
    else
        return 'S'; // Senior
}

//  RECURSIVE FUNCTION
void printReverse(int servedIDs[], int index) {
    if (index < 0)
        return;

    printf("%d ", servedIDs[index]);
    printReverse(servedIDs, index - 1);
}
