#include "IDAutomaton.h"

void IDAutomaton::S0(const std::string& input) {
    if (isalpha(input[index])) {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void IDAutomaton::S1(const std::string& input) {
    if (isalnum(input[index])) {
        inputRead++;
        index++;
        S1(input);
    } else if (!isalnum(input[index])){
        if(input[index]=='\n'){newLines++;}
    }
    else {
        Serr();
    }
}