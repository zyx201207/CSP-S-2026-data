#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1000;
const int INF = 1e9;
int C, T, n, ans, k, uu[N], vv[N], f[N], vis[N], b[N];
vector<int> e[N];

int find(int x){
	return f[x] == x ? x : f[x] = find(f[x]);
}

inline int c(){
	for(int i = 1;i <= n;++i) f[i] = i;
	for(int i = 1;i < n;++i){
		vis[i] = 0;
		int u = uu[i], v = vv[i];
		if(b[u] && b[v]) {
			int fx = find(u),fy = find(v);
			f[fx] = fy;
		}
	}
	vis[n] = 0;
	int cntt = 0;
	for(int i = 1;i <= n;++i){
		if(b[i]) {
			if(!vis[find(i)]) {
				vis[find(i)] = 1;
				cntt++;
			}
		}
	}
	return cntt <= 2;
}
int dfs2(int u,int fa) {
	if(b[u]) return 0;
	int res = INF - 10;
	for(int v : e[u]){
		if(v == fa) continue;
		res = min(res,dfs2(v,u) + 1);
	}
	return res;
}
int cnt = 0;
void dfs(int p) {
	if(p == n + 1) {
		if(cnt != k || !c()) return ;
		int px = 0;
		for(int i = 1;i <= n;++i){
			px = max(px,dfs2(i, 0));
		}
		ans = min(ans,px);
		return ;
	}
	b[p] = 1;
	++cnt;
	dfs(p + 1);
	--cnt;
	b[p] = 0;
	dfs(p + 1);
}

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> C >> T;
	while(T--){
		cin >> n >> k;
		ans = INF;
		for(int i = 1;i <= n;++i) e[i].clear();
		for(int i = 1;i < n;++i){
			int u,v;
			cin >> u >> v;
			uu[i] = u;
			vv[i] = v;
			e[u].emplace_back(v);
			e[v].emplace_back(u);
		}
		cnt = 0;
		dfs(1);
		cout << ans << '\n';
	}
	return 0;
}
