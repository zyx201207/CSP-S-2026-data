#include <bits/stdc++.h>
using namespace std;
string a, b, c, d;
int f = 1;
int m, n, i, j;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> a >> b >> c >> d;
	m = b[0] * 100 + b[1];
	n = d[0] * 100 + d[1];
	i = b[2];
	j = d[2];
	if (a == c) {
		cout << '1';
	} else {
		cout << '0';
		f = 0;
	}
	if (m == n && f == 1) {
		cout << '1';
	} else {
		cout << '0';
		f = 0;
	}
	if (i <= 67 && j <= 67 && f == 1) {
		cout << '1';
	} else if (i >= 68 && j >= 68 && f == 1) {
		cout << '1';
	} else {
		cout << '0';
		f = 0;
	}
	if ((i - j == 1 || j - i == 1) &&  f == 1) {
		cout << '1';
	} else {
		cout << '0';
	}

	return 0;
}
