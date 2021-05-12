#include "Predicate.h"
#include <string>
#include <vector>

#ifndef RULE_H
#define RULE_H



class Rule {

private:
    Predicate headPredicate;
    std::vector<Predicate> bodyPredicates;
public:
    Rule();
    ~Rule();
    std::string RuleToString();
    void addBodyPredicates(Predicate body);
    void setHeadPredicate(Predicate head);

};


#endif RULE_H
