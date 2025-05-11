./compiler<rule3a.txt
./compiler<rule3b.txt
flex part1_EL.l
bison -d part1_EL.y
gcc -Wall part1_EL.tab.c -o compiler
./compiler<rule3b.txt
clear
bison -d part1_EL.y
gcc -Wall part1_EL.tab.c -o compiler
./compiler<rule3b.txt
bison -d part1_EL.y
gcc -Wall part1_EL.tab.c -o compiler
./compiler<rule3b.txt
./compiler<rule3a.txt
./compiler<rule3c.txt
bison -d part1_EL.y
gcc -Wall part1_EL.tab.c -o compiler
./compiler<rule3a.txt
./compiler<rule3b.txt
./compiler<rule3c.txt
clear
bison -d part1_EL.y
gcc -Wall part1_EL.tab.c -o compiler
./compiler<rule3a.txt
./compiler<rule3b.txt
./compiler<rule3c.txt
bison -d part1_EL.y
gcc -Wall part1_EL.tab.c -o compiler
./compiler<rule3a.txt
./compiler<rule3b.txt
./compiler<rule3c.txt
bison -d part1_EL.y
gcc -Wall part1_EL.tab.c -o compiler
./compiler<rule1.txt
./compiler<rule2.txt
./compiler<rule2.txt
bison -d part1_EL.y
bison -d part1_EL.y
gcc -Wall part1_EL.tab.c -o compiler
bison -d part1_EL.y
gcc -Wall part1_EL.tab.c -o compiler
./compiler<rule3a.txt
./compiler<rule3c.txt
./compiler<rule3b.txt
./compiler<rule3a.txt
bison -d part1_EL.y
gcc -Wall part1_EL.tab.c -o compiler
./compiler<rule3a.txt
./compiler<rule3b.txt
bison -d part1_EL.y
bison -d part1_EL.y
bison -d part1_EL.y
bison -d part1_EL.y
bison -d part1_EL.y
bison -d part1_EL.y
bison -d part1_EL.y
bison -d part1_EL.y
gcc -Wall part1_EL.tab.c -o compiler
./compiler<rule1.txt
bison -d part1_EL.y
bison -d part1_EL.y
gcc -Wall part1_EL.tab.c -o compiler
bison -d part1_EL.y
gcc -Wall part1_EL.tab.c -o compiler
./compiler<rule1.txt
./compiler<rule3b.txt
./compiler<rule3a.txt
./compiler<rule3a.txt
./compiler<rule3a.txt
clear
bison -d part1_EL.y
gcc -Wall part1_EL.tab.c -o compiler
bison -d part1_EL.y
bison -d part1_EL.y
gcc -Wall part1_EL.tab.c -o compiler
bison -d part1_EL.y
gcc -Wall part1_EL.tab.c -o compiler
clear
flex part1_EL.l
bison -d part1_EL.y
gcc -Wall part1_EL.tab.c -o compiler
./compiler<rule3a.txt
./compiler<rule3a.txt
./compiler<rule3b.txt
./compiler<rule3c.txt
bison -d part1_EL.y
bison -d part1_EL.y
bison -d part1_EL.y
gcc -Wall part1_EL.tab.c -o compiler
./compiler<rule3a.txt
./compiler<rule3c.txt
./compiler<rule3b.txt
./compiler<rule3b.txt
./compiler<rule1.txt
./compiler<rule2.txt
./compiler<rule3b.txt
./compiler<rule3c.txt
./compiler<rule3b.txt
bison -d part1_EL.y
gcc -Wall part1_EL.tab.c -o compiler
./compiler<rule4a.txt
./compiler<rule4a.txt
./compiler<rule4b.txt
./compiler<rule4b.txt
./compiler<rule4c.txt
./compiler<rule4b.txt
./compiler<rule2.txt
./compiler<rule3b.txt
./compiler<rule3c.txt
./compiler<rule3a.txt
bison -d part1_EL.y
gcc -Wall part1_EL.tab.c -o compiler
./compiler<rule3a.txt
./compiler<rule3b.txt
./compiler<rule5a.txt
./compiler<rule5b.txt
./compiler<rule6a.txt
./compiler<rule6a.txt
./compiler<rule6a.txt
./compiler<rule6b.txt
./compiler<rule6b.txt
./compiler<rule6b.txt
./compiler<rule3b.txt
./compiler<rule1.txt
bison -d part1_EL.y
gcc -Wall part1_EL.tab.c -o compiler
bison -d part1_EL.y
gcc -Wall part1_EL.tab.c -o compiler
./compiler<rule1.txt
./compiler<rule2.txt
./compiler<rule2.txt
./compiler<rule3a.txt
./compiler<rule3b.txt
./compiler<rule4a.txt
./compiler<rule4b.txt
./compiler<rule4c.txt
./compiler<rule5a.txt
./compiler<rule5b.txt
./compiler<rule6b.txt
./compiler<rule6a.txt
./compiler<rule7a.txt
./compiler<rule7a.txt
./compiler<rule7a.txt
./compiler<test1.txt
./compiler<rule7a.txt
./compiler<rule7a.txt
./compiler<rule7b.txt
./compiler<rule7b.txt
./compiler<rule7b.txt
./compiler<rule7b.txt
./compiler<rule7b.txt
./compiler<rule8a.txt
./compiler<rule8a.txt
./compiler<rule8b.txt
./compiler<rule8b.txt
bison -d part1_EL.y
gcc -Wall part1_EL.tab.c -o compiler
// Type checking (Rule 8)
temp = $4;
int index = 0;
while (temp && index < f->paramCount) {
    node* exprNode = (strcmp(temp->token, "exp_list") == 0) ? temp->left : temp;
    char* actualType = inferExprType(exprNode);
    char* expectedType = f->paramTypes[index];
    if (strcmp(actualType, expectedType) != 0) {
        char msg[256];
        sprintf(msg, "Semantic Error: Argument %d type mismatch in call to '%s': expected '%s' but got '%s'.",
                index + 1, f->name, expectedType, actualType);
        yyerror(msg);
        YYABORT;
    }
    temp = (strcmp(temp->token, "exp_list") == 0) ? temp->right : NULL;
    index++;
}
