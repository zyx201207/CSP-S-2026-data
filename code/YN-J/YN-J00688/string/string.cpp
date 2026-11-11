#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	string s = "/";
	long long n, a, cnt = 0;
	cin >> n;
	char c;

	for (int i = 1; i <= n; i++) {

		cin >> a >> c;

		for (int j = 1; j <= a; j++) {

			s += c;
		}
	}

	long long l = s.size() - 1;

	for (int i = l / 2; i >= 1; i--) {

		if (s[i] != s[l + 1 - i]) {
			cnt++;
		}
	}

	cout << cnt;
	return 0;
}