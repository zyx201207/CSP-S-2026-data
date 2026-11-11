#include <bits/stdc++.h>
using namespace std;
long long n, x, ans = 0, cnt = 0;
char y;
string s;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x >> y;
		for (int q = 1; q <= x; q++) {
			s += y;
		}
	}
	for (int i = 0; i <= (s.size() - 1) / 2; i++) {
		if (s[i] != s[s.size() - i - 1] ) {
			cnt++;
			s[i] = s[i] != s[s.size() - i - 1];
		}
	}
	cout << cnt;
	return 0;
}