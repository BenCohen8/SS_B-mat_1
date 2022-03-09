#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}


TEST_CASE("Good input") { //test1
	CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n"
													 "@-------@\n"
													 "@-@@@@@-@\n"
													 "@-@---@-@\n"
													 "@-@@@@@-@\n"
													 "@-------@\n"
													 "@@@@@@@@@"));}
TEST_CASE("Good input") {//test2
	CHECK(nospaces(mat(1, 1, '@', '-')) == nospaces("@"));}
													
TEST_CASE("Good input") {//test3
	CHECK(nospaces(mat(3,3, '!', '#')) == nospaces( "!!!\n"
													"!#!\n"
													"!!!\n"));}

TEST_CASE("Good input") {//test4
	CHECK(nospaces(mat(3,3, '3', '3')) == nospaces( "333\n"
													"333\n"
													"333"));}

TEST_CASE("Good input") {//test5
	CHECK(nospaces(mat(3,9, '1', '0')) == nospaces( "111\n"
													"101\n"
													"101\n"
													"101\n"
													"101\n"
													"101\n"
													"101\n"
													"101\n"
													"111"));}
TEST_CASE("Good input") {//test6
	CHECK(nospaces(mat(11,11, 'Q', 'W')) == nospaces("QQQQQQQQQQQ\n"
													"QWWWWWWWWWQ\n"
													"QWQQQQQQQWQ\n"
													"QWQWWWWWQWQ\n"
													"QWQWQQQWQWQ\n"
													"QWQWQWQWQWQ\n"
													"QWQWQQQWQWQ\n"
													"QWQWWWWWQWQ\n"
													"QWQQQQQQQWQ\n"
													"QWWWWWWWWWQ\n"
													"QQQQQQQQQQQ"));}
TEST_CASE("Good input") {//test7
	CHECK(nospaces(mat(11, 1, '@', '-')) == nospaces("@@@@@@@@@@@"));}

TEST_CASE("Good input") {//test8
	CHECK(nospaces(mat(1, 11, '-', '!')) == nospaces("-\n"
													"-\n"
													"-\n"
													"-\n"
													"-\n"
													"-\n"
													"-\n"
													"-\n"
													"-\n"
													"-\n"
													"-"));}
												

TEST_CASE("Good input") {//test9
	CHECK(nospaces(mat(5, 5, '[', ']')) == nospaces("[[[[[\n"
													"[]]][\n"
													"[][][\n"
													"[]]][\n"
													"[[[[["));}
TEST_CASE("Bad input") {//test 10
    CHECK_THROWS(mat(-11, 1, '[', '['));
}

TEST_CASE("Bad input") {//test 11
    CHECK_THROWS(mat(1, -1, '[', '['));
}

TEST_CASE("Bad input") {//test 12
    CHECK_THROWS(mat(1, 1, '\t', '\n'));
}
TEST_CASE("Bad input") {//test 13
    CHECK_THROWS(mat(11, 0, '$', '%'));
}
TEST_CASE("Bad input") {//test 14
    CHECK_THROWS(mat(-1, -1, '@', '%'));
}
TEST_CASE("Bad input") {//test 15
    CHECK_THROWS(mat(11, -1, '!', '%'));
}
TEST_CASE("Bad input") {//test 16
    CHECK_THROWS(mat(11, 5, '\t', '%'));
}

TEST_CASE("Bad input") {//test 17
    CHECK_THROWS(mat(10, 5, '$', '%'));
}

TEST_CASE("Bad input") {//test 18
    CHECK_THROWS(mat(0, 0, '$', '%'));
}

TEST_CASE("Bad input") {//test19
    CHECK_THROWS(mat(9, 101, ' ', '%'));
}

TEST_CASE("Bad input") { //test20
    CHECK_THROWS(mat(13, 3, '$', '\n'));
}
