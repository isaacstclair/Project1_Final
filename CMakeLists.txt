cmake_minimum_required(VERSION 3.19)
project(Project1_Starter_Code)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Project1_Starter_Code
        Automaton.h
        ColonAutomaton.cpp
        ColonAutomaton.h
        ColonDashAutomaton.cpp
        ColonDashAutomaton.h
        Lexer.cpp
        Lexer.h
        main.cpp
        Token.cpp
        Token.h
        CommaAutomaton.cpp
        CommaAutomaton.h
        LeftParenAutomaton.cpp
        LeftParenAutomaton.h
        RightParenAutomaton.cpp
        RightParenAutomaton.h
        PeriodAutomaton.cpp
        PeriodAutomaton.h
        QMarkAutomaton.cpp
        QMarkAutomaton.h
        MultiplyAutomaton.cpp
        MultiplyAutomaton.h
        AddAutomaton.cpp
        AddAutomaton.h
        SchemesAutomaton.cpp
        SchemesAutomaton.h
        FactsAutomaton.cpp
        FactsAutomaton.h
        RulesAutomaton.cpp
        RulesAutomaton.h
        QueriesAutomaton.cpp
        QueriesAutomaton.h
        IDAutomaton.cpp
        IDAutomaton.h
        StringAutomaton.cpp
        StringAutomaton.h
        CommentAutomaton.cpp
        CommentAutomaton.h
        UndefinedAutomaton.cpp
        UndefinedAutomaton.h
        Rule.cpp
        Rule.h
        Parameter.cpp
        Parameter.h
        DatalogProgram.cpp
        DatalogProgram.h
        Predicate.cpp
        Predicate.h
        Parser.h
        Parser.cpp)