#include <bits/stdc++.h>
using namespace std;
long long n, l, cnt = 0, r, zongchang = 0;
string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;

	while (n--) {
		long long x;
		cin >> x;
		char a;
		cin >> a;

		for (long long i = 1; i <= x; i++) {

			s += a;
		}

		zongchang += x;
	}

	if (zongchang % 2 == 0) {
		l = zongchang / 2 - 1, r = l + 1;
	} else {
		l = zongchang / 2 - 1, r = l + 2;
	}

	while (l >= 0 && r <= zongchang) {
		if (s[l] != s[r]) {
			cnt++;
		}

		l--, r++;
	}

	cout << cnt;
	return 0;
}
