#pragma once
#include <iostream>
#include <iterator>
#include <set>
#include <unordered_set>

using namespace std;
class Value {
public:
	Value();
	Value(string value);
	unordered_set<string> values = {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
	string value;
	friend int operator<(Value c1, Value c2);
	friend string operator++(Value c1);
};