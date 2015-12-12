// (c) Copyright 2015 Josh Wright
#include <cassert>
#include <cmath>
#include <limits>
#include "rpn_calc.h"

int main(int argc, char const *argv[]) {
    using std::cout;
    using std::endl;
    using namespace rpn;
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

    std::unordered_map<std::string, long double> variables;
    variables["asdf"] = 4.5L;
    variables["a"] = 10L;
    variables["b"] = -50L;

    {
        assert(parse_rpn("4 3 +", variables) == 4+3);
        assert(parse_rpn("4 3 + 5 2 - / 8 *", variables) == 56.0L/3.0L);
        assert(parse_rpn("5 ^2", variables) == 25);
        assert(parse_rpn("9 sqrt", variables) == 3);
        assert(parse_rpn("125 3 root", variables) == 5);
        assert(parse_rpn("125 3 rt", variables) == 5);
        assert(parse_rpn("3 3 pow", variables) == 27);
        assert(parse_rpn("3 4 ^", variables) == 81);
        assert(parse_rpn("4 30 ^", variables) == 1152921504606846976);
        assert(parse_rpn("10000 10 loga", variables) == 4);
        assert(parse_rpn("10000 log", variables) == 4);
        assert(parse_rpn("4294967296 lg", variables) == 32);
        assert(parse_rpn("4294967296 lg", variables) == 32);
        assert(parse_rpn("pi", variables) == Pi);
        assert(parse_rpn("Pi", variables) == Pi);
        assert(parse_rpn("PI", variables) == Pi);
        assert(parse_rpn("PI sin", variables) == sin(Pi));
        assert(parse_rpn("PI cos", variables) == cos(Pi));
        assert(parse_rpn("PI tan", variables) == tan(Pi));
        assert(fabs(parse_rpn("0.3450 asin", variables) - asin(0.3450)) < long_double_threshold);
        assert(fabs(parse_rpn("0.7345 acos", variables) - acos(0.7345)) < long_double_threshold);
        assert(fabs(parse_rpn("0.1234 atan", variables) - atan(0.1234)) < long_double_threshold);
        assert(parse_rpn("asdf 5 +", variables) == 4.5 + 5);
        assert(parse_rpn("a b 5 + +", variables) == 10 - 50 + 5);
    }

    return 0;
}
