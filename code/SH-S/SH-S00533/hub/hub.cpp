#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
const int inf = 1e18;
int c, T, n, k;
vector<int> g[N];
int f[N], s[N];

void dfs(int u, int fa) {
	for(auto v : g[u]) {
		if(v == fa) continue;
		f[v] = min(f[v], f[u] + 1);
		dfs(v, u);
	}
}

void dfs2(int u, int fa, int st) {
	if((st >> (u - 1)) & 1) {
		if(s[fa] >= 1) s[u] = 1;
		else s[u] = 2;
	}
	for(auto v : g[u]) {
		if(v == fa) continue;
		dfs2(v, u, st);
	}
}

bool check(int st) {
	int cnt = 0;
	for(int i = 0; i < n; i++) if((st >> i) & 1) cnt++;
	if(cnt != k) return 0;
	for(int i = 1; i <= n; i++) s[i] = 0;
	dfs2(1, 0, st);
	int cnt2 = 0;
	for(int i = 1; i <= n; i++) if(s[i] == 2) cnt2++;
	return cnt2 <= 2;
}

void solve() {
	cin>>n>>k;

	for(int i = 1; i <= n; i++) g[i].clear();

	for(int i = 1; i < n; i++) {
		int u, v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	if(k == 2) {
		int ans = inf;
		for(int i = 1; i <= n; i++) {
			for(int j = i + 1; j <= n; j++) {
				for(int p = 1; p <= n; p++) f[p] = inf;
				f[i] = f[j] = 0;
				dfs(i, 0);
				dfs(j, 0);
				int res = 0;
				for(int i = 1; i <= n; i++) res = max(res, f[i]);
				ans = min(ans, res);
			}
		}
		cout<<ans<<"\n";
	} else if(n <= 20 && k <= 20) {
		int fu = (1 << n) - 1;
		int ans = inf;
		for(int st = 1; st <= fu; st++) {
			if(!check(st)) continue;
			int res = 0;
			for(int i = 1; i <= n; i++) f[i] = inf;
			for(int i = 1; i <= n; i++) if((st >> (i - 1) & 1)) f[i] = 0, dfs(i, 0);
			for(int i = 1; i <= n; i++) res = max(res, f[i]);
			ans = min(ans, res);
//			for(int i = 0; i < n; i++) cout<<((st >> i) & 1);
//			cout<<"  ";
//			for(int i = 1; i <= n; i++) cout<<f[i];
//			cout<<"\n";
		}
		cout<<ans<<"\n";
	}

}

signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--) solve();
	return 0;
}
