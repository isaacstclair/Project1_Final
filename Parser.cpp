
#include "Parser.h"

bool Parser::Match(TokenType current, TokenType toMatch){
    if(current == toMatch){
        return true;
    } else{return false;}
}

void Parser::ParseDatalogProgram(std::vector<Token*> tokens) {
    ParseTerminal(tokens, TokenType::SCHEMES);
    ParseTerminal(tokens, TokenType::COLON);
    scheme(tokens);
    schemeList(tokens);
    ParseTerminal(tokens, TokenType::FACTS);
    ParseTerminal(tokens, TokenType::COLON);
    factList(tokens);
    ParseTerminal(tokens, TokenType::RULES);
    ParseTerminal(tokens, TokenType::COLON);
    ruleList(tokens);
    ParseTerminal(tokens, TokenType::QUERIES);
    ParseTerminal(tokens, TokenType::COLON);
    query(tokens);
    queryList(tokens);
    ParseTerminal(tokens, TokenType::EOF_TYPE);

}


//TERMINALS
void Parser::ParseTerminal(std::vector<Token*> tokens, TokenType type){
    if(Match(tokens.at(counter)->GetTokenType(), type)){
        Advance();
    } else{
        throw(type);
    }
}




//NONTERMINALS
void Parser::schemeList(std::vector<Token*> tokens){
    if(tokens.at(counter)->GetTokenType() == TokenType::ID) {
        scheme(tokens);
        schemeList(tokens);
    }
}
void Parser::factList(std::vector<Token*> tokens){
    if(tokens.at(counter)->GetTokenType() == TokenType::ID) {
        fact(tokens);
        factList(tokens);
    }
}
void Parser::ruleList(std::vector<Token*> tokens){
    if(tokens.at(counter)->GetTokenType() == TokenType::ID) {
        rule(tokens);
        ruleList(tokens);
    }
}
void Parser::queryList(std::vector<Token*> tokens){
    if(tokens.at(counter)->GetTokenType() == TokenType::ID) {
        query(tokens);
        queryList(tokens);
    }
}
void Parser::scheme(std::vector<Token*> tokens){
    ParseTerminal(tokens, TokenType::ID);
    ParseTerminal(tokens, TokenType::LEFTPAREN);
    ParseTerminal(tokens, TokenType::ID);
    idList(tokens);
    ParseTerminal(tokens, TokenType::RIGHTPAREN);
}
void Parser::fact(std::vector<Token*> tokens){
    ParseTerminal(tokens, TokenType::ID);
    ParseTerminal(tokens, TokenType::LEFTPAREN);
    ParseTerminal(tokens, TokenType::STRING);
    stringList(tokens);
    ParseTerminal(tokens, TokenType::RIGHTPAREN);
    ParseTerminal(tokens, TokenType::PERIOD);
}
void Parser::rule(std::vector<Token*> tokens){
    headPredicate(tokens);
    ParseTerminal(tokens, TokenType::COLON_DASH);
    predicate(tokens);
    predicateList(tokens);
    ParseTerminal(tokens, TokenType::PERIOD);
}
void Parser::query(std::vector<Token*> tokens){
    predicate(tokens);
    ParseTerminal(tokens, TokenType::QMARK);
}
void Parser::headPredicate(std::vector<Token*> tokens){
    ParseTerminal(tokens, TokenType::ID);
    ParseTerminal(tokens, TokenType::LEFTPAREN);
    ParseTerminal(tokens, TokenType::ID);
    idList(tokens);
    ParseTerminal(tokens, TokenType::RIGHTPAREN);
}
void Parser::predicate(std::vector<Token*> tokens){
    ParseTerminal(tokens, TokenType::ID);
    ParseTerminal(tokens, TokenType::LEFTPAREN);
    parameter(tokens);
    parameterList(tokens);
    ParseTerminal(tokens, TokenType::RIGHTPAREN);
}
void Parser::predicateList(std::vector<Token*> tokens){
    if(tokens.at(counter)->GetTokenType() == TokenType::COMMA) {
        ParseTerminal(tokens, TokenType::COMMA);
        predicate(tokens);
        predicateList(tokens);
    }
}
void Parser::parameterList(std::vector<Token*> tokens){
    if(tokens.at(counter)->GetTokenType() == TokenType::COMMA) {
        ParseTerminal(tokens, TokenType::COMMA);
        parameter(tokens);
        parameterList(tokens);
    }
}
void Parser::stringList(std::vector<Token*> tokens){
    if(tokens.at(counter)->GetTokenType() == TokenType::COMMA) {
        ParseTerminal(tokens, TokenType::COMMA);
        ParseTerminal(tokens, TokenType::STRING);
        stringList(tokens);
    }
}
void Parser::idList(std::vector<Token*> tokens){
    if(tokens.at(counter)->GetTokenType() == TokenType::COMMA) {
        ParseTerminal(tokens, TokenType::COMMA);
        ParseTerminal(tokens, TokenType::ID);
        idList(tokens);
    }
}
void Parser::parameter(std::vector<Token*> tokens){
    if(Match(tokens.at(counter)->GetTokenType(),TokenType::STRING)){
        ParseTerminal(tokens, TokenType::STRING);
    } else if (Match(tokens.at(counter)->GetTokenType(),TokenType::ID)){
        ParseTerminal(tokens, TokenType::ID);
    }

}





int Parser::Advance(){
    counter = counter+1;
    return(counter);
}