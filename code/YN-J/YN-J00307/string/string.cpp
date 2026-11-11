#include <bits/stdc++.h>
using namespace std;
string s, s1;

int main() {
//	freopen("string.in", "r", stdin);
//	freopen("string.out", "w", stdout);
	long long n, cn = 0, h;
	cin >> n;
	long long a[n];
	char b[n];
	for (long long i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		for (long long j = 0; j < a[i]; j++) {
			s += b[i];
		}
	}
	for (long long i = s.size() - 1; i >= 0; i--) {
		s1 += s[i];
	}
	if (s == s1) {
		cout << 0;
		return 0;
	}
	h = s.size() / 2;
	if (h % 2 == 0) {
		string sq, sh;
		for (long long i = h - 1; i >= 0; i--) {
			sq += s[i];
		}
		for (long long i = h; i < 2 * h; i++) {
			sh += s[i];
		}
		for (long long i = 0; i < h; i++) {
			if (sq[i] != sh[i]) {
				cn++;
			}
		}
	} else {
		string sq, sh;
		for (long long i = h - 1 ; i >= 0; i--) {
			sq += s[i];
		}
		for (long long i = h + 1; i <= 2 * h; i++) {
			sh += s[i];
		}
		for (long long i = 0; i < h; i++) {
			if (sq[i] != sh[i]) {
				cn++;
			}
		}
	}
	cout << cn;
	return 0;
}