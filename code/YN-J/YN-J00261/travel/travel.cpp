/*
CSP-J 2026 T1
by hty
*/
#include <bits/stdc++.h>
using namespace std;
string s1, s2, c1, c2;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		cout << 1;
		string str1 = s1, str2 = s2;
		str1.pop_back(), str2.pop_back();
		if (str1 == str2) {
			cout << 1;
			str1 = s1, str2 = s2;
			char ch1 = s1[(int)s1.size() - 1], ch2 = s2[(int)s2.size() - 1];
			if ((ch1 == 'F' && ch2 == 'D') || (ch1 == 'D' && ch2 == 'F')) {
				cout << "11";
				return 0;
			} else if ((ch1 == 'A' && ch2 == 'B') || (ch1 == 'B' && ch2 == 'A')) {
				cout << "11";
				return 0;
			} else if ((ch1 == 'B' && ch2 == 'C') || (ch1 == 'C' && ch2 == 'B')) {
				cout << "11";
				return 0;
			} else if ((ch1 == 'C' && ch2 == 'A') || (ch1 == 'A' && ch2 == 'C')) {
				cout << "10";
				return 0;
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
		return 0;
	}
	return 0;
}