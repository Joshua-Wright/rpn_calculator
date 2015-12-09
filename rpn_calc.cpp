//
// Created by j0sh on 12/8/15.
//

#include "rpn_calc.h"

namespace rpn {

    token::token(std::string str) {
        if (str.front() >= '0' && str.front() <= '9') {
            type = NUMBER;
            number = GiNaC::numeric(str.c_str());
        } else if (str == "pi" || str == "Pi" || str == "PI") {
            type = NUMBER;
            number = GiNaC::Pi;
        } else if (str == "e") {
            type = NUMBER;
            number = exp(numeric(1));
        } else {
            type = OPERATOR;
            if (str == "+") {
                op = ADD;
            } else if (str == "-") {
                op = SUBTRACT;
            } else if (str == "*") {
                op = MULTIPLY;
            } else if (str == "/") {
                op = DIVIDE;
            } else if (str == "^2") {
                op = SQUARE;
            } else if (str == "sqrt") {
                op = SQRT;
            } else if (str == "^" || str == "pow") {
                op = POWER;
            } else if (str == "rt" || str == "root") {
                op = ROOT;
            } else if (str == "ln") {
                op = LOG_E;
            } else if (str == "log") {
                op = LOG_10;
            } else if (str == "lg") {
                op = LOG_2;
            } else if (str == "loga") {
                op = LOG_A;
            } else if (str == "exp") {
                op = EXP_E;
            } else if (str == "exp10") {
                op = EXP_10;
            } else if (str == "exp2") {
                op = EXP_2;
            } else if (str == "sin") {
                op = SIN_RAD;
            } else if (str == "cos") {
                op = COS_RAD;
            } else if (str == "tan") {
                op = TAN_RAD;
            } else if (str == "asin") {
                op = ASIN_RAD;
            } else if (str == "acos") {
                op = ACOS_RAD;
            } else if (str == "atan") {
                op = ATAN_RAD;
            } else if (str == "@") {
                op = EVAL;
            } else if (str == "@n") {
                op = EVAL_N_DIGITS;
            }
        }
    }

    token::token(GiNaC::numeric numeric) {
        type = NUMBER;
        number = numeric;
    }

    token::token(ex ex1) {
        type = NUMBER;
        number = ex1;

    }

    ex rpn_calc::parse(std::string line) {
        std::string word;
        std::stringstream stringstream(line);
        while (stringstream >> word) {
            token t(word);
            if (t.type == OPERATOR) {
                switch (t.op) {
                    case ADD: {
                        ex ex1(stack.back().number);
                        stack.pop_back();
                        ex ex2(stack.back().number);
                        stack.pop_back();
                        stack.push_back(token(ex1 + ex2));
                        break;
                    }
                    case SUBTRACT: {
                        ex ex1(stack.back().number);
                        stack.pop_back();
                        ex ex2(stack.back().number);
                        stack.pop_back();
                        stack.push_back(token(ex2 - ex1));
                        break;
                    }
                    case MULTIPLY: {
                        ex ex1(stack.back().number);
                        stack.pop_back();
                        ex ex2(stack.back().number);
                        stack.pop_back();
                        stack.push_back(token(ex1 * ex2));
                        break;
                    }
                    case DIVIDE: {
                        ex ex1(stack.back().number);
                        stack.pop_back();
                        ex ex2(stack.back().number);
                        stack.pop_back();
                        stack.push_back(token(ex2 / ex1));
                        break;
                    }
                    case SQUARE: {
                        ex ex1(stack.back().number);
                        stack.pop_back();
                        stack.push_back(token(pow(ex1, 2)));
                        break;
                    }
                    case SQRT: {
                        ex ex1(stack.back().number);
                        stack.pop_back();
                        stack.push_back(token(sqrt(ex1)));
                        break;
                    }
                    case POWER: {
                        ex exp = stack.back().number;
                        stack.pop_back();
                        ex base = stack.back().number;
                        stack.pop_back();
                        stack.push_back(token(pow(base, exp)));
                        break;
                    }
                    case ROOT: {
                        ex exp = stack.back().number;
                        stack.pop_back();
                        ex base = stack.back().number;
                        stack.pop_back();
                        stack.push_back(token(pow(base, 1 / exp)));
                        break;
                    }
                    case LOG_E: {
                        ex ex1(stack.back().number);
                        stack.pop_back();
                        stack.push_back(token(log(ex1)));
                        break;
                    }
                    case LOG_10: {
                        /*FIXME: make these more efficient*/
                        ex ex1(stack.back().number);
                        stack.pop_back();
                        stack.push_back(token(log(ex1) / log(10)));
                        break;
                    }
                    case LOG_2: {
                        ex ex1(stack.back().number);
                        stack.pop_back();
                        stack.push_back(token(log(ex1) / log(2)));
                        break;
                    }
                    case LOG_A: {
                        ex base(stack.back().number);
                        stack.pop_back();
                        ex ex1(stack.back().number);
                        stack.pop_back();
                        stack.push_back(token(log(ex1) / log(base)));
                        break;
                    }
                    case EXP_E: {
                        ex ex1(stack.back().number);
                        stack.pop_back();
                        stack.push_back(token(exp(ex1)));
                        break;
                    }
                    case EXP_10: {
                        ex ex1(stack.back().number);
                        stack.pop_back();
                        stack.push_back(token(pow(10,ex1)));
                        break;
                    }
                    case EXP_2: {
                        ex ex1(stack.back().number);
                        stack.pop_back();
                        stack.push_back(token(pow(2,ex1)));
                        break;
                    }
                    case SIN_RAD: {
                        ex ex1(stack.back().number);
                        stack.pop_back();
                        stack.push_back(token(sin(ex1)));
                        break;
                    }
                    case COS_RAD: {
                        ex ex1(stack.back().number);
                        stack.pop_back();
                        stack.push_back(token(cos(ex1)));
                        break;
                    }
                    case TAN_RAD: {
                        ex ex1(stack.back().number);
                        stack.pop_back();
                        stack.push_back(token(tan(ex1)));
                        break;
                    }
                    case ASIN_RAD: {
                        ex ex1(stack.back().number);
                        stack.pop_back();
                        stack.push_back(token(asin(ex1)));
                        break;
                    }
                    case ACOS_RAD: {
                        ex ex1(stack.back().number);
                        stack.pop_back();
                        stack.push_back(token(acos(ex1)));
                        break;
                    }
                    case ATAN_RAD: {
                        ex ex1(stack.back().number);
                        stack.pop_back();
                        stack.push_back(token(atan(ex1)));
                        break;
                    }
                    case EVAL: {
                        ex ex1(stack.back().number);
                        stack.pop_back();
                        stack.emplace_back(ex1.evalf());
                        break;
                    }
                    case EVAL_N_DIGITS: {
                        /*FIXME*/
//                        ex ex1(stack.back().number);
//                        stack.pop_back();
//                        ex digits (stack.back().number);
//                        stack.pop_back();
//                        Digits = (int) digits.evalf().integer_content();
//                        stack.emplace_back(ex1.evalf());
                        break;
                    }
                    default:
                        throw std::runtime_error("what");
                }
            } else {
                stack.push_back(t);
            }
        }
        return stack.back().number;
    }
}