// (c) Copyright 2015 Josh Wright
#pragma once

#include <string>
#include "rpn_calc.h"

namespace rpn {

    struct tree_node {
        token node;
        std::vector<tree_node> children;
    };

    tree_node render_expression_tree(const std::string &line);

    void print_tree(const tree_node &head, int level = 0, bool first = true);

    void tree_to_gv(const tree_node &head);
}