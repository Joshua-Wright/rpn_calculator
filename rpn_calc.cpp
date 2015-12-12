#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include "stack.h"
#include "rpn_calc.h"

namespace rpn {

    using std::cout;
    using std::endl;
    using std::cerr;

    using std::pow;
    using std::sqrt;
    using std::log;
    using std::log2;
    using std::log10;
    using std::exp;
    using std::exp2;
    using std::sin;
    using std::cos;
    using std::tan;
    using std::asin;
    using std::acos;
    using std::atan;
    using std::atan2;
    using std::ceil;
    using std::floor;
    using std::fabs;


    token::token(const std::string &str) {
        if (str.front() >= '0' && str.front() <= '9') {
            type = NUMBER;
            number = std::stold(str);
        } else if (str == "pi" || str == "Pi" || str == "PI") {
            type = NUMBER;
            number = PI;
        } else if (str == "e") {
            type = NUMBER;
            number = e;
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
            } else if (str == "floor") {
                op = FLOOR;
            } else if (str == "ceil") {
                op = CEIL;
            } else {
                throw std::runtime_error("Invalid Token");
            }
        }
    }


    long double parse_rpn(const std::string &line) {
        containers::stack<token> stack;
        std::string word;
        std::stringstream stringstream(line);
        while (stringstream >> word) {
            token t(word);
            if (t.type == OPERATOR) {
                switch (t.op) {
                    case ADD: {
                        long double ex1(stack.pop().number);
                        long double ex2(stack.pop().number);
                        stack.push(token(ex1 + ex2));
                        break;
                    }
                    case SUBTRACT: {
                        long double ex1(stack.pop().number);
                        long double ex2(stack.pop().number);
                        stack.push(token(ex2 - ex1));
                        break;
                    }
                    case MULTIPLY: {
                        long double ex1(stack.pop().number);
                        long double ex2(stack.pop().number);
                        stack.push(token(ex1 * ex2));
                        break;
                    }
                    case DIVIDE: {
                        long double ex1(stack.pop().number);
                        long double ex2(stack.pop().number);
                        stack.push(token(ex2 / ex1));
                        break;
                    }
                    case SQUARE: {
                        long double ex1(stack.pop().number);
                        stack.push(token(pow(ex1, 2)));
                        break;
                    }
                    case SQRT: {
                        long double ex1(stack.pop().number);
                        stack.push(token(sqrt(ex1)));
                        break;
                    }
                    case POWER: {
                        long double exp = stack.pop().number;
                        long double base = stack.pop().number;
                        stack.push(token(pow(base, exp)));
                        break;
                    }
                    case ROOT: {
                        long double exp = stack.pop().number;
                        long double base = stack.pop().number;
                        stack.push(token(pow(base, 1 / exp)));
                        break;
                    }
                    case LOG_E: {
                        long double ex1(stack.pop().number);
                        stack.push(token(log(ex1)));
                        break;
                    }
                    case LOG_10: {
                        long double ex1(stack.pop().number);
                        stack.push(token(log10(ex1)));
                        break;
                    }
                    case LOG_2: {
                        long double ex1(stack.pop().number);
                        stack.push(token(log2(ex1)));
                        break;
                    }
                    case LOG_A: {
                        long double base(stack.pop().number);
                        long double ex1(stack.pop().number);
                        stack.push(token(log2(ex1) / log2(base)));
                        break;
                    }
                    case EXP_E: {
                        long double ex1(stack.pop().number);
                        stack.push(token(exp(ex1)));
                        break;
                    }
                    case EXP_10: {
                        long double ex1(stack.pop().number);
                        stack.push(token(pow(10, ex1)));
                        break;
                    }
                    case EXP_2: {
                        long double ex1(stack.pop().number);
                        stack.push(token(exp2(ex1)));
                        break;
                    }
                    case SIN_RAD: {
                        long double ex1(stack.pop().number);
                        stack.push(token(sin(ex1)));
                        break;
                    }
                    case COS_RAD: {
                        long double ex1(stack.pop().number);
                        stack.push(token(cos(ex1)));
                        break;
                    }
                    case TAN_RAD: {
                        long double ex1(stack.pop().number);
                        stack.push(token(tan(ex1)));
                        break;
                    }
                    case ASIN_RAD: {
                        long double ex1(stack.pop().number);
                        stack.push(token(asin(ex1)));
                        break;
                    }
                    case ACOS_RAD: {
                        long double ex1(stack.pop().number);
                        stack.push(token(acos(ex1)));
                        break;
                    }
                    case ATAN_RAD: {
                        long double ex1(stack.pop().number);
                        stack.push(token(atan(ex1)));
                        break;
                    }
                    case ATAN2_RAD: {
                        long double ex2(stack.pop().number);
                        long double ex1(stack.pop().number);
                        stack.push(token(atan2(ex1, ex2)));
                        break;
                    }
                    case FLOOR: {
                        long double ex1(stack.pop().number);
                        stack.push(token(floor(ex1)));
                        break;
                    }
                    case CEIL: {
                        long double ex1(stack.pop().number);
                        stack.push(token(ceil(ex1)));
                        break;
                    }
                    default:
                        cerr << endl;
                        cerr << word << endl;
                        cerr << t.type << endl;
                        cerr << t.number << endl;
                        cerr << t.op << endl;
                        throw std::runtime_error("Invalid Token");
                }
            } else {
                stack.push(t);
            }
        }
        return stack.pop().number;
    }
}
