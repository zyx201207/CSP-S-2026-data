#include <bits/stdc++.h>
#define FILE(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
#define DEBUG(s) freopen(s".err", "w", stderr)
#define CloseFILE fclose(stdin), fclose(stdout)
#define CloseDEBUG fclose(stderr)
#define int long long
#define endl "\n"
using namespace std;

constexpr int MAXN = 2e6+5;
int n, d, ans, a[MAXN], cnt[10][10][10], g[10], used[10];

void dfs(int step, bool mustbezero) {
	if (step == n+1) {
		bool valid = 1; int len = n;
		if (g[1] == 0 || g[2] == 0) return;
		int lst = a[g[1]];
		for (int i = 2; i <= n; i++) {
			if (g[i] == 0) {
				len = i-1; break;
			}
			if (abs(a[g[i]]-lst) > d) {
				valid = 0;
				break;
			}
			lst = a[g[i]];
		}
		if (valid) {
			cnt[g[1]][g[len]][len]++;
		}
		return;
	}
	g[step] = 0;
	dfs(step+1, true);
	if (mustbezero) return;
	for (int i = 1; i <= n; i++) {
		if (used[i]) continue;
		used[i] = 1;
		g[step] = i;
		dfs(step+1, false);
		used[i] = 0;
		g[step] = 0;
	}
}

void solve() {
	cin >> n >> d;
	memset(cnt, 0, sizeof(cnt));
	memset(used, 0, sizeof(used));
	memset(g, 0, sizeof(g));
	ans = 0;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (n <= 9) {
		dfs(1, false);
		ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i+1; j <= n; j++) {
				bool valid = 0;
				for (int len = 1; len <= 9; len++) {
					if (cnt[i][j][len] != 0) {
//						cout << i <<" " << j << " " << len << " " << cnt[i][j][len] <<endl;
						if (cnt[i][j][len] != 2) break;
						valid = 1;
						break;
					}
				}
				if (valid) ans += valid; 
			}
		}
		cout <<ans <<endl;
	}
}

signed main() {
	FILE("migrate"), DEBUG("migrate");
	cin.tie(0) -> sync_with_stdio(0);
	int c, t; cin >> c >> t;
	while (t--) solve();
//	CloseFILE, CloseDEBUG;
	return 0;
}

