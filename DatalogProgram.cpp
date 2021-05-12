#include "DatalogProgram.h"

void DatalogProgram::addScheme(Predicate scheme){SchemesPredicates.push_back(scheme);}

void DatalogProgram::addFact(Predicate fact){FactsPredicates.push_back(fact);}

void DatalogProgram::addQuery(Predicate query){QueriesPredicates.push_back(query);}

void DatalogProgram::addRule(Rule rule){Rules.push_back(rule);}

void DatalogProgram::addDomain(std::string domain){Domain.insert(domain);}

std::string DatalogProgram::DatalogProgramToString(){

    std::stringstream ss;

    for(int i=0; i<SchemesPredicates.size(); i++){
        ss << SchemesPredicates.at(i).PredicateToString();
    }

    std::string schemes = "Schemes(" + std::to_string(SchemesPredicates.size()) + "):\n  " + ss.str();

    ss.clear();

    for(int i=0; i<FactsPredicates.size(); i++){
        ss << FactsPredicates.at(i).PredicateToString();
    }

    std::string facts = "Facts(" + std::to_string(FactsPredicates.size()) + "):\n  " + ss.str();

    ss.clear();

    for(int i=0; i<Rules.size(); i++){
        ss << Rules.at(i).RuleToString();
    }

    std::string rules = "Rules(" + std::to_string(Rules.size()) + "):\n  " + ss.str();

    ss.clear();

    for(int i=0; i<QueriesPredicates.size(); i++){
        ss << QueriesPredicates.at(i).PredicateToString();
    }

    std::string queries = "Queries(" + std::to_string(QueriesPredicates.size()) + "):\n  " + ss.str();

    ss.clear();

    for(auto it = Domain.begin(); it != Domain.end(); ++it){
        ss << *it << std::endl;
    }

    std::string domain = "Domain(" + std::to_string(Domain.size()) = "):\n  " + ss.str();



    std::string datalogString = schemes + facts + rules + queries + domain;

   return datalogString;
}