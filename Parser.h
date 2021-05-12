#pragma once

#include "Token.h"
#include "DatalogProgram.h"
#include <vector>
#include "Predicate.h"

class Parser
{
private:
    int counter = 0;
    int Advance();
    std::vector<Token*> tokens;
    std::vector<Parameter> schemeParameters;
    std::vector<Parameter> factParameters;
    std::vector<Parameter> queryParamters;

public:
    Parser(std::vector<Token*> tokens);
    ~Parser();
    void ParseDatalogProgram();
    bool Match(TokenType toMatch);

    //Terminals
    void ParseTerminal(TokenType type);

    //Non-Terminals
    void schemeList();
    void factList();
    void ruleList();
    void queryList();
    void scheme();
    void fact();
    void rule();
    void query();
    void headPredicate();
    void predicate();
    void predicateList();
    void parameterList();
    void stringList();
    void idList();
    void parameter();


};

