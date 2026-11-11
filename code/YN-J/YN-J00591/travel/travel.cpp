#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
string ans;
string s1_1, s2_1;
string s1_2, s2_2;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		ans += "1";
		string a, b;
		a += s1[0];
		s1_1 += s1[0];
		s1_1 += s1[1];
		s2_1 += s2[0];
		s2_1 += s2[1];
		if (s1_1 == s2_1) {
			ans += "1";
			s1_2 = s1[2];
			s2_2 = s2[2];
			if ((s1_2 == "F" && s2_2 == "D") || (s1_2 == "D" && s2_2 == "F") || (s1_2 == "B" && s2_2 == "A") || (s1_2 == "A"
			        && s2_2 == "B") || (s1_2 == "A" && s2_2 == "C") || (s1_2 == "C" && s2_2 == "A") || (s1_2 == "B" && s2_2 == "C")
			        || (s1_2 == "C" && s2_2 == "B") ) {
				ans += "1";
				if (((s1_2 == "F" && s2_2 == "D") || (s1_2 == "C" && s2_2 == "B") || (s1_2 == "B" && s2_2 == "A")) || ((s2_2 == "F"
				        && s1_2 == "D") || (s2_2 == "C" && s1_2 == "B") || (s2_2 == "B" && s1_2 == "A"))) {
					ans += "1";
				} else {
					ans += "0";
				}
			} else {
				ans += "00";
			}
		} else {
			ans += "000";
		}
	} else {
		ans += "0000";
	}
	cout << ans;
	return 0;
}