#include "ast.h"
#include <stdio.h>

void generate_code(ASTNode* node);

void generate_expression(ASTNode* node) {
    if (!node) return;

    switch (node->type) {
        case AST_IDENTIFIER:
            printf("%s", node->identifier.name);
            break;

        case AST_BINARY_OP:
            printf("(");
            generate_expression(node->binary_op.left);
            printf(" %s ", node->binary_op.op);
            generate_expression(node->binary_op.right);
            printf(")");
            break;

        default:
            printf("<expr>");
            break;
    }
}

void generate_code(ASTNode* node) {
    if (!node) return;

    switch (node->type) {
        case AST_FUNCTION_DEF:
            printf("void %s(%s, %s) {\n", 
                   node->function_def.name, 
                   node->function_def.arg1, 
                   node->function_def.arg2);
            generate_code(node->function_def.body);
            printf("}\n");
            break;

        case AST_RETURN_STMT:
            printf("    return ");
            generate_expression(node->return_stmt.expr);
            printf(";\n");
            break;

        default:
            printf("// unknown AST node\n");
            break;
    }
}
