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
bison -d part1_EL.y
gcc -Wall part1_EL.tab.c -o compiler
./compiler<rule8b.txt
./compiler<rule8a.txt
bison -d part1_EL.y
gcc -Wall part1_EL.tab.c -o compiler
./compiler<rule8a.txt
bison -d part1_EL.y
gcc -Wall part1_EL.tab.c -o compiler
./compiler<rule8a.txt
./compiler<rule8b.txt
bison -d part1_EL.y
gcc -Wall part1_EL.tab.c -o compiler
./compiler<rule8b.txt
./compiler<rule8a.txt
bison -d part1_EL.y
gcc -Wall part1_EL.tab.c -o compiler
./compiler<rule8a.txt
bison -d part1_EL.y
gcc -Wall part1_EL.tab.c -o compiler
./compiler<rule8a.txt
bison -d part1_EL.y
gcc -Wall part1_EL.tab.c -o compiler
./compiler<rule8a.txt
bison -d part1_EL.y
gcc -Wall part1_EL.tab.c -o compiler
bison -d part1_EL.y
bison -d part1_EL.y
bison -d part1_EL.y
bison -d part1_EL.y
gcc -Wall part1_EL.tab.c -o compiler
./compiler<rule8a.txt
bison -d part1_EL.y
gcc -Wall part1_EL.tab.c -o compiler
./compiler<rule8a.txt
bison -d part1_EL.y
gcc -Wall part1_EL.tab.c -o compiler
./compiler<rule8a.txt
bison -d part1_EL.y
gcc -Wall part1_EL.tab.c -o compiler
./compiler<rule8a.txt
flex part1_EL.l
bison -d part1_EL.y
gcc -Wall part1_EL.tab.c -o compiler
./compiler<rule8a.txt
flex part1_EL.l
bison -d part1_EL.y
gcc -Wall part1_EL.tab.c -o compiler
./compiler<rule8a.txt
flex part1_EL.l
bison -d part1_EL.y
gcc -Wall part1_EL.tab.c -o compiler
./compiler<rule8a.txt
./compiler<rule8נ.txt
./compiler<rule8b.txt
bison -d part1_EL.y
gcc -Wall part1_EL.tab.c -o compiler
./compiler<rule8b.txt
./compiler<rule8a.txt
bison -d part1_EL.y
gcc -Wall part1_EL.tab.c -o compiler
./compiler<rule8b.txt
./compiler<rule8a.txt
bison -d part1_EL.y
gcc -Wall part1_EL.tab.c -o compiler
./compiler<rule8a.txt
./compiler<rule8b.txt
bison -d part1_EL.y
gcc -Wall part1_EL.tab.c -o compiler
./compiler<rule8b.txt
bison -d part1_EL.y
gcc -Wall part1_EL.tab.c -o compiler
./compiler<rule8b.txt
./compiler<rule8a.txt
bison -d part1_EL.y
gcc -Wall part1_EL.tab.c -o compiler
./compiler<rule8a.txt
./compiler<rule8b.txt
bison -d part1_EL.y
gcc -Wall part1_EL.tab.c -o compiler
flex part1_EL.l
bison -d part1_EL.y
gcc -Wall part1_EL.tab.c -o compiler
./compiler<rule8b.txt
bison -d part1_EL.y
gcc -Wall part1_EL.tab.c -o compiler
./compiler<rule8b.txt
./compiler<rule8a.txt
./compiler<rule9a.txt
./compiler<rule9b.txt
./compiler<rule9c.txt
bison -d part1_EL.y
gcc -Wall part1_EL.tab.c -o compiler
./compiler<rule9c.txt
./compiler<rule9b.txt
./compiler<rule9a.txt
./compiler<rule10a.txt
./compiler<rule10b.txt
./compiler<rule10c.txt
./compiler<rule10c.txt
bison -d part1_EL.y
gcc -Wall part1_EL.tab.c -o compiler
./compiler<rule11a.txt
./compiler<rule11b.txt
./compiler<rule11c.txt
./compiler<rule11d.txt
./compiler<rule11e.txt
./compiler<rule11f.txt
./compiler<rule11f.txt
bison -d part1_EL.y
gcc -Wall part1_EL.tab.c -o compiler
./compiler<rule12a.txt
bison -d part1_EL.y
gcc -Wall part1_EL.tab.c -o compiler
./compiler<rule12a.txt
bison -d part1_EL.y
gcc -Wall part1_EL.tab.c -o compiler
./compiler<rule12a.txt
./compiler<rule12b.txt
./compiler<rule13a.txt
./compiler<rule13b.txt
git add .
git push
git checkout main
git commit -m "update part2 rules 1-13"
git push
git checkout main
git stash --include-untracked
git checkout main
git fetch
git pull
git merge part2
git push
./compiler<rule13a.txt
./compiler<rule13b.txt

git stash --include-untracked
git checkout comp2
./compiler<test1.txt
./compiler<first_run.txt
git checkout compiler
./compiler<first_run.txt
chmod +x compiler
./compiler<first_run.txt
./compiler<test1.txt
git checkout main
git stash --include-untracked
git checkout main
clear
./compiler<test1.txt
./compiler<first_run.txt
./compiler<rule7a.txt
./compiler<rule7a.txt
bison -d part1_EL.y
gcc -Wall part1_EL.tab.c -o compiler
./compiler<rule7a.txt
./compiler<rule6a.txt
./compiler<rule6a.txt
./compiler<rule6b.txt
