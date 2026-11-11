#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500010];
bool flag;

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	int flg = abs(a[2] - a[1]);
	int ans = flg;
	int cnt = 0;
	while (m - flg >= 0 && cnt <= n) {
		m -= flg;
		cnt++;
		flg += ans;
	}
	cout << cnt + 1;

	return 0;
}
