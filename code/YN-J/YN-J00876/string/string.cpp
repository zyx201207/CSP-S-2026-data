#include <bits/stdc++.h>
using namespace std;
long long n, m = 0;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	string s, s1;

	for (long long i = 1; i <= n; i++) {

		long long a;
		string c;
		cin >> a >> c;
		m += a;

		for (long long j = 1; j <= a; j++) {

			s += c;
		}
	}

	long long cnt = 0;

	for (long long i = 0; i < m; i++) {

		s1[i] = s[m - i - 1];

		if (s1[i] != s[i]) {
			cnt++;
		}
	}

	cout << cnt / 2;
	return 0;
}
