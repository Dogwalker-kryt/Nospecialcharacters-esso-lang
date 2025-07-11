#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "lexer.h"

int is_special(const char* word) {
    return strcmp(word, "BRACKET") == 0 ||
           strcmp(word, "QUOT") == 0||
           strcmp(word, "COLON") == 0 ||
           strcmp(word, "EQUALS") == 0 ||
           strcmp(word, "EQUALSEQUALS") == 0 ||
           strcmp(word, "BANGEQUALS") == 0 ||
           strcmp(word, "PLUS") == 0 ||
           strcmp(word, "MINUS") == 0 ||
           strcmp(word, "STAR") == 0 ||
           strcmp(word, "SLASH") == 0 ||
           strcmp(word, "COMMA") == 0 ||
           strcmp(word, "SMALLERTHEN") == 0 ||
           strcmp(word, "BIGGERTHEN") == 0 ||
           strcmp(word, "LINE") == 0 ||
           strcmp(word, "HASHTAG") == 0 ||
           strcmp(word, "SQUAREBRACKET") == 0 ||
           strcmp(word, "EXCLEMATIONMARK") == 0 ||
           strcmp(word, "QUESTIONMARK") == 0 ||
           strcmp(word, "SEMICOLON") == 0;
}

const char* keywords[] = {
    "def", "return", "if", "else", "elif", "while", "for", "in", "break", "Class", "import", "from", "as", "try", "except", "raise", "with", "and", "or", "is", "none", "true", "false"
};

int is_keyword(const char* word) {
    for (int i = 0; i < sizeof(keywords)/sizeof(keywords[0]); i++) {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}


void classify_token(const char* word, Token* token) {
    strcpy(token->value, word);

    if (is_keyword(word)) {
        token->type = TOKEN_KEYWORD;
    } else if (is_special(word)) {
        token->type = TOKEN_SPECIAL;
    } else if (isdigit(word[0])) {
        token->type = TOKEN_NUMBER;
    } else if (strcmp(word, "QUOT") == 0) {
        token->type = TOKEN_STRING;
    } else {
        token->type = TOKEN_IDENTIFIER;
    }
}

void print_token(const Token* token) {
    const char* type_str =
        token->type == TOKEN_KEYWORD ? "KEYWORD" :
        token->type == TOKEN_SPECIAL ? "SPECIAL" :
        token->type == TOKEN_NUMBER ? "NUMBER" :
        token->type == TOKEN_STRING ? "STRING" : "IDENTIFIER";
    printf("[%s: %s]\n", type_str, token->value);
}

int notmain() {
    FILE* file = fopen("main.eeso", "r");
    if (!file) {
        perror("Failed to open file");
        return 1;
    }

    char word[256];
    while (fscanf(file, "%255s", word) == 1) {
        Token token;
        classify_token(word, &token);
        print_token(&token);
    }

    fclose(file);
    return 0;
}

Token tokens[256]; 

Token* tokenize_file(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return NULL;
    }

    char word[256];
    int i = 0;
    while (fscanf(file, "%255s", word) == 1 && i < 1024) {
        classify_token(word, &tokens[i++]);
    }

    fclose(file);
    return tokens;
}
