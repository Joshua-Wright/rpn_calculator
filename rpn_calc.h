#ifndef RPN_CALCULATOR_RPN_H
#define RPN_CALCULATOR_RPN_H

#include <string>
#include <stack>
#include <forward_list>
#include <vector>
#include <ginac/ginac.h>
#include <sstream>
#include <iostream>


namespace rpn {
    using std::cout;
    using std::endl;
    using namespace GiNaC;

    enum token_type {
        OPERATOR,
        NUMBER
    };

    enum operator_type {
        ADD,
        SUBTRACT,
        MULTIPLY,
        DIVIDE,
        SQUARE,
        SQRT,
        POWER,
        ROOT,
        LOG_E,
        LOG_10,
        LOG_2,
        LOG_A,
        EXP_E,
        EXP_10,
        EXP_2,
        SIN_RAD,
        COS_RAD,
        TAN_RAD,
        ASIN_RAD,
        ACOS_RAD,
        ATAN_RAD,
        EVAL,
        EVAL_N_DIGITS
    };

    struct token {

        token_type type;
        operator_type op;
        GiNaC::ex number;

        token(const std::string &str);

        token(const GiNaC::numeric &);

        token(const GiNaC::ex &);

    };


    class rpn_calc {
        std::vector<token> stack;

    public:

        rpn_calc() : stack() { };

        ex parse(const std::string &line);

    };
};

#endif //RPN_CALCULATOR_RPN_H
