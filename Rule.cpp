
#include "Rule.h"

Rule::~Rule(){}

std::string Rule::RuleToString(){
    std::string rule = "rule";
    //should be headPredicate, :- , bodyPredicates
    rule = headPredicate.Predicate::PredicateToString() + " :- This is where the rules go";// + Predicate::PredicateVectorToString(bodyPredicates);
    return rule;
}

void Rule::setHeadPredicate(Predicate head){
    headPredicate = head;
}

void Rule::addBodyPredicates(Predicate body){
    bodyPredicates.push_back(body);
}
