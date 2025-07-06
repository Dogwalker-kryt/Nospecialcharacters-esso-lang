typedef enum {
    AST_FUNCTION_DEF,
    AST_RETURN_STMT,
    AST_IDENTIFIER,
    AST_NUMBER,
    AST_BINARY_OP
} ASTNodeType;

typedef struct ASTNode {
    ASTNodeType type;
    union {
        struct {
            char name[64];
            char arg1[64];
            char arg2[64];
            struct ASTNode* body;
        } function_def;

        struct {
            struct ASTNode* expr;
        } return_stmt;

        struct {
            struct ASTNode* left;
            char op[8];
            struct ASTNode* right;
        } binary_op;

        struct {
            char name[64];
        } identifier;

        struct {
            int value;
        } number;
    };
} ASTNode;
