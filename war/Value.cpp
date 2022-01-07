#include "Value.h"
Value::Value() {
	value = "2";
}

Value::Value(string valueC) {
	value = valueC;
}

int operator<(Value c1, Value c2)
{
	const unordered_set<string> allValues = c1.values;
	auto pos1 = allValues.find(c1.value);
	auto pos2 = allValues.find(c2.value);

	int distance1 = std::distance(allValues.begin(), pos1);
	int distance2 = std::distance(allValues.begin(), pos2);


	if (pos1 == pos2) {
		return 0;
	}

	if (distance1 > distance2) {
		return 1;
	}

	if (distance1 < distance2) {
		return 2;
	}

	return 3;
}

string operator++(Value c1)
{
	const unordered_set<string> allValues = c1.values;
	auto pos = allValues.find(c1.value);
	
	if (++pos == allValues.end()) {
		return "2";
	}
	return *(pos);
}