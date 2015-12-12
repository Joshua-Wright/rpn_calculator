#include <ios>
#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
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
            /*quit when the user asks*/
            return 0;
        } else if (line[0] == '#') {
            /*handle stuffs*/
            /*this line has no math so parse_rpn() won't know what to do with it*/
            if (line == "#hex") {
                cout << std::hexfloat;
            } else if (line == "#def" || line == "#default") {
                cout << std::defaultfloat;
            } else if (line == "#fix" || line == "#fixed") {
                cout << std::fixed;
            } else if (line == "#sci" || line == "#scientific") {
                cout << std::scientific;
            } else if (line == "#max" || line == "#maxdigits") {
                cout << std::setprecision(std::numeric_limits<long double>::digits10);
            } else if (!std::strncmp(line.c_str(), "#digits ", strlen("#digits ")) ||
                       !std::strncmp(line.c_str(), "#dig ", strlen("#dig "))) {
                std::size_t idx = line.find(" ") + 1;
                cout << std::setprecision(std::atoi(line.substr(idx).c_str()));
            }
        } else {
            try {
                cout << parse_rpn(line) << endl;
            } catch (std::runtime_error &e) {
                cerr << "Error: " << e.what() << endl;
            }
        }
    }
    return 0;
}
