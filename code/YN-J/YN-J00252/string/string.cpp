#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
const int M = 2e5 * 1e9;
char c[N];
int n;
int cnt;
int t = 1;
int ans;

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	while (n--) {
		int aa;
		char cc;
		cin >> aa >> cc;
		cnt += aa;
		for (int i = 1; i <= aa; i++) {
			c[t] = cc;
			t++;
		}
	}
	int m = cnt / 2;
	for (int i = 1; i <= t; i++) {
		cout << c[i];
	}
	for (int i = 1, j = cnt; i <= m; i++, j--) {
		if (c[i] != c[j]) {
			ans++;
		}
	}
	cout << ans;
	return 0;
}