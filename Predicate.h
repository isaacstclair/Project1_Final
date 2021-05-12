
#include <vector>
#include <string>
#include "Parameter.h"
#include <sstream>

#ifndef PREDICATE_H
#define PREDICATE_H


class Predicate {
private:
    std::string name;
    std::vector<Parameter> parameters;

public:
    Predicate(std::string name, std::vector<Parameter> parameters);
    ~Predicate();
    std::string PredicateToString();
};


#endif PREDICATE_H
