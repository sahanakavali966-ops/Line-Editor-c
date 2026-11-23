
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINES 100
#define MAX_LEN 256

char lines[MAX_LINES][MAX_LEN];
int count = 0;

// Display all lines
void display(void) {
    if (count == 0) {
        printf("Document is empty!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("%d: %s\n", i + 1, lines[i]);
    }
}

// Insert a line
int insert_line(int n, const char *text) {
    if (count >= MAX_LINES)
        return -1;

    if (n < 1 || n > count + 1)
        return -1;

    for (int i = count; i >= n; i--) {
        strcpy(lines[i], lines[i - 1]);
    }

    strncpy(lines[n - 1], text, MAX_LEN - 1);
    lines[n - 1][MAX_LEN - 1] = '\0';

    count++;
    return 0;
}

// Delete a line
int delete_line(int n) {
    if (n < 1 || n > count)
        return -1;

    for (int i = n - 1; i < count - 1; i++) {
        strcpy(lines[i], lines[i + 1]);
    }

    count--;
    return 0;
}

// Save document to file
void save_file(const char *filename) {
    FILE *fp = fopen(filename, "w");

    if (fp == NULL) {
        printf("Unable to save file!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s\n", lines[i]);
    }

    fclose(fp);
    printf("File saved successfully!\n");
}

// Load document from file
void load_file(const char *filename) {
    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("File does not exist!\n");
        return;
    }

    count = 0;

    while (count < MAX_LINES &&
           fgets(lines[count], MAX_LEN, fp) != NULL) {

        lines[count][strcspn(lines[count], "\n")] = '\0';
        count++;
    }

    fclose(fp);
    printf("File loaded successfully!\n");
}

// Main function
int main(void) {
    char input[512];
    char command;
    char text[MAX_LEN];
    char filename[256];
    int n;
    char *end;

    printf("===== SIMPLE LINE EDITOR =====\n");
    printf("Commands:\n");
    printf("i n text  - Insert line\n");
    printf("d n       - Delete line\n");
    printf("p         - Display document\n");
    printf("s file    - Save document\n");
    printf("l file    - Load document\n");
    printf("q         - Quit\n");

    while (1) {
        printf("\n> ");

        if (fgets(input, sizeof(input), stdin) == NULL)
            break;

        if (sscanf(input, " %c", &command) != 1)
            continue;

        switch (command) {

            case 'i':
                n = (int)strtol(input + 1, &end, 10);

                if (end == input + 1) {
                    printf("Usage: i n text\n");
                    break;
                }

                while (*end == ' ' || *end == '\t')
                    end++;

                if (*end == '\0' || *end == '\n') {
                    printf("Please enter some text!\n");
                    break;
                }

                end[strcspn(end, "\n")] = '\0';

                if (insert_line(n, end) == 0)
                    printf("Line inserted successfully!\n");
                else
                    printf("Invalid line number or document full!\n");

                break;

            case 'd':
                if (sscanf(input + 1, "%d", &n) != 1) {
                    printf("Usage: d n\n");
                    break;
                }

                if (delete_line(n) == 0)
                    printf("Line deleted successfully!\n");
                else
                    printf("Invalid line number!\n");

                break;

            case 'p':
                display();
                break;

            case 's':
                if (sscanf(input + 1, "%255s", filename) == 1)
                    save_file(filename);
                else
                    printf("Usage: s filename\n");

                break;

            case 'l':
                if (sscanf(input + 1, "%255s", filename) == 1)
                    load_file(filename);
                else
                    printf("Usage: l filename\n");

                break;

            case 'q':
                printf("Exiting Line Editor.\n");
                return 0;

            default:
                printf("Unknown command!\n");
        }
    }

    return 0;
}
