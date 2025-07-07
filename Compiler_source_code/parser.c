#include "ast.h"
#include "lexer.h" 
#include <string.h>
#include <stdlib.h>

Token* token;
int current = 0;

Token* peek() {
    return &tokens[current];
}

Token* advance() {
    return &tokens[current++];
}

int match(const char* value) {
    if (strcmp(peek()->value, value) == 0) {
        advance();
        return 1;
    }
    return 0;
}

ASTNode* parse_identifier() {
    Token* t = advance();
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = AST_IDENTIFIER;
    strcpy(node->identifier.name, t->value);
    return node;
}

ASTNode* parse_expression() {
    ASTNode* left = parse_identifier();
    char* op = advance()->value;
    ASTNode* right = parse_identifier();

    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = AST_BINARY_OP;
    node->binary_op.left = left;
    strcpy(node->binary_op.op, op);
    node->binary_op.right = right;
    return node;
}

ASTNode* parse_return() {
    match("return");
    ASTNode* expr = parse_expression();
    match("SEMICOLON");

    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = AST_RETURN_STMT;
    node->return_stmt.expr = expr;
    return node;
}

ASTNode* parse_function() {
    match("def");
    Token* name = advance(); 
    match("LPAREN");
    Token* arg1 = advance();
    match("COMMA");
    Token* arg2 = advance();
    match("RPAREN");
    match("COLON");

    ASTNode* return_stmt = parse_return();

    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = AST_FUNCTION_DEF;
    strcpy(node->function_def.name, name->value);
    strcpy(node->function_def.arg1, arg1->value);
    strcpy(node->function_def.arg2, arg2->value);
    node->function_def.body = return_stmt;
    return node;
}


ASTNode* parse_program() {
    static ASTNode dummy;
    return &dummy;
}
