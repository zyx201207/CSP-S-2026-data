#include<bits/stdc++.h>
using namespace std;

vector <int> e[1000005];
vector <vector <array <array <int,2>,3> > > f; 
int n,k,mid,mdep[1000005],fa[1000005],siz[1000005];

void dfs(int now){
	for (auto v : e[now]) if (v != fa[now])
		fa[v] = now, dfs(v),
		mdep[now] = !mdep[now] ? mdep[v] + 1 : min(mdep[now],mdep[v] + 1);
}

void calc(int now){
//	cerr << now << '\n';
	siz[now] = 1;
	if (mdep[now] <= mid)
		f[now][1][1][1] = 0;
	f[now][0][0][0] = mdep[now];
	for (auto v : e[now]) if (v != fa[now]){
		calc(v);
//		cerr << " care " << now << " - > " << v << '\n';
		vector <array <array <int,2>,3> > g = f[now];
		for (int i = 1;i <= min(siz[now] + siz[v],k);++i)
			for (int j = 1;j <= min(siz[v],k);++j){
				g[i][0][0] = max(f[now][i - j][0][0],f[v][j][0][0]);
				g[i][1][0] = min({
					max(f[now][i - j][1][0],f[v][j][0][0]),
					max(f[now][i - j][0][0],min(f[v][j][1][0],f[v][j][1][1])),
				});
				g[i][1][1] = min({
					max(f[now][i - j][1][1],f[v][j][1][1]),
					max(f[now][i - j][1][1],f[v][j][0][0])
				});
				g[i][2][0] = min({
					max(f[now][i - j][2][0],f[v][j][0][0]),
					max(f[now][i - j][1][0],min(f[v][j][1][0],f[v][j][1][1])),
					max(f[now][i - j][0][0],min(f[v][j][2][0],f[v][j][2][1]))
				});
				g[i][2][1] = min({
					max(f[now][i - j][2][1],f[v][j][0][0]),
					max(f[now][i - j][1][1],f[v][j][1][1]),
				});
//				g[now][i][1] = max(f[now][i - j][1],f[v][j][0]);
			}
		f[now] = g;
		siz[now] += siz[v];
	}
//	cout << " f " << now << " : \n";
}

bool check(){
	for (int i = 1;i <= n;++i) for (int j = 0;j <= k;++j) for (int l = 0;l < 3;++l) for (int p = 0;p < 2;++p)
		f[i][j][l][p] = n + 5;
	calc(1);
	int mn = n + 5;
	for (int i = 0;i < 3;++i) for (int j = 0;j < 2;++j)
		mn = min(mn,f[1][k][i][j]);
	return (mn <= mid);
}

void solve(){
	cin >> n >> k;
	f.resize(n + 5);
	for (int i = 1;i <= n;++i)
		f[i].resize(k + 5);
	for (int i = 1;i < n;++i){
		int u,v; cin >> u >> v;
		e[u].emplace_back(v);
		e[v].emplace_back(u);
	}
	dfs(1);
	int l = 1,r = n,ans;
	while (l <= r){
		mid = l + r >> 1;
//		cerr << mid << '\n';
		if (check()) r = mid - 1, ans = mid;
		else l = mid + 1;
	}
	cout << ans << '\n';
	for (int i = 1;i <= n;++i)
		e[i].clear(),
		mdep[i] = fa[i] = siz[i] = 0;
}

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout); 
	int TST,T; cin >> TST >>T;
	while (T--) solve();
}
// manba out
// zhui ji
// shu shang bei bao tiao bu chu lai le 
// ben lai gan jue hai ke yi you hua diao yi ge zuo dao O(nk) de
// jie guo xian zai zhe ge O(n^2 k) dou tiao bu chu lai
// kong bei qie