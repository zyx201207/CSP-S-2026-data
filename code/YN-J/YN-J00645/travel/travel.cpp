#include <bits/stdc++.h>
using namespace std;
int n, m;
string s1, s2;
int a, b;
char c, d;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> n >> s1 >> m >> s2;
	a = 10 * (s1[0] - '0');
	a = s1[1] - '0';
	b = 10 * (s2[0] - '0');
	b = s2[1] - '0';
	c = s1[2];
	d = s2[2];
//	cout << c << ' ' << d;

	if (n == m) {
		cout << 1;

		if (a == b) {
			cout << 1;

			if (c >= 'A' && c <= 'C' && d >= 'A' && d <= 'C' || c == 'D' && d == 'F' || c == 'F' && d == 'D') {
				cout << 1;

				if (c - 1 == d || c + 1 == d) {
					cout << 1;
				} else
					cout << 0;
			} else
				cout << "00";
		} else
			cout << "000";
	} else
		cout << "0000";
	return 0;
}