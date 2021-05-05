#include <stdio.h>
#include <stdlib.h>

#define PRN_COUNT 80
const int RECORD_COUNT = 5;

const char *FILENAME = "students";

const char *STUDENT_FORMAT_IN = " %[^,], %lli";   // Input is expected of the form (Name, PRN)
const char *STUDENT_FORMAT_OUT = "Name: %s, PRN: %lli\n";

// Array to store the position of records in the file
int INDEX[PRN_COUNT];

typedef struct {
    char name[20];
    long long int prn;
} Student;

const int SIZE_OF_STUDENT = sizeof (Student);
int FILE_POINTER = 0;

// Search for entry in file
void search();

// Function to initialize INDEX
void initIndex() {
	int i;
    for (i = 0; i < PRN_COUNT; ++i) {
        INDEX[i] = -1;
    }
}


// PROGRAM DRIVER
int main(void) {
	
	int j,k;
    // Initialize indices to -1
    initIndex();

    // Open file in write mode
    FILE *out;
    out = fopen(FILENAME, "w");

    // Check whether the file was opened successfully or not
    if (out == NULL) {
        exit(EXIT_FAILURE);
    }

    // Read records from STDIN and write to the FILE
    for (j = 0; j < RECORD_COUNT; ++j) {

        Student st;

        // Get record
        printf("Enter record: ");
        scanf(STUDENT_FORMAT_IN, &st.name, &st.prn);

        // Set key to be the last two digits of the PRN
        int key = st.prn % 100;

        // Add record if the key is empty
        if (INDEX[key] == -1) {

            INDEX[key] = FILE_POINTER;
            fwrite(&st, SIZE_OF_STUDENT, 1, out);
            FILE_POINTER += SIZE_OF_STUDENT;
        }
        else {
            printf("The key already exists!\n");
        }
    }

    // Close the file
    fclose(out);

    // Display index table
    printf("\nINDEX table\n");
    for (k = 0; k < PRN_COUNT; ++k) {
        printf("%d: %d\n", k, INDEX[k]);
    }

    // Test search functionality
    printf("\nTesting search record functionality.\n");
    search();
    search();
    search();

    return 0;
}

// ----------------------
//  FUNCTION DEFINITIONS
// ----------------------

void search() {

    long long int prn;

    // Ask for PRN of record to be searched
    printf("Enter PRN: ");
    scanf("%lli", &prn);

    // Calculate key
    int key = prn % 100;

    // Get the position of the record in the file
    int position = INDEX[key];

    // Check whether the record exists or not
    if (position == -1) {
        printf("The record does not exist!\n");
    }
    else {

        FILE *in = fopen(FILENAME, "r");
        if (in == NULL) {
            exit(EXIT_FAILURE);
        }

        Student st;

        fseek(in, position, SEEK_SET);
        fread(&st, SIZE_OF_STUDENT, 1, in);
        fclose(in);

        printf(STUDENT_FORMAT_OUT, st.name, st.prn);
    }
}

// END OF PROGRAM
