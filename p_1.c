#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    int n = strlen(input);

    if (n > 0 && input[n - 1] == '\n') {
        input[n - 1] = '\0';
        n--; 
    }

    if (n < 2) {
        printf("Invalid String\n");
        return 0;
    }

    if (input[n - 1] == 'b' && input[n - 2] == 'b') {
        int valid = 1;

        for (int i = 0; i < n - 2; i++) {
            if (input[i] != 'a') {
                valid = 0;
                break;
            }
        }

        if (valid) {
            printf("Valid String\n");
        } else {
            printf("Invalid String\n");
        }
    } else {
        printf("Invalid String\n");
    }

    return 0;
}
