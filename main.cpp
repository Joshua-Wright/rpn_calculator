#include <iostream>
#include <string>
#include "rpn_calc.h"

using namespace std;

int main() {
    using std::cout;
    using std::endl;
    using namespace rpn;
    std::string line;
    while (getline(cin, line)) {
        if (line == "q" || line == "quit" || line == "exit") {
            break;
        }
        cout << parse_rpn(line) << endl;
    }
    return 0;
}