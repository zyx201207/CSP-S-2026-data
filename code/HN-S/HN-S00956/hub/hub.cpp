#include<bits/stdc++.h>
//#define int long long
#define fore(i,a,b) for(int i=(a);i<=(b);++i)
#define repe(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N = 40;
int c, T;
int n, k;
bool p[N];
vector<int> G[N];
int ans;
int fa[N], dep[N];
int dist(int u,int v) {
	int res = 0;
	while(u != v) {
		if(dep[u] > dep[v]) {
			res ++;
			u = fa[u];
		} else {
			res ++;
			v = fa[v];
		}
	}
	return res;
}
int H() {
	int res = 0;
	fore(i, 1, n) {
		if(p[i]) continue;
		int Dis = 1e18;
		fore(j, 1, n) {
			if(p[j] == 0) continue;
			Dis = min(Dis, dist(i, j));
		}
		res = max(res, Dis);
	}
	return res;
}
int scc[N];
void chdfs(int u) {
	bool flag = 0;
	for(int v : G[u]) {
		if(v == fa[u]) continue;
		chdfs(v);
		scc[u] += scc[v];
		if(p[v]) flag = 1;
	}
	if(p[u] && flag == 0) {
		scc[u] ++;
	}
}
bool ch() {
	int cnt = 0;
	fore(i, 1, n) cnt += p[i];
	if(cnt != k) return false;
	fore(i, 1, n) scc[i] = 0;
	chdfs(1);
	if(scc[1] > 2) return false;
	return true;
}
void dfs(int x) {
	if(x == n + 1) {
		if(ch()) ans = min(ans, H());
		return;
	}
	p[x] = 0;
	dfs(x + 1);
	p[x] = 1;
	dfs(x + 1);
}
void init(int u,int fat) {
	fa[u] = fat;
	dep[u] = dep[fat] + 1;
	for(int v : G[u]) {
		if(v == fat) continue;
		init(v, u);
	}
}
void Clear() {
	ans = 1e18;
	dep[0] = 0;
	fore(i, 1, n) {
		G[i].clear();
		fa[i] = dep[i] = 0;
		p[i] = 0;
	}
}
void Main() {
	cin >> n >> k;
	Clear();
	fore(i, 2, n) {
		int u, v; cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	init(1, 0);
	dfs(1);
	cout << ans << '\n';
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> T;
	while(T --) Main();
	return 0;
}
/*

0 3
8 6
4 8
5 8
6 3
3 2
2 1
1 8
7 8
6 5
1 2
2 5
4 5
5 3
3 6
9 3
1 2
2 8
4 7
6 5
7 9
8 5
5 3
3 9



0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/
