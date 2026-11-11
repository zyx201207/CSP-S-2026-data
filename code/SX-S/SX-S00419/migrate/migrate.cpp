#include <bits/stdc++.h>
using namespace std;

int C, T, n, dp[2000005], q[2000005], lst[2000005], hd, tl;
long long d, a[2000005], ans, ct[2000005];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> C >> T;
	while (T--) {
		ans = 0;
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		hd = 1, tl = 0;
		for (int i = 1; i <= n; i++) {
			q[++tl] = i;
			while (hd <= tl && a[q[hd]] + d < a[i])
				hd++;
			lst[i] = q[hd];
		}
		for (int i = 1; i <= n; i++) {
			dp[i] = 0, ct[i] = 1;
			for (int j = i + 1; j <= n; j++) {
				dp[j] = 0, ct[j] = 0;
				if (lst[j] == j)
					break;
				int frm = max(i, lst[j]);
				dp[j] = dp[frm] + 1;
				ct[j] = ct[frm];
				if (frm + 1 < j && dp[frm] == dp[frm + 1])
					ct[j] += ct[frm + 1];
				if (frm + 2 < j && dp[frm] == dp[frm + 2])
					ct[j] += ct[lst[j] + 2];
				if (ct[j] > 1e9)
					ct[j] = 1e9;
				if (ct[j] == 2)
					ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
// Âå¹È¹Ø×¢ Sparse_Table uid = 1046508 Ð»Ð»ß÷