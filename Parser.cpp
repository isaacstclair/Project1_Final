
#include "Parser.h"


Parser::Parser(std::vector<Token*> tokens){
    this->tokens = tokens;
    ParseDatalogProgram();
}

Parser::~Parser(){
    //clean up memory
}


bool Parser::Match(TokenType toMatch){
    if(tokens.at(counter)->GetTokenType() == toMatch){
        return true;
    } else{return false;}
}

void Parser::ParseDatalogProgram() {
    ParseTerminal(TokenType::SCHEMES);
    ParseTerminal(TokenType::COLON);
    scheme();
    schemeList();
    ParseTerminal(TokenType::FACTS);
    ParseTerminal(TokenType::COLON);
    factList();
    ParseTerminal(TokenType::RULES);
    ParseTerminal(TokenType::COLON);
    ruleList();
    ParseTerminal(TokenType::QUERIES);
    ParseTerminal(TokenType::COLON);
    query();
    queryList();
    ParseTerminal(TokenType::EOF_TYPE);

}


//TERMINALS
void Parser::ParseTerminal(TokenType type){
    if(Match(type)){
        Advance();
    } else{
        std::string error = tokens.at(counter)->GetStringError();
        throw(error);
    }
}




//NONTERMINALS
void Parser::schemeList(){
    if(tokens.at(counter)->GetTokenType() == TokenType::ID) {
        scheme();
        schemeList();
    }
}
void Parser::factList(){
    if(tokens.at(counter)->GetTokenType() == TokenType::ID) {
        fact();
        factList();
    }
}
void Parser::ruleList(){
    if(tokens.at(counter)->GetTokenType() == TokenType::ID) {
        rule();
        ruleList();
    }
}
void Parser::queryList(){
    if(tokens.at(counter)->GetTokenType() == TokenType::ID) {
        query();
        queryList();
    }
}
void Parser::scheme(){
    ParseTerminal(TokenType::ID);
    ParseTerminal(TokenType::LEFTPAREN);
    ParseTerminal(TokenType::ID);
    idList();
    ParseTerminal(TokenType::RIGHTPAREN);
}
void Parser::fact(){
    ParseTerminal(TokenType::ID);
    ParseTerminal(TokenType::LEFTPAREN);
    ParseTerminal(TokenType::STRING);
    stringList();
    ParseTerminal(TokenType::RIGHTPAREN);
    ParseTerminal(TokenType::PERIOD);
}
void Parser::rule(){
    headPredicate();
    ParseTerminal(TokenType::COLON_DASH);
    predicate();
    predicateList();
    ParseTerminal(TokenType::PERIOD);
}
void Parser::query(){
    predicate();
    ParseTerminal(TokenType::QMARK);
}
void Parser::headPredicate(){
    ParseTerminal(TokenType::ID);
    ParseTerminal(TokenType::LEFTPAREN);
    ParseTerminal(TokenType::ID);
    idList();
    ParseTerminal(TokenType::RIGHTPAREN);
}
void Parser::predicate(){
    ParseTerminal(TokenType::ID);
    ParseTerminal(TokenType::LEFTPAREN);
    parameter();
    parameterList();
    ParseTerminal(TokenType::RIGHTPAREN);
}
void Parser::predicateList(){
    if(tokens.at(counter)->GetTokenType() == TokenType::COMMA) {
        ParseTerminal(TokenType::COMMA);
        predicate();
        predicateList();
    }
}
void Parser::parameterList(){
    if(tokens.at(counter)->GetTokenType() == TokenType::COMMA) {
        ParseTerminal(TokenType::COMMA);
        parameter();
        parameterList();
    }
}
void Parser::stringList(){
    if(tokens.at(counter)->GetTokenType() == TokenType::COMMA) {
        ParseTerminal(TokenType::COMMA);
        ParseTerminal(TokenType::STRING);
        stringList();
    }
}
void Parser::idList(){
    if(tokens.at(counter)->GetTokenType() == TokenType::COMMA) {
        ParseTerminal(TokenType::COMMA);
        ParseTerminal(TokenType::ID);
        idList();
    }
}
void Parser::parameter(){
    if(Match(TokenType::STRING)){
        ParseTerminal(TokenType::STRING);
    } else if (Match(TokenType::ID)){
        ParseTerminal(TokenType::ID);
    }

}





int Parser::Advance(){
    counter = counter+1;
    return(counter);
}