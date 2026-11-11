#include <bits/stdc++.h>
#define max(a, b) a > b ? a : b
#define min(a, b) a < b ? a : b
#define inf 0x3f3f3f3f3f3f3f3f
#define ll long long
using namespace std;

int c, t, n, k;
int e[15][15];
int fa[15], vis[15], d[15][15];
ll ans;

int find(int x) {
	return (fa[x] = (x == fa[x] ? x : find(fa[x])));
}

int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	freopen("hub.in", "r", stdin);
//	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		ans = -inf;
		cin >> n >> k;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j) d[i][j] = inf;
		for (int i = 1; i <= n; ++i) {
			int u, v;cin >> u >> v;
			e[u][v] = e[v][u] = 1; e[u][u] = e[v][v] = 1;
			d[u][v] = d[v][u] = 1; d[u][u] = d[v][v] = 0;
		}
		
		for (int k = 1; k <= n; ++k) {
			for (int i = 1; i <= n; ++i) {
				for (int j = 1; j <= n; ++j)
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
		
		for (int S = 1; S < (1 << n); ++S) {
			for (int i = 0; i <= n; ++i) fa[i] = i;
			int Q = S, idx = 1;
			while (Q) {
				if (!(Q & 1)) vis[idx]=1;
				Q >>= 1; ++idx;
			}
			for (int i = 1; i <= n; ++i) {
				if (!vis[i])for (int j = 1; j <= n; ++j) {
					if (i != j && !vis[j] && e[i][j]) {
						fa[find(j)] = fa[find(i)];
						vis[j] = 1;
					}
				}
				vis[i] = 1;
			} int a = 0, b = 0; bool flag = 1;
			for (int i = 1; i <= n; ++i) {
				if (find(fa[i]) != i)
				if (find(fa[i]) != a) {
					if(!a) a = fa[i];
					else if (!b) b = fa[i];
					else if(b != fa[i]){
						flag = 0; break;
					}
				} else if (!b || find(fa[i]) != b) {
					if (!b) b = find(fa[i]);
					else {
						flag = 0; break;
					}
				}
			} if (flag) {
				Q = S, idx = 1;
				vector <int> anses;
				while (Q) {
					if (Q & 1) {
						anses.push_back(idx);
					} Q >>= 1, ++idx;
				} int len = anses.size(), ans_ = inf;
				
				for (int i = 1; i <= n; ++i) {
					for (int j = 0; j < len; ++j) {
						ans_ = min(ans_, d[i][anses[j]]);
					}
				} ans = max(ans, ans_);
			}
		} cout << ans << '\n';
	}
	return 0;
}