#include <bits/stdc++.h>
using namespace std;


int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long q = 0, n, s;
	string c, w = "";
	cin >> n;
	for (long long i = 1; i <= n; ++i) {
		cin >> s >> c;
		for (int j = 1; j <= s; ++j) {
			w += c;
		}
	}
	for (int i = 0; i <= w.length() ; ++i) {
		if (w[i] != w[w.length() - i]) {
			w[w.length() - i] = w[i];
			q++;
		}
	}
	cout << q;
	return 0;
}
