/// ETML
/// Author : Kathleen Lu
/// Date : 02.03.2024
/// Description : A program which finds the answer for the Advent Of Code puzzle 1 part 1 based on a input text file

#include <stdio.h>

int main()
{
    // Opens the input file in read mode
    FILE* input = fopen("../../input.txt", "r");

    // If the file does not exist, prints and error and exits the programm
    if (input == NULL) {
        perror("Error opening file");
        return 1;
    }

    // The sum of the calibration values
    int calibration = 0;

    // For reading each line in the input file
    char line[80];

    // Reads each line of the input file
    while (fgets(line, sizeof(line), input)) {

        // First digit of the line
        int first_digit = -1;

        // Last digit of the line
        int last_digit = -1;

        // Finds the first digit
        for (int i = 0; line[i] != '\0'; i++) {
            if (line[i] >= '0' && line[i] <= '9') {
                first_digit = line[i] - '0';
                break;
            }
        }

        // Finds the last digit
        for (int i = strlen(line) - 1; i >= 0; i--) {
            if (line[i] >= '0' && line[i] <= '9') {
                last_digit = line[i] - '0';
                break;
            }
        }

        // If both first and last digits are found, calculate calibration value and adds it to the sum
        if (first_digit != -1 && last_digit != -1) {
            calibration += first_digit * 10 + last_digit;
        }
    }

    // Closes the input file
    fclose(input);

    // Prints the result
    printf("Sum of calibration values: %d\n", calibration);

    return 0;
}