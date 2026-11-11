#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[200005];
char t[200005];

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, m = 0, f = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i]  >> t[i];
		m += a[i];
		if (i != 0 && t[i] != t[i] - 1) {
			f = 1;
		}
	}
	if (n == 1 || f == 0) {
		cout << "0";
	} else {
		string s, s1, s2;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 1; j <= a[i]; j++) {
				s += t[i];
			}
		}
		for (int i = 0; i < m / 2; i++) {
			s1 += s[i];
		}
		if (m % 2 == 0) {
			for (int i = m - 1; i >= m / 2; i--) {
				s2 += s[i];
			}
		} else {
			for (int i = m - 1; i > m / 2; i--) {
				s2 += s[i];
			}
		}
		for (int i = 0; i < m / 2; i++) {
			if (s1[i] != s2[i]) {
				sum++;
			}
		}
		cout << sum;
	}
	return 0;
}