#include <iostream>
#include <string>
using namespace std;


int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string num1 = "0000";
	string c1 ;
	string c2;
	string s1;
	string s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2 && s1 != s2) {
		string num1 = "1000";

		if (s1[0] == s2[0] && s1[1] == s2[1]) {
			string num1 = "1100";
			if (s1[2] + s2[2] <= 'C' + 'B' && s1[2] != 'D' && s2[2] != 'D' ) {
				string num1 = "1110";
				if (s1[2] - 1 == s2[2] || s1[2] + 1 == s2[2] ) {
					string num1 = "1111";
					cout << num1 << endl;
					return 0;
				} else
					cout << num1 << endl;
			} else if (s1[2] + s2[2] == 'D' + 'F') {
				string num1 = "1111";
				cout << num1 << endl;
				return 0;
			} else
				cout << num1 << endl;
		} else
			cout << num1 << endl;
	} else
		cout << num1 << endl;
	return 0;
}
