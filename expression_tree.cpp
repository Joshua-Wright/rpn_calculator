// (c) Copyright 2015 Josh Wright
#include <vector>
#include "rpn_calc.h"
#include "stack.h"
#include "expression_tree.h"

namespace rpn {

    tree_node build_tree(std::vector<token> &tokens) {
        tree_node tree_node1;
        tree_node1.node = tokens.back();
        tokens.pop_back();
        if (tree_node1.node.type == NUMBER) {
            /*do not recurse, return the value*/
            return tree_node1;
        } else if (tree_node1.node.type == OPERATOR) {
            /*recurse*/
            switch (tree_node1.node.op) {
                /*two operands*/
                case ADD:
                case SUBTRACT:
                case MULTIPLY:
                case DIVIDE:
                case MODULO:
                case ROOT:
                case POWER:
                case LOG_A:
                case ATAN2_RAD: {
                    tree_node1.children.push_back(build_tree(tokens));
                    tree_node1.children.push_back(build_tree(tokens));
                    break;
                }

                    /*one operand*/
                case SQUARE:
                case SQRT:
                case LOG_E:
                case LOG_10:
                case LOG_2:
                case EXP_E:
                case EXP_10:
                case EXP_2:
                case SIN_RAD:
                case COS_RAD:
                case TAN_RAD:
                case ASIN_RAD:
                case ACOS_RAD:
                case ATAN_RAD:
                case FLOOR:
                case CEIL: {
                    tree_node1.children.push_back(build_tree(tokens));
                    break;
                }
                default:
                    throw std::runtime_error("invalid token");
            }
        }
    }

    void print_tree(const tree_node &head, int level, bool first) {
        /*print the indentation*/
        for (int i = 0; i < level-1; i++) {
            std::cout << "  ";
        }
        /*first = don't print any indentation, because it's the root node*/
        if (!first) {
            /*unicode box drawing characters are cool*/
            std::cout << "└ ";
        }
        /*print the head node*/
        if (head.node.type == NUMBER) {
            std::cout << head.node.number << std::endl;
        } else if (head.node.type == OPERATOR) {
            std::cout << get_op_string(head.node.op) << std::endl;
        }

        /*print all children*/
        for (auto &&a : head.children) {
            print_tree(a, level + 1, false);
        }
    }

    tree_node render_expression_tree(const std::string &line) {
        std::vector<token> tokens(tokenize_expression(line));
        tree_node head = build_tree(tokens);
        return head;
    }

    void _tree_to_gv(const tree_node &head, char &current_var) {
        /*TODO: make a better way to name these variables sequentially*/
        /*print the head node*/
        char this_node_label = current_var;
        if (head.node.type == NUMBER) {
            std::cout << "" << current_var++ << "[label=\"" << head.node.number << "\"];" << std::endl;
        } else if (head.node.type == OPERATOR) {
            std::cout << "" << current_var++ << "[label=\"" << get_op_string(head.node.op) << "\"];" << std::endl;
        }

        /*print all children*/
        for (auto &&a : head.children) {
            std::cout << this_node_label << "->" << current_var << std::endl;
            _tree_to_gv(a, current_var);
        }

    }

    void tree_to_gv(const tree_node &head) {
        char current_var = 'a';
        std::cout << "digraph g{" << std::endl;
        _tree_to_gv(head, current_var);
        std::cout << "}" << std::endl;
    }

}
