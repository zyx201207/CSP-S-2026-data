#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string a, b, c, d;
	cin >> a >> b >> c >> d;
	if (a == c) {
		cout << "1";
		int e = 0, f = 0;
		e = (b[0] - 48) * 10 + (b[1] - 48);
		f = (d[0] - 48) * 10 + (d[1] - 48);
		if (e == f) {
			cout << "1";
			string s1, s2;
			s1 = b[2];
			s2 = d[2];
			if ((s1 == "D" || s1 == "F") && (s2 == "D" || s2 == "F")) {
				cout << "11";
			} else if ((s1 == "A" || s1 == "B") && (s2 == "A" || s2 == "B")) {
				cout << "11";
			} else if ((s1 == "C" || s1 == "B") && (s2 == "C" || s2 == "B")) {
				cout << "11";
			} else if ((s1 == "C" || s1 == "A") && (s2 == "C" || s2 == "A")) {
				cout << "10";
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