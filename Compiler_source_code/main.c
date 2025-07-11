#include <stdio.h>
#include "lexer.h"
#include "ast.h"

typedef struct ASTNode ASTNode;
void generate_code(ASTNode* ast);

ASTNode* parse_program(); //{
    //return parse_function();
//}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <main.nsc>\n", argv[0]);
        return 1;
    }
    const char* filename = argv[1];
    tokenize_file(filename);
    ASTNode* ast = parse_program();
    if (!ast) {
        fprintf(stderr, "Parsing failed.\n");
        return 1;
    }
    printf("Parsing complete.\n");
    generate_code(ast);
    return 0;
}

