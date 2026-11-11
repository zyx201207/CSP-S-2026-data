#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n, z = 0, c = 0;
	string s;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int sl;
		string nr;
		cin >> sl >> nr;
		c += sl;
		for (int j = 1; j <= sl; j++) {
			s += nr;
		}
	}
	for (int i = 0; i * 2 < c; i++) {
		if (s[i] != s[c - i]) {
			z++;
		}
	}
	cout << z;
	return 0;
}

