#ifndef AST_H
#define AST_H

typedef enum {
    AST_RETURN_STMT,
    AST_FUNCTION_DEF,
    AST_IDENTIFIER,
    AST_BINARY_OP
} ASTNodeType;

typedef struct ASTNode ASTNode;

struct ASTNode {
    ASTNodeType type;
    union {
        struct {
            char name[256];
        } identifier;

        struct {
            ASTNode* left;
            char op[8];
            ASTNode* right;
        } binary_op;

        struct {
            ASTNode* expr;
        } return_stmt;

        struct {
            char name[256];
            char arg1[256];
            char arg2[256];
            ASTNode* body;
        } function_def;
    };
};

#endif
