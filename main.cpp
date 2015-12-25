#include <ios>
#include <iostream>
#include <string>
#include <unordered_map>
#include <cstring>
#include <random>
#include <iomanip>
#include "linenoise/linenoise.h"
#include "rpn_calc.h"
#include "expression_tree.h"

int main(int argc, char** argv) {
    using std::cerr;
    using std::cout;
    using std::endl;
    using std::cin;
    using namespace rpn;

    char *line_c_str;
    std::unordered_map<std::string, long double> variables;
    /*TODO: seed this better*/
    std::srand((unsigned int) std::time(nullptr));

    if ( argc >= 2 && !strcmp(argv[1], "-e")) {
        /*evaluate the argument as an expression*/
        cout << parse_rpn(argv[2], variables) << endl;
        return 0;
    }

    while ((line_c_str = linenoise(">> ")) != NULL) {
        if (line_c_str[0] == '\0') {
            /*stil need to free the c string manually*/
            free(line_c_str);
            continue;
        }
        linenoiseHistoryAdd(line_c_str);
        std::string line(line_c_str);
        if (line == "q" || line == "quit" || line == "exit") {
            /*quit when the user asks*/
            /*stil need to free the c string manually*/
            free(line_c_str);
            return 0;
        } else if (line[0] == '#') {
            /*handle stuffs*/
            /*this part has no math so parse_rpn() won't know what to do with it*/
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
            } else if (!std::strncmp(line.c_str(), "#define ", strlen("#define ")) ||
                       !std::strncmp(line.c_str(), "#d ", strlen("#d "))) {
                /*get a variable. The rest of the line is treated as an expression*/
                std::size_t idx = line.find(" ") + 1;
                std::stringstream stream(line.substr(idx).c_str());
                std::string varname;
                std::string varcontent;
                stream >> varname;
                getline(stream, varcontent);
                variables[varname] = parse_rpn(varcontent, variables);
            } else if (!std::strncmp(line.c_str(), "#tree ", strlen("#tree ")) ||
                       !std::strncmp(line.c_str(), "#t ", strlen("#t "))) {
                /*print parse tree*/
                std::size_t idx = line.find(" ") + 1;
                std::string newline = line.substr(idx);
                tree_node head = rpn::render_expression_tree(newline);
                print_tree(head);
            }
        } else {
            try {
                cout << parse_rpn(line, variables) << endl;
            } catch (std::runtime_error &e) {
                cerr << "Error: " << e.what() << endl;
            }
        }
        /*need to free the c string manually*/
        free(line_c_str);
    }
    return 0;
}
