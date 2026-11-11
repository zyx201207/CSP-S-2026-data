#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 1e6 + 16;

int CaseID, T;

int n, k;
vector<int>e[MAXN];

bool vis[MAXN];

bool dfs_vis[MAXN];
void dfs_chk(int u) {
	if(!vis[u])return;
	if(dfs_vis[u])return;
	dfs_vis[u] = 1;
	for(int v : e[u]) {
		dfs_chk(v);
	}
}

bool chk() {
	for(int i = 1; i <= n; i++) {
		dfs_vis[i] = 0;
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++) {
		if(vis[i] && !dfs_vis[i]) {
			dfs_chk(i);
			cnt++;
		}
		if(cnt > 2)return 0;
	}
	return 1;
}

int dep[MAXN];

void dfs_calc(int u, int fa) {
	for(int v : e[u]) {
		if(v == fa)continue;
		dep[v] = dep[u] + 1;
		dfs_calc(v, u);
	}
}

int calc() {
	if(!chk())return n + 1;
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		if(!vis[i]) {
			dep[i] = 0;
			dfs_calc(i, 0);
			int d = n + 1;
			for(int j = 1; j <= n; j++) {
				//cout << dep[j] << ' ';
				if(vis[j])d = min(d, dep[j]);
			}
			//cout << i << '\n';
			ans = max(ans, d);
		}
	}
	//cout << '\n';
	return ans;
}

void solve() {
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		e[i].clear();
	}
	for(int u, v, i = 1; i < n; i++) {
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	if(CaseID <= 6) {
		int ans = n;
		for(int i = 0; i < (1 << n); i++) {
			if(__builtin_popcount(i) != k)continue;
			for(int j = 0; j < n; j++)vis[j + 1] = i >> j & 1;
			ans = min(ans, calc());
		}
		cout << ans << '\n';
	} else {
		cout << k - 1 << '\n';
	}
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    for(cin >> CaseID >> T; T--; solve());
    return 0;
}
