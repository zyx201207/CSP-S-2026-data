#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n, m, sum = 0;
	string t, s = "", sa, sb;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> m >> t;
		for (int j = 1; j <= m; j++) {
			s = s + t;
		}
	}
	if (s.size() % 2 == 0) {
		sa = s.substr(0, s.size() / 2);
		sb = s.substr(s.size() / 2, s.size() - 1);
	} else {
		sa = s.substr(0, (s.size() - 1) / 2);
		sb = s.substr((s.size() + 1) / 2, s.size() - 1);
	}
	for (int i = 0; i <= sa.size() - 1; i++) {
		if (sa[i] != sb[i]) {
			sum++;
		}
	}
	cout << sum;
	return 0;
}