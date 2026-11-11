#include<bits/stdc++.h>
#define int long long
using namespace std;
int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while('0' > ch || ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while('0' <= ch && ch <= '9') {
		x = (x << 1) + (x << 3) + (ch & 15);
		ch = getchar();
	}
	return x * f;
} 
const int N = 5e5 + 5;
int C, T, n, k, fa[N][25], dep[N], fat[N];
bool vis[N];
inline int find(int u) {
	if(u == fat[u]) return u;
	return fat[u] = find(fat[u]);
}
vector<int> vt[N];
pair<int, int> a[N];
void init(int u, int father) {
	dep[u] = dep[father] + 1;
	fa[u][0] = father;
	for(int i = 1;i <= 20;++ i)
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for(int it : vt[u]) {
		if(it == father) continue;
		init(it, u);
	}
	return ;
} 
int dis(int u, int v) {
	int res = 0;
	if(dep[u] < dep[v]) swap(u, v);
	for(int i = 20;i >= 0;-- i)
		if(dep[fa[u][i]] >= dep[v]) {
			u = fa[u][i];
			res += (1 << i);
		}
	if(u == v) return res;
	for(int i = 20;i >= 0;-- i) {
		if(fa[u][i] != fa[v][i]) {
			u = fa[u][i];
			v = fa[v][i];
			res += (1 << (i + 1));
		} 
	}
	return res + 2;
}
inline Popcount(int u) {
	int t = 0;
	while(u) {
		++ t;
		u -= (u & (-u));
	}
	return t;
}
signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> C >> T;
	while(T --) {
		cin >> n >> k;
		for(int i = 1;i <= n;++ i) vt[i].clear(); 
		for(int i = 1, u, v;i < n;++ i) {
			cin >> u >> v;
			a[i] = {u, v};
			vt[u].push_back(v);
			vt[v].push_back(u);
		}
		init(1, 0);
		int res = 0x3f3f3f3f3f3f3f3f;
		for(int i = (1 << n) - 1;i >= 0;-- i) {
			if(Popcount(i) != k) continue;
			int Cnt = k;
			for(int j = 1;j <= n;++ j) {
				vis[j] = ((i >> (j - 1)) & 1);
				fat[j] = j;
			}
			for(int j = 1, u, v;j < n;++ j) {
				if(vis[a[j].first] && vis[a[j].second]) {
					u = find(a[j].first), v = find(a[j].second);
					if(u != v) fat[u] = v;
					-- Cnt;
				}
			}
			if(Cnt <= 2) {
				int rest = 0;
				for(int i = 1;i <= n;++ i) {
					if(vis[i]) continue;
					int Ct = 0x3f3f3f3f3f3f3f3f;
					for(int j = 1;j <= n;++ j) {
						if(!vis[j]) continue;
						Ct = min(Ct, dis(i, j));
					}
					rest = max(rest, Ct);
				}
				res = min(res, rest);
			}
		}
		cout << res << '\n';
	}
	return 0;
}
/*
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
