#include <stdio.h>
#include <string.h>
#include "stb_ds.h"
#include "simple_json.c"

int main() {
    char *JsonString = 
            "{"
            "\"model\": \"meta-llama/Meta-Llama-3-8B-Instruct\","
            "\"messages\": ["
            "    {"
            "        \"role\": \"user\","
            "        \"content\": \"Ку, брат, расскажи мне анекдот!!.\""
            "    }"
            "],"
            "\"max_tokens\": 500,"
            "\"stream\": false"
            "}";

    ast_node *AST = Parse(JsonString);

    if(AST == NULL)
    {
        printf("NE RABOTAET!\n");
        return 1;
    }

    FreeJsonASTRecursively(AST);

    return 0;
}
