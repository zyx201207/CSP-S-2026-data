#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5, M = 2e5 + 5;
int n, m, a[N];
int fa[N], sz[N];
vector<int> g[M];
int get(int u) {
	if(u == fa[u]) return u;
	return fa[u] = get(fa[u]);
}
void merge(int u, int v) {
	int fu = get(u), fv = get(v);
	if(sz[fu] < sz[fv]) {
		fa[fu] = fv;
		sz[fv] += sz[fu];
	}
	else {
		fa[fv] = fu;
		sz[fu] += sz[fv];
	}
}
int ans[M];
int dgs[N], dge[N];
int rp[M], vis[M];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i=1; i<=n; ++i) cin >> a[i];
	for(int i=n; i>=1; --i){
		if(!vis[a[i]]) {
			vis[a[i]] = 1;
			rp[a[i]] = i;
		}
	} 
	for(int i=1; i<=n; ++i) {
		if(rp[i] != i) {
			dgs[i]++, dge[rp[i]]++;
		}
	}
	for(int i=1; i<=n; ++i) fa[i] = i, sz[i] = 1;
	for(int i=1; i<=n; ++i) {
		merge(i, rp[i]);
		if(rp[a[i]] == i) {
			ans[a[i]] = sz[get(i)];
		}
		merge(i - 1, i);
	}
	for(int i=1; i<=m; ++i) {
		cout << ans[i] << ' ';
	}
	return 0;
}
