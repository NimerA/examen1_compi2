#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#define YYSTYPE double

#include <sstream>
#include <memory>
#include <vector>
#include <cstring>
#include "doctest.h"
#include "expr_parser.h"

using PIntDouble = std::pair<int, double>;

std::vector<PIntDouble> test1 = {
    {NUMBER, 45.0},
    {OP_ADD, 0},
    {NUMBER, 10.0},
};

std::vector<PIntDouble> test2 = {
    {OPEN_PAR, 0.0},
    {NUMBER, 0.535},
    {OP_SUB, 0.0},
    {NUMBER, 0.035},
    {CLOSE_PAR, 0.0},
    {OP_MUL, 0.0},
    {NUMBER, 10.0},
};

std::vector<PIntDouble> test3 = {
    {OPEN_PAR, 0.0},
    {NUMBER, 0.535},
    {OP_SUB, 0.0},
    {NUMBER, 0.035},
    {CLOSE_PAR, 0.0},
    {OP_MUL, 0.0},
    {NUMBER, 100.0},
    {SEMICOLON, 0.0},
    {OPEN_PAR, 0.0},
    {NUMBER, 0.4},
    {OP_ADD, 0.0},
    {NUMBER, 0.6},
    {CLOSE_PAR, 0.0},
    {OP_DIV, 0.0},
    {NUMBER, 4},
};

/* TODO: Implement the following functions */
int parse(const std::vector<PIntDouble>& inv)
double getExprValue(int index);
int getExprCount();

TEST_CASE("Add expression") {
    REQUIRE(parse(test1) == 0);
    REQUIRE(getExprCount() == 1);
    REQUIRE(getExprValue(0) == 55);
}

TEST_CASE("Sub/Mult expression") {
    REQUIRE(parse(test2) == 0);
    REQUIRE(getExprCount() == 1);
    REQUIRE(getExprValue(0) == 5.0);
}

TEST_CASE("Multiple expressions") {
    REQUIRE(parse(test3) == 0);
    REQUIRE(getExprCount() == 2);
    REQUIRE(getExprValue(0) == 50.0);
    REQUIRE(getExprValue(1) == 0.25);
}

