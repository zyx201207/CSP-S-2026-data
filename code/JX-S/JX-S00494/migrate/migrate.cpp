#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
#define For(i, a, b) for (int i = (a); i <= (b); i++)
#define Rof(i, a, b) for (int i = (a); i >= (b); i--)
#define Fo(i, a) for (auto i : a)
#define fi first
#define se second
#define pb push_back
#define sr cin
#define sw cout
#define endl '\n'

const int N = 2000010, _ = 5010;
int c, T, pre[N], dp[N][2];
i64 x[N], res[N];
int dis[_][_];
i64 val[_][_];
vector<int> G[_];

void mika() {
	int n;
	i64 d;
	sr >> n >> d;
	int tmp = 1;
	For(i, 1, n) {
		sr >> x[i];
		while (x[i] - x[tmp] > d) tmp++;
		pre[i] = tmp;
	}
	x[n + 1] = 5e18, pre[n + 1] = n + 1;
	if (c <= 10) {
		For(i, 1, n) For(j, 1, n) dis[i][j] = 0x3f3f3f3f, val[i][j] = 0;
		For(i, 1, n) G[i].clear(), dis[i][i] = 0;
		For(i, 1, n) For(j, pre[i], i - 1) G[j].pb(i);
		For(i, 1, n) {
			queue<int> q;
			q.push(i);
			val[i][i] = 1;
			while (!q.empty()) {
				int t = q.front();
				q.pop();
				Fo(x, G[t]) {
					if (dis[i][x] > dis[i][t] + 1) {
						dis[i][x] = dis[i][t] + 1, val[i][x] = 0;
						q.push(x);
					}
					if (dis[i][x] == dis[i][t] + 1) val[i][x] += val[i][t];
				}
			}
		}
		i64 ans = 0;
		For(i, 1, n) For(j, 1, n) if (val[i][j] == 2) ans++;
		sw << ans << endl;
		return;
	}
	if (c == 11 || c == 12) {
		For(i, 1, n) {
			dp[i][0] = min(i, pre[i + 1]) - pre[i];
			dp[i][1] = 0;
			if (pre[i] == i) continue;
			dp[i][0] += (pre[i] != pre[i + 1]) * dp[pre[i]][0];
			dp[i][1] += (pre[i] != pre[i + 1]) * dp[pre[i]][1];
			if (pre[i] == i - 1) continue;
			dp[i][1] += (x[i + 1] - x[pre[i] + 1] > d) * dp[pre[i] + 1][0];
		}
		i64 ans = 0;
		For(i, 1, n) {
			res[i] = 0;
			if (pre[i] == i) continue;
			res[i] += dp[pre[i]][1];
			if (pre[i] == i - 1) continue;
			res[i] += dp[pre[i] + 1][0];
		}
		For(i, 1, n) ans += res[i] - res[pre[i]];
		sw << ans << endl;
		return;
	}
	if (c > 12) {
		For(i, 1, n) {
			dp[i][0] = min(i, pre[i + 1]) - pre[i];
			dp[i][1] = 0;
			if (pre[i] == i) continue;
			dp[i][0] += (pre[i] != pre[i + 1]) * dp[pre[i]][0];
			dp[i][1] += (pre[i] != pre[i + 1]) * dp[pre[i]][1];
			if (pre[i] == i - 1) continue;
			dp[i][1] += (x[i + 1] - x[pre[i] + 1] > d) * dp[pre[i] + 1][0];
		}
		i64 ans = 0;
		For(i, 1, n) {
			if (pre[i] == i) continue;
			ans += dp[pre[i]][1];
			if (pre[i] == i - 1) continue;
			ans += dp[pre[i] + 1][0];
		}
		sw << ans << endl;
		return;
	}
	// For(i, 1, n) sw << pre[i] << " ";
	// sw << endl;
	// For(i, 1, n) sw << dp[i][0] << " ";
	// sw << endl;
	// For(i, 1, n) sw << dp[i][1] << " ";
	// sw << endl;
	// For(i, 1, n) sw << res[i] - (x[i + 1] - x[pre[i] + 1] > d) * dp[pre[i]][0] << " ";
	// sw << endl;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	sr >> c >> T;
	while (T--) mika();
	return 0;
}