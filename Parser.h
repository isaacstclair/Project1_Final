#pragma once

#include "Token.h"
#include <vector>

class Parser
{
private:
    int counter = 0;
    int Advance();

public:
    void ParseDatalogProgram(std::vector<Token*> tokens);
    bool Match(TokenType current, TokenType toMatch);

    //Terminals
    void ParseTerminal(std::vector<Token*> tokens, TokenType type);

    //Non-Terminals
    void schemeList(std::vector<Token*> tokens);
    void factList(std::vector<Token*> tokens);
    void ruleList(std::vector<Token*> tokens);
    void queryList(std::vector<Token*> tokens);
    void scheme(std::vector<Token*> tokens);
    void fact(std::vector<Token*> tokens);
    void rule(std::vector<Token*> tokens);
    void query(std::vector<Token*> tokens);
    void headPredicate(std::vector<Token*> tokens);
    void predicate(std::vector<Token*> tokens);
    void predicateList(std::vector<Token*> tokens);
    void parameterList(std::vector<Token*> tokens);
    void stringList(std::vector<Token*> tokens);
    void idList(std::vector<Token*> tokens);
    void parameter(std::vector<Token*> tokens);


};

