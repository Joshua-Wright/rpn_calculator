#ifndef RPN_CALCULATOR_RPN_H
#define RPN_CALCULATOR_RPN_H

#include <iostream>
#include <unordered_map>
#include <limits>
#include <cmath>


namespace rpn {

    /*constants to 100 digits, because overkill is nice*/
    constexpr const long double e = 2.718281828459045235360287471352662497757247093699959574966967627724076630353547594571382178525166427L;
    constexpr const long double PI = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117068L;
    constexpr const long double Pi = PI;
    constexpr const long double pi = PI;
    /*handy threshold for comparing doubles for equality*/
    constexpr const long double long_double_threshold = (const long double) std::sqrt(std::numeric_limits<long double>::epsilon());

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
        ATAN2_RAD,
        FLOOR,
        CEIL,
        MODULO
    };

    struct token {

        /*TODO: make this more compact (maybe using a union?)*/
        token_type type;
        operator_type op;
        long double number;

        token(const std::string &str, const std::unordered_map<std::string, long double> &variables);
        token() {};

        token(const long double &num) : type(NUMBER), number(num) { };

    };


    long double parse_rpn(const std::string &line, const std::unordered_map<std::string, long double> &variables);

};

#endif //RPN_CALCULATOR_RPN_H
