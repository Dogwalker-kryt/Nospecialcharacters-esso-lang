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

#define MAX_TOKENS 256

extern Token tokens[MAX_TOKENS];
extern int token_count;

Token* tokenize_file(const char* filename);

#endif

extern Token tokens[];
