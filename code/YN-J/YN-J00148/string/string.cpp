#include <bits/stdc++.h>
using namespace std;
string s;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int c[100000];
	int n, a, b, sum = 0, cnt = 0;
	char d;
	bool du = 1;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a >> d;
		c[i] = a;
		for (int i = 1; i <= a; i++) {
			s += d;
		}

	}
	for (int i = 0; i < sum; i++) {
		if (s[i] != s[n - i]) {
			du = 0;
			cnt++;
		}
		if (c[i] > c[n]) {
			b = max(c[i], c[n]);
			cout << b;
		}
	}
	if (du == true) {
		cout << 0;
	}
	return 0;
}