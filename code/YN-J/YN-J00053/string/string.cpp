#include <bits/stdc++.h>
#define int long long
using namespace std;
int ans;

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s, s1;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		char c;
		cin >> c;
		for (int j = 1; j <= a; j++) {
			s += c;
		}
	}
	int len = s.length();
	s1 = s.substr(0, len / 2);
	for (int i = 0; i < s1.length(); i++) {
		if (s[len - i] != s1[i])
			ans++;
	}
	cout << ans;
	return 0;
}