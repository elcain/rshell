#ifndef PARSER_H
#define PARSER_H
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include "token.h"
using namespace std;

class Token;

class Parser{
public:
    Parser(){};

    void parse(string cmd);

    vector<Token*> cmdsToVector();
    vector<char> getChContainer();
    int numWords(string str);
    //HELPER FUNCTIONS
    void printContainer();
    void printConnectors();
private:
    vector<string> strContainer;
    string command;
    vector<char> connectorCont;

    const char** makePtArr(string str);
    vector<string> divideString(string str);
    void standardize();
    void reverseStr();
    void cleanString();
    void removeEmptySpots();
    
    bool checkForParenthesis(vector<char> myVector);
};
#endif // PARSER
