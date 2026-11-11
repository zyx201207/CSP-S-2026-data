#include <bits/stdc++.h>
using namespace std;
string s1, c1, s2, c2;
int ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		int jga = (s1[0]) * 10 + (s1[1] - '0'), jgb = (s2[0]) * 10 + (s2[1] - '0');
		if (jga == jgb) {
			int wh1 = (s1[2]) - 'A' + 1, wh2 = (s2[2]) - 'A' + 1;
			if ((wh1 <= 3 && wh2 <= 3) || (wh1 > 3 && wh2 > 3)) {
				if (abs(wh1 - wh2) == 1) {
					cout << "1111";
				} else {
					cout << "1110";
				}
			} else {
				cout << "1100";
			}
		} else {
			cout << "1000";
		}
	} else {
		cout << "0000";
	}
	return 0;
}