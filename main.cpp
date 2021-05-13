#include "Lexer.h"
#include "Parser.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>


int main(int argc, char** argv) {

    if (argc != 2){
        std::cout << "usage: " << argv[0] << " input_file" << std::endl;
        return 1;
    }

    std::string fileName = argv[1];
    std::ifstream input(fileName);
    std::string txt;

    if (!input.is_open()){
        std::cout << "File " << fileName << " could not be found or opened." << std::endl;
        return 1;
    }

    if(input){
        std::ostringstream ss;
        ss << input.rdbuf();
        txt = ss.str();
    }


    Lexer* lexer = new Lexer();
    lexer->Run(txt);



    try {
        Parser myParser(lexer->getTokens());
        std::cout << "Success!" << std::endl;
        std::cout << myParser.ToString();
    } catch(std::string e){
        std::cout << "Failure!" << std::endl;
    }

    delete lexer;

    return 0;
}