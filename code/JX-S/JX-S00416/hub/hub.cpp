#include <bits/stdc++.h>
#define int long long
#define PII pair <int, int>
#define N 231
using namespace std;
const int INF = 2e18;
const int mod = 998244353;

int n, k;
vector <int> g[N];
bool flg[N];
bool vis[N];

void dfs(int u){
	vis[u] = 1;
	for(int v : g[u])
		if(!vis[v] && flg[v])
			dfs(v);
}

int mnd = INF;
void calc(int u, int fa, int dep){
	if(fa != 0 && flg[u])
		mnd = min(mnd, dep);
	for(int v : g[u]){
		if(v == fa) continue;
		if(dep + 1 > mnd) continue;
		calc(v, u, dep + 1);
	}
}

void solve(){
	cin >> n >> k;
	for(int i = 1; i <= n; i++) g[i].clear();
	for(int i = 1; i < n; i++){
		int u, v; cin >> u >> v;
		g[u].push_back(v); g[v].push_back(u);
	}
	int ans = INF;
	for(int I = 0; I < (1 << n); I++){
		if(__builtin_popcount(I) != k) continue;
		memset(flg, 0, sizeof flg);
		memset(vis, 0, sizeof vis);
		for(int i = 1; i <= n; i++)
			if(I >> (i - 1) & 1)
				flg[i] = 1;
		int cnt = 0;
		for(int i = 1; i <= n; i++){
			if(flg[i] && !vis[i]){
				cnt++;
				dfs(i);
			}
		}
		if(cnt > 2) continue;
		int res = 0;
		for(int i = 1; i <= n; i++){
			if(!flg[i]){
				mnd = INF;
				calc(i, 0, 0);
				res = max(res, mnd);
			}
		}
		ans = min(ans, res);
	}
	cout << ans << '\n';
}

signed main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int C, T = 1;
	cin >> C >> T;
	while(T--)
		solve();
	return 0;
}

// noooooooooo i forget that CSP-S lasts for 4h, i gonna get red 
// i can do few thing so that i should do nothing

