#ifndef TOKEN_H
#define TOKEN_H
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <vector>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include "baseshell.h"

//Token Class that will encapsulate the individual commands 
class Token : public BaseShell
{
public:
    //default
    Token();
    bool successFlag; 
    //constructor will take the character pointer array for us in execvp
    Token(const char** argv);
    
    //will execute the individual program
    void execute();
    void executeTree(std::vector<Token*>); 
    //will test function
    void test(const char**);
    void cd(const char**); 
    const char** command; 
    //use these two member variables the parser is in parenthesis
    std::vector<Token*> tokens; 
    std::vector<char> Tkconnectors; 
    
};

#endif // TOKEN_H
