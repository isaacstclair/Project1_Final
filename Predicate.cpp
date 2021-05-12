
#include "Predicate.h"


Predicate::Predicate(std::string name, std::vector<Parameter> parameter){
    this->name = name;
    this->parameters = parameters;
}


Predicate::~Predicate(){}

std::string Predicate::PredicateToString(){

    std::stringstream ss;
    for(int i=0; i < parameters.size()-1; i++) {
        ss << parameters.at(i).getParameter() << ", ";
    }
    ss << parameters.at(parameters.size()).getParameter();

    std::string predicate = name + "(" + ss.str() + ")";
    return predicate;
}
