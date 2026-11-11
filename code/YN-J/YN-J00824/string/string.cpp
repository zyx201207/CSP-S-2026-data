#include <bits/stdc++.h>
using namespace std;
long long n;
string s;

int main() {
	freopen("string.in", "r", stdin);
	freopen("stirng.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	while (n) {
		int m;
		string a;
		cin >> m >> a;
		for (int i = 1; i <= m; i++) {
			s += a;
		}
		n--;
	}
	long long len = s.size(), ans = 0;
	for (int i = 0; i * 2 < len; i++) {
		if (s[i] != s[len - 1 - i]) {
			ans++;
		}
	}
	cout << ans;
	return 0;
}

