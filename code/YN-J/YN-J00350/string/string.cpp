#include <bits/stdc++.h>
using namespace std;

int t;
string s;
long long len;

int main() {
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> t;

	while (t--) {
		int n;
		char c;
		cin >> n >> c;
		len += n;

		for (int i = 1; i <= n; i++) {

			s += c;
		}
	}

	s = ' ' + s;
	long long l = 1, r = len, cnt = 0;

	for (; l < r; l++, r--) {

		if (s[l] != s[r])
			cnt++;
	}

	cout << cnt;
	return 0;
}
