#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 4e3;
const int inf = 1e9;
int C,T;
int n,k;
vector<int> G[maxn + 5];
int fa[maxn + 5],book[maxn + 5];
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
namespace Brute {
	int dis[maxn + 5];
	void calc(int u,int fa,int d) {
		if (dis[u] <= d) return ;
		dis[u] = d;
		for (int v : G[u]) {
			if (v == fa) continue;
			calc(v,u,d + 1);
		}
	}
	void main() {
		int ans = inf;
		for (int s = 0;s <= (1 << n) - 1;s ++) {
			for (int i = 1;i <= n;i ++) fa[i] = i;
			for (int i = 1;i <= n;i ++) book[i] = (s >> (i - 1)) & 1;
			int ncnt = 0;
			for (int u = 1;u <= n;u ++) {
				if (book[u]) {
					for (int v : G[u]) if (book[v]) fa[find(u)] = find(v);
					ncnt ++;
				}
			}
			if (ncnt != k) continue;
//			for (int i = 1;i <= n;i ++) if (book[i]) cout << i << " ";
//			cout << "::choose set\n";
			int cnt = 0;
			for (int i = 1;i <= n;i ++) if (book[i] && find(i) == i) cnt ++;
			if (cnt > 2) continue;
			for (int i = 1;i <= n;i ++) dis[i] = inf;
			for (int i = 1;i <= n;i ++) if (book[i]) calc(i,0,0);
			int res = 0;
			for (int i = 1;i <= n;i ++) res = max(res,dis[i]);
			ans = min(ans,res);
		}
		cout << ans << "\n";
	}
}
namespace ElainaA {
	int dis[maxn + 5][maxn + 5];
	void dfs(int u,int fa,int rt,int d) {
		dis[rt][u] = d;
		for (int v : G[u]) {
			if (v == fa) continue;
			dfs(v,u,rt,d + 1);
		}
	}
	void main() {
		for (int i = 1;i <= n;i ++) dfs(i,0,i,0);
		int ans = inf;
		for (int i = 1;i <= n;i ++) {
			for (int j = i + 1;j <= n;j ++) {
				int mx = 0;
				for (int k = 1;k <= n;k ++) mx = max(mx,min(dis[i][k],dis[k][j]));
				ans = min(ans,mx);
			}
		}
		cout << ans << "\n";
	}
}
int main() {
	ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> C >> T;
	while (T --) {
		cin >> n >> k;
		for (int i = 1;i <= n;i ++) G[i].clear();
		for (int i = 1;i <= n - 1;i ++) {
			int u,v; cin >> u >> v;
			G[u].push_back(v),G[v].push_back(u);
		}
		if (T <= 3) Brute::main();
		else ElainaA::main();
	}
	return 0;
}