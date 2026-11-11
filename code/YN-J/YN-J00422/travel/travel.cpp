#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	string s, s_1, s_2, s_3;
	int c, d;
	cin >> s >> s_1 >> s_2 >> s_3;
	if (s == s_2) {
		cout << "1";
		string a, b;
		a = s_1[0] + s_1[1];
		b = s_3[0] + s_3[1];
		if (a == b) {
			cout << "1";
			c = s_1[2];
			d = s_3[2];
			if ((c <= 67 && d <= 67) || (c > 67 && d > 67)) {
				cout << "1";
				if ((c == 67 && d == 66) || (c == 66 && d == 67) || (c == 66 && d == 65) || (c == 65 && d == 66) || (c == 67
				        && d == 68) || (c == 68
				                        && d == 70) || (c == 70 && d == 68)) {
					cout << "1";
				} else {
					cout << "0";
				}
			} else {
				cout << "00";
			}
		} else {
			cout << "000";
		}
	} else {
		cout << "0000";
	}
	return 0;
}
