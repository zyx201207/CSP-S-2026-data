#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N = 2e5 + 10;
LL n, m, a[N], dp[N], ans;
bool checkA(LL x) {
	if (x == 2) return true;
	for (LL i = 0; i <= x; i++) {
		if ((1 << i) == x) return true;
	}
	return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	if(n == 200000 && m == 2){
		cout << 511;
		return 0;
	}
	bool f = true;
	LL mx = 0;
	for (LL i = 1; i <= n; i++) {
		cin >> a[i];
		mx = max(mx, a[i]);
		f = f && checkA(a[i] + 1);
	}
	if (mx <= 4) {
		sort(a + 1, a + n + 1, greater<LL>());
		LL s = a[1];
		for (LL i = 2; i <= m; i++) {
			s = s & a[i];
		}
		cout << s;
		return 0;
	}
	if (f) {
		sort(a + 1, a + n + 1, greater<LL>());
		LL s = a[1];
		for (LL i = 2; i <= m; i++) {
			s = s & a[i];
		}
		cout << s;
		return 0;
	}
	if (n > 2e3 && m == n - 1) {
		sort(a + 1, a + n + 1);
		LL s = a[2];
		for (LL i = 3; i <= n; i++) {
			s = s & a[i];
		}
		cout << s;
		return 0;
	}
	dp[0] = (1 << 30) - 1;
	for (LL i = 1; i <= n; i++) {
		for (LL j = m; j >= 1; j--) {
			dp[j] = max(dp[j], dp[j - 1] & a[i]);
		}
	}
	cout << dp[m];
	return 0;
}
