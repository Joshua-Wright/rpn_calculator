// (c) Copyright 2015 Josh Wright
#include <cassert>
#include "rpn_calc.h"

int main(int argc, char const *argv[]) {
    using std::cout;
    using std::endl;
    using namespace rpn;
    {
        assert(rpn_calc().parse("4 3 +") == 4+3);
        assert(rpn_calc().parse("4 3 + 5 2 - / 8 *") == numeric("56/3"));
        assert(rpn_calc().parse("5 ^2") == 25);
        assert(rpn_calc().parse("9 sqrt") == 3);
        assert(rpn_calc().parse("125 3 root") == 5);
        assert(rpn_calc().parse("125 3 rt") == 5);
        assert(rpn_calc().parse("3 3 pow") == 27);
        assert(rpn_calc().parse("3 4 ^") == 81);
        assert(rpn_calc().parse("4 30 ^") == numeric("1152921504606846976"));
        assert(rpn_calc().parse("10000 10 loga @") == numeric("4"));
        assert(rpn_calc().parse("10000 log @") == numeric("4"));
        assert(rpn_calc().parse("4294967296 lg @") == numeric("32"));
        assert(rpn_calc().parse("4294967296 lg @") == numeric("32"));
        assert(rpn_calc().parse("pi") == Pi);
        assert(rpn_calc().parse("Pi") == Pi);
        assert(rpn_calc().parse("PI") == Pi);
        assert(rpn_calc().parse("PI sin") == sin(Pi));
        assert(rpn_calc().parse("PI cos") == cos(Pi));
        assert(rpn_calc().parse("PI tan") == tan(Pi));
        assert(rpn_calc().parse("0.3450 asin @") == asin(numeric("0.345")));
        assert(rpn_calc().parse("0.7345 acos @") == acos(numeric("0.7345")));
        assert(rpn_calc().parse("0.1234 atan @") == atan(numeric("0.1234")));
    }

    return 0;
}
