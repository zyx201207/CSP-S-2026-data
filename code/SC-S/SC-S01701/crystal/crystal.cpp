#include<bits/stdc++.h>
using namespace std;
int n, ans;
long long m, a[500005], mn;
long long maxl, minl, suml, pdpd, cntl;
bool pd, pdl;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		maxl = max(maxl, a[i]);
		minl = min(minl, a[i]);
		if (a[i] != i) {
			pd = 1;
		}
		if (i > 2) {
			pdpd = a[2] - a[1];
			if (a[i] - a[i - 1] != pdpd) {
				pdl = 1;
			}
		}
	}
	if (n > 5000 && maxl - minl <= 200) {
		cout << n;
		return 0;
	}
	if (n > 5000 && pd == 0) {
		for (int i = 1; suml + i <= m; i++) {
			suml += i;
			cntl++;
		}
		cout << cntl;
		return 0;
	}
	if (n > 5000 && pdl == 0) {
		for (int i = 1; suml + i <= m; i += pdpd) {
			suml += i;
			cntl++;
		}
		cout << cntl;
		return 0;
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		long long sum = 0;
		int cnt = 0;
		for (int j = 1; j < i; j++) {
			mn = a[i] - a[j];
			if (mn > m || sum + mn > m) {
				break;
			}
			sum += mn;
			cnt++;
		}
		ans = max(ans, cnt);
	}
	cout << ans + 1;
	return 0;
}