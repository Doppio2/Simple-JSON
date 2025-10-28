JSON Parser & Serializer (C)

A lightweight and simple JSON parser and serializer written in pure C.  
It parses JSON strings into an abstract syntax tree (AST), provides convenient access to elements, and handles memory cleanup automatically.

### Example usage:
```c
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
            "        \"content\": \"Hello! Tell me a story!.\""
            "    }"
            "],"
            "\"max_tokens\": 500,"
            "\"stream\": false"
            "}";

    ast_node *AST = Parse(JsonString);

    ast_node *ModelName = shget(AST->JsonObj, "model\n");

    printf("%s", ModelName->JsonStr);

    FreeJsonASTRecursively(AST);

    return 0;
}
