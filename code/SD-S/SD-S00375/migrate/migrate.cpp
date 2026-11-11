#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 2e6 + 5;

int c, t;
int n;
ll d;
ll dg[N];
ll a[N];
vector<int> g[N];
vector<ll> cnt[5005][5005];
ll ans;

void input() {
	cin >> n >> d;
	for (int i = 1; i <= n; i++) cin >> a[i];
}

void dfs(int s, int u, int fa, int dep) {
	for(int v : g[u]) {
		if (v == fa) continue;
		cnt[s][v].push_back(dep);
		dfs(s, v, u, dep + 1);
	} 
} 

void solve() {
	for (int i = 1; i <= n; i++) while (g[i].size()) g[i].pop_back();
	for (int j = 1; j <= n; j++)
		for (int i = 1; i <= n; i++) while (cnt[i][j].size()) cnt[i][j].pop_back();
	for (int i = 1; i <= n; i++) dg[i] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (a[j] - a[i] <= d) {
				g[i].push_back(j);
				dg[j]++;
			}
		}
	}
	for (int i = 1; i <= n; i++) dfs(i, i, i - 1, 1);
	ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			int wwz = 0;
			if (cnt[i][j].size()) {
				sort(cnt[i][j].begin(), cnt[i][j].end());
				for (int k = cnt[i][j][0]; k < cnt[i][j].size() - 1; k++) if (cnt[i][j][k] == cnt[i][j][k + 1]) wwz++;
			}
			if (wwz == 2) ans++;
		}
	cout << ans << '\n';
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> c >> t;
	while (t--) {
		input();
		if (c <= 10) {
			solve();
		}
	}
	
	return 0;
}
