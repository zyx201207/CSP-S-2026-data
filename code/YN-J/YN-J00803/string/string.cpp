#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	string s;
	int n, sum = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		char c;
		cin >> x >> c;
		for (int j = 1; j <= x; j++) {
			s += c;
		}
	}
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != s[s.size() - 1 - i]) {
			sum++;
			s[s.size() - 1 - i] = s[i];
		}
	}
	cout << sum;
	return 0;
}