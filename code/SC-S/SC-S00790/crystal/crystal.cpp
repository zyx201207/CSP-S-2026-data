#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
int a[N];
signed main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort (a + 1, a + 1 + n);
	bool ok = false;
	int k = a[2] - a[1];
	for (int i = 2; i <= n; i++) {
		if (a[i] - a[i - 1] != k) {
			ok = true;
			continue;
		}
	}
	if (ok == false) {
		for (int i = 1; i < n; i++) {
			int cnt = (i * i + i) / 2 * k;
			if (cnt > m) {
				cout << i;
				return 0;
			}
		}
		cout << n;
		return 0;
	}
	//特殊性质A(m >= 1 * k + 2 * k + ... + k * n(k为等差数列之差), ans = n + 1) 
	//特殊性质B(m >= 1 + 2 + 3 + ... + n, ans = n + 1) 
	int ans = 0;
	//n * n:
	for (int i = 1; i <= n; i++) {
		int cnt = 1, now = 0;
		for (int j = 1; j < i; j++) {
			now += abs(a[i] - a[j]);
			if (now > m) continue;
			cnt++;
		}
		ans = max(ans, cnt);
	}
	cout << ans;
	return 0;
}
/*
5 5
1 2 4 8 9

3
*/
/*
5 8
-3 -1 2 2 7

4
*/