#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// List of reserved keywords in C
char *keywords[] = {
    "auto", "break", "case", "char", "const", "continue", "default", "do",
    "double", "else", "enum", "extern", "float", "for", "goto", "if", "int",
    "long", "register", "return", "short", "signed", "sizeof", "static",
    "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"
};

// Check if word is a keyword
int isKeyword(char *word) {
    for (int i = 0; i < 32; i++) {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

// Check if character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' ||
            ch == '>' || ch == '<' || ch == '!' || ch == '&' || ch == '|' ||
            ch == '^' || ch == '~' || ch == '=');
}

// Check if word is a constant (all digits)
int isConstant(char *word) {
    for (int i = 0; word[i]; i++) {
        if (!isdigit(word[i]))
            return 0;
    }
    return 1;
}

int main() {
    FILE *fp = fopen("file.txt", "r"); // Input file
    if (fp == NULL) {
        printf("Cannot open file.\n");
        return 1;
    }

    char ch, buffer[100];
    int i = 0;

    printf("Lexical Analysis Output:\n\n");

    while ((ch = fgetc(fp)) != EOF) {
        if (isalnum(ch) || ch == '_') {
            buffer[i++] = ch;
        } else {
            if (i > 0) {
                buffer[i] = '\0';
                i = 0;

                if (isConstant(buffer)) {
                    // Ignore constants
                } else if (isKeyword(buffer)) {
                    printf("%s: Keyword\n", buffer);
                } else {
                    printf("%s: Identifier\n", buffer);
                }
            }

            if (isOperator(ch)) {
                printf("%c: Operator\n", ch);
            }

            // Ignore separators entirely
        }
    }

    // To process the last word if file doesn't end with a separator
    if (i > 0) {
        buffer[i] = '\0';
        if (!isConstant(buffer)) {
            if (isKeyword(buffer)) {
                printf("%s: Keyword\n", buffer);
            } else {
                printf("%s: Identifier\n", buffer);
            }
        }
    }

    fclose(fp);
    return 0;
}
