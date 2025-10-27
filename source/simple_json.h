#if !defined(_SIMPLE_JSON_H)

#define ArrayCount(Array) (sizeof(*Array) / sizeof((Array)[0]))

#define IsWhitespace(Ch) (Ch == ' ' || Ch == '\n' || Ch == '\r' || Ch == '\t')

typedef enum
{
    TOKENTYPE_BRACE_OPEN = 0,
    TOKENTYPE_BRACE_CLOSE,
    TOKENTYPE_BRACKET_OPEN,
    TOKENTYPE_BRACKET_CLOSE,
    TOKENTYPE_STRING,
    TOKENTYPE_NUMBER,
    TOKENTYPE_COMMA,
    TOKENTYPE_COLON,
    TOKENTYPE_BOOL,
    TOKENTYPE_NULL
} token_type;


// TODO: refactor the token struct. Instead of using linked list, i should use a default array and store it in lexer struct.
typedef struct token
{
    struct token *Next;
    char *Value;
    token_type Type;
} token;

// TODO: Rename it to lexer struct and refactor from linked list to array.
typedef struct 
{
    token *Head;
    token *Tail;
    int Count;
} token_list;

// NOTE: Maybe i should put it in struct.
typedef enum
{
    ASTNODE_OBJECT = 0,
    ASTNODE_ARRAY,
    ASTNODE_STRING,
    ASTNODE_NUMBER,
    ASTNODE_BOOL,
    ASTNODE_NULL
} ast_node_type;

typedef struct json_object
{
    // JSON Object. TODO: Now I use a stb lib. In future it must be my hash map.
    char *key;
    struct ast_node *value;

} json_object;

// TODO: Implement later.
typedef struct ast_node
{
    ast_node_type Type;

    // TODO: In c++ you can not write anonymous structures or unions with name.
    // So, for copabilites compatibility i write it more unreadeble ):
    union               // This union is value of ast_node.
    {
        json_object *JsonObj;
        struct ast_node **JsonArr;        // TODO: maybe later if should change it to my own dynamic array.
        char *JsonStr;
        int JsonNum;
        bool JsonBool;
        // I dont need field for null.
    };

} ast_node;

/*                  For tokens                     */
const char *GetTokenType(token_type Type);
void AppendToken(token_list *Tokens, token Token);
void FreeTokenList(token_list *Tokens);
void PrintTokens(token_list *Tokens);                  // For debug.

token_list Lexer(char *JsonString);

ast_node *CreateASTNode(ast_node NewASTNodeData);

token *GetNextToken(token **Token);
ast_node *ParseValue(token **Token);
ast_node *ParseJsonObject(token **Token);
ast_node *ParseJsonArray(token **Token);
ast_node *Parse(char *String);         // TODO: add returning value later.

void FreeASTNode(ast_node **ASTNodePtr);
void FreeJsonObject(ast_node **ASTNodePtr);
void FreeJsonArray(ast_node **ASTNodePtr);
void FreeJsonString(char **JsonStringPtr);
void FreeJsonASTRecursively(ast_node *AST);

/*           For Debugging           */
void PrintJsonAST(ast_node *ASTNode);
void PrintJsonObject(ast_node *ASTNode);
void PrintJsonArray(ast_node *ASTNode);
void PrintValue(ast_node *ASTNode);

/*           For strings             */
char *AppendChar(char *String, char Ch);

#endif
