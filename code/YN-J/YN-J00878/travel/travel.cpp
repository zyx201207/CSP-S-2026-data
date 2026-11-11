#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

using ll = long long;

static inline void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}

int main(void) {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	FastIO();
	string s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;
	string a1 = s2.length() == 3 ? s2.substr(0, 2) : s2.substr(0, 3);
	string a2 = s4.length() == 3 ? s4.substr(0, 2) : s4.substr(0, 3);
	string b1 = s2.length() == 3 ? s2.substr(2, 1) : s2.substr(3, 1);
	string b2 = s2.length() == 3 ? s4.substr(2, 1) : s4.substr(3, 1);
	if (s1 == s3) {
		cout << 1;
		if (a1 == a2) {
			cout << 1;
			if ((b1 <= "C" && b2 <= "C") || (b1 >= "D" && b2 >= "D")) {
				cout << 1;
				if ((b1 == "A" && b2 == "B")
				        || (b1 == "B" && b2 == "A")
				        || (b1 == "B" && b2 == "C")
				        || (b1 == "C" && b2 == "B")
				        || (b1 == "D" && b2 == "F")
				        || (b1 == "F" && b2 == "D")) {
					cout << 1;
				} else {
					cout << "0";
					return 0;
				}
			} else {
				cout << "00";
				return 0;
			}
		} else {
			cout << "000";
			return 0;
		}
	} else {

		cout << "0000";
	}


	return 0;
}