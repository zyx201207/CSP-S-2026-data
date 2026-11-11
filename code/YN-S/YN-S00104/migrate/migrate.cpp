#include <bits/stdc++.h>
using namespace std;
long long a[2000005];
long long an, num, ans;
long long n, d;

void dfs(long long st, long long cnt, long long nd) {
	if (st == nd) {
		if (cnt < an) {
			num = 1;
			an = cnt;
		} else if (cnt == an)
			num++;
	}
	for (int i = st + 1; a[i] - a[st] <= d && i <= n; i++) {
		dfs(i, cnt + 1, nd);
	}
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T, c;
	cin >> c >> T;
	while (T--) {

		ans = 0;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		long long D = (long long)(a[2] - a[1]);
		//cout << D << " ";
		if (D > d || d >= a[n] - a[1]) {
			cout << 0 << "\n";
			continue;
		}
		if (c == 11 || c == 12) {
			long long f = d / D;
			ans = (a[n] - D * (2 * f + 1) - a[1]) / D;
			cout << ans << "\n";
			continue;
		}
		for (int l = 1; l <= n; l++) {
			for (int r = l + 1; r <= n; r++) {
				an = 0x7fffffffffffffff, num = 0;
				dfs(l, 0, r);
				if (num == 2)
					ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}