
#include <iostream>
#include "Predicate.h"

Predicate::Predicate(){}

Predicate::Predicate(std::string name, std::vector<Parameter> parameters){
    this->name = name;
    this->parameters = parameters;
}


Predicate::~Predicate(){}

std::string Predicate::PredicateToString(){
    std::stringstream ss;
    if(parameters.size() != 0) {
        for (int i = 0; i < int(parameters.size()) - 1; i++) {
              ss << parameters.at(i).getParameter() << ",";
        }
        ss << parameters.at(parameters.size()-1).getParameter();
    }

    std::string predicate = name + "(" + ss.str() + ")";
    return predicate;
}
