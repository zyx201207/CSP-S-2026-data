#include <bits/stdc++.h>
using namespace std;
string s1, s2, x, y;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> s1 >> x >> s2 >> y;
	int n = x.size(), m = y.size();

	if (s1 == s2)
		cout << 1;
	else {
		cout << "0000";
		return 0;
	}

	string a = "", b = "";
	int c, d;

	for (int i = 0; i < n - 1; i++) {

		a += x[i];
		b += y[i];
	}

	if (b == a)
		cout << 1;
	else {
		cout << "000";
		return 0;
	}

	if (x[n - 1] == 'A' || x[n - 1] == 'B' || x[n - 1] == 'C')
		c = 1;
	else
		c = 0;

	if (y[n - 1] == 'A' || y[n - 1] == 'B' || y[n - 1] == 'C')
		d = 1;
	else
		d = 0;

	if (c == d)
		cout << 1;
	else {
		cout << "00";
		return 0;
	}

	if (abs(int(x[n - 1]) - int(y[m - 1])) == 1)
		cout << 1;
	else
		cout << 0;
	return 0;
}