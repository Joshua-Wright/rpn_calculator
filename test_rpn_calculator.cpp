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

    {
        assert(parse_rpn("4 3 +") == 4+3);
        assert(parse_rpn("4 3 + 5 2 - / 8 *") == 56.0L/3.0L);
        assert(parse_rpn("5 ^2") == 25);
        assert(parse_rpn("9 sqrt") == 3);
        assert(parse_rpn("125 3 root") == 5);
        assert(parse_rpn("125 3 rt") == 5);
        assert(parse_rpn("3 3 pow") == 27);
        assert(parse_rpn("3 4 ^") == 81);
        assert(parse_rpn("4 30 ^") == 1152921504606846976);
        assert(parse_rpn("10000 10 loga") == 4);
        assert(parse_rpn("10000 log") == 4);
        assert(parse_rpn("4294967296 lg") == 32);
        assert(parse_rpn("4294967296 lg") == 32);
        assert(parse_rpn("pi") == Pi);
        assert(parse_rpn("Pi") == Pi);
        assert(parse_rpn("PI") == Pi);
        assert(parse_rpn("PI sin") == sin(Pi));
        assert(parse_rpn("PI cos") == cos(Pi));
        assert(parse_rpn("PI tan") == tan(Pi));
        assert(fabs(parse_rpn("0.3450 asin") - asin(0.3450)) < long_double_threshold);
        assert(fabs(parse_rpn("0.7345 acos") - acos(0.7345)) < long_double_threshold);
        assert(fabs(parse_rpn("0.1234 atan") - atan(0.1234)) < long_double_threshold);
    }

    return 0;
}
