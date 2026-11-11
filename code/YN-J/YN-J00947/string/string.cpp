#include <bits/stdc++.h>
using namespace std;
int q = 1;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, wei = 1, sum = 0;
	cin >> n;

	string s;

	for (int i = 1; i <= n; i++) {

		int a;
		cin >> a;
		char b;
		cin >> b;

		for (int j = 1; j <= a; j++) {

			s[wei] = b;
			wei++;

			//cout << q;
			//q++;
		}
	}

	if (n == 1) {
		cout << 0;
		return 0;
	}

	string o, t;
	int m = s.size() / 2;

	for (int i = 1; i <= m; i++) {

		o[i] = s[i];
		//cout << q;
		//q++;
	}

	if (s.size() % 2 == 1) {
		m += 2;
	}

	int y = 1;

	for (int i = s.size(); i >= m; i--) {

		t[y] = s[i];
		y++;
	}

	for (int i = 1; i <= m - 2; i++) {

		if (o[i] != t[i])
			sum++;
	}

	cout << sum;
	return 0;
}
