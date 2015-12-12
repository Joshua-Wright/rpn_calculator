#include <iostream>
#include <string>
#include "rpn_calc.h"

int main() {
    using std::cerr;
    using std::cout;
    using std::endl;
    using std::cin;
    using namespace rpn;
    std::string line;
    while (getline(cin, line)) {
        if (line == "q" || line == "quit" || line == "exit") {
            break;
        }
        try {

            cout << parse_rpn(line) << endl;
        } catch (std::runtime_error &e) {
            cerr << "Error: " << e.what() << endl;
        }
    }
    return 0;
}
