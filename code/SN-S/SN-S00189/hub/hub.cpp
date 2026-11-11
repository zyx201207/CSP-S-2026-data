#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e6 + 5;

const int M = 25;

int C,T,n,m,de[N],id[N],tot,ans = 1e9,f[N][M];

vector<int> e[N];

bool vis[N];

void dfs(int u,int fa) {
	de[u] = de[fa] + 1;
	id[u] = ++tot;
	for(auto v : e[u]) {
		if(v == fa) continue;
		f[v][0] = u;
		for(int i = 1;i<=18;i++) f[v][i] = f[f[v][i - 1]][i - 1];
		dfs(v,u);
	}
}

int lca(int u,int v) {
	if(de[u] < de[v]) swap(u,v);
	int h = de[u] - de[v];
	for(int i = 0;i<=18;i++) if((h >> i) & 1) u = f[u][i];
	if(u == v) return u;
	for(int i = 18;i>=0;i--) if(f[u][i] != f[v][i]) u = f[u][i],v = f[v][i];
	return f[u][0];
}

void dfs1(int x,int sum) {
	if(x > n) {
		int num = 0;
		for(int i = 1;i<=n;i++) if(vis[id[i]] != vis[id[i]-1]) num++;
		num = (num + 1) / 2;
		if(num > 2) return;
		int cnt = 0;
		for(int i = 1;i<=n;i++) {
			for(int j = i+1;j<=n;j++) {
				if(vis[id[i]] || vis[id[j]]) continue;
				int l = lca(i,j);
				cnt = min(cnt,de[i] + de[j] - 2 * de[l]);
			}
		}
		ans = min(ans,cnt);
		return;
	}
	if(sum < m) {
		vis[id[x]] = true;
		dfs1(x+1,sum+1);
		vis[id[x]] = false;
	}
	dfs1(x+1,sum);
}

void solve() {
	cin >> n >> m;
	for(int i = 1;i<=n;i++) e[i].clear();
	memset(f,0,sizeof(f));
	memset(vis,0,sizeof(vis));
	memset(de,0,sizeof(de));
	memset(id,0,sizeof(id));
	ans = 1e9,tot = 0;
	for(int i = 1;i<n;i++) {
		int u,v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0);
	dfs1(1,0);
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> C >> T;
	while(T--) solve();
	return 0;
}
