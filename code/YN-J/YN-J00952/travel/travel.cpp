#include <iostream>
#include <string>
using namespace std;

string c1, c2, s1, s2, result;

char bool_to_str_01(bool is) {
	if (is)
		return '1';
	return '0';
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	cin >> c1 >> s1 >> c2 >> s2;

	bool in_same_y = s1.substr(0, 2) == s2.substr(0, 2);
	bool in_same_gourp = in_same_y && !(
	                         ('A' <= s1[2] && s1[2] <= 'C') ^ ('A' <= s2[2] && s2[2] <= 'C')
	                     );

	result = "0000";
	result[0] = bool_to_str_01(c1 == c2);
	if (c1 == c2) {
		result[1] = bool_to_str_01(in_same_y);
		result[2] = bool_to_str_01(in_same_gourp);
		result[3] = bool_to_str_01(
		                in_same_gourp && abs(s1[2] - s2[2]) <= 1
		            );
	}

	cout << result;

	return 0;
}
