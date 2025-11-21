# Introduction to Compilation

This project implements a small compiler for a custom language, built as part of an Introduction to Compilation course.  
It uses Flex and Bison to perform lexical, syntax, and basic semantic analysis, including symbol tables, scopes, functions, and type checking.

## Tech Stack

- **Language:** C
- **Tools:** Flex, Bison, GCC
- **Platform:** Linux / WSL

## How to Build & Run

```bash
flex part1_EL.l
bison -d part1_EL.y
gcc -Wall part1_EL.tab.c -o compiler -lfl
./compiler < test1.txt
