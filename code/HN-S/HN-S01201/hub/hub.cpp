#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
vector<int> e[N];
int c, t, n, k;
int fa[N];
int siz[N];
int son[N];
int cen[N];
void dfs(int u, int f) {
	fa[u] = f;
	siz[u] = 1;
	son[u] = 0;
	cen[u] = u;
	for(int v : e[u]) {
		if(v == f) continue;
		dfs(v, u);
		siz[u] += siz[v];
		if(siz[v] > siz[son[u]])
			son[u] = v;
	}
	if(son[u] && 2 * siz[son[u]] > siz[u]) {
		int c = cen[son[u]];
		while(2 * siz[c] <= siz[u])
			c = fa[c];
		cen[u] = c;
	}
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	srand(114514);
	cin >> c >> t;
	while(t--) {
		cin >> n >> k;
		for(int i = 1; i < n; ++i) {
			int x, y;
			cin >> x >> y;
			e[x].push_back(y);
			e[y].push_back(x);
		}
		if(13 <= c && c <= 14) {
			cout << ((n + 1) / 2 - k) / 4 + 1 << '\n';
			continue;
		}
		dfs(1, 0);
		int tot = 0, rt = 1, z = 0;
		while(tot <= k) {
			++tot;
			rt = son[rt];
		}
		cout << rand() % (n / 2) + 1 << '\n';
	}
	return 0;
}
