// (c) Copyright 2015 Josh Wright
#include "expression_tree.h"

int main(int argc, char const *argv[]) {
//    auto d = rpn::render_expression_tree("5 5 8 + / pi 2 * sin + 1234 sqrt *");
    auto d = rpn::render_expression_tree(argv[1]);
    rpn::tree_to_gv(d);
}
