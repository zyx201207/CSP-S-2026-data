/*
CSP-J 2026 T2
by hty
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
string s;
int n;
const int N = 2e5 + 10;
int a[N];
char c[N];
int cnt;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		for (int j = 1; j <= a[i]; j++) {
			s += c[i];
		}
	}
	for (int i = 0; i < (int)s.size() / 2; i++) {
		if (s[i] != s[(int)s.size() - i - 1]) {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}