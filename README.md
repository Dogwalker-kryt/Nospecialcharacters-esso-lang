# Nospecialcharacters-esso-lang
- Basicly Python but with no special characters
- in the lexer.c file you can see al names of all symbols

**about**
- Every Special character
- , . ; : ( ) / [ ] = ! - _ * + # ' and so on
- is reaplaced with the name of the charakter in caps
- so
   "print("Hello world")"
- is going to:
   "print BRACKET QUOT Hello world QUOT BRACKET"
  
## Still in Progress!
- Compiler is finished it searches for main.nsc (nsc = no special character)
- in the main.nsc file you can find the "Hello, World!" program
  
## Compiler
- Should work now
-  if you dont want to compiler the compiler then skip to 'finished compiler'
- please, if you dowloaded the compiler code before the July 7, 2025, then please update it with the new version!
  
**how to use**
- if you want to complie the source code by hand then do this:
```bash
gcc -Wall -Wextra -g -c main.c -o main.o
gcc -Wall -Wextra -g -c lexer.c -o lexer.o
gcc -Wall -Wextra -g -c parser.c -o parser.o
gcc -Wall -Wextra -g -c codegen.c -o codegen.o
gcc -Wall -Wextra -g main.o lexer.o parser.o codegen.o -o compiler
```
- then you compile with this:
```bash
cc -O2 -Wall -Wextra main.o lexer.o parser.o codegen.o -o compiler
```
**finished compiler**
- then you can do this:
- write in the terminal
```bash
./compiler main.nsc
```
- but i it still doesnt complie to python, i dont know
- Still in development
