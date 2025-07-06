#ifndef LEXER_H
#define LEXER_H

typedef enum {
    TOKEN_IDENTIFIER,
    TOKEN_NUMBER,
    TOKEN_STRING,
    TOKEN_KEYWORD,
    TOKEN_SPECIAL,
    TOKEN_EOF
} TokenType;

typedef struct {
    TokenType type;
    char value[256];
} Token;

#define MAX_TOKENS 1024

extern Token tokens[MAX_TOKENS];
extern int token_count;

void tokenize_file(const char* filename);

#endif
