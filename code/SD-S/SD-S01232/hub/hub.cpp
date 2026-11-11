#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <vector>
#include <iomanip>
#define ll long long
using namespace std;
const int MAXN = 1e6 + 5;
const int INF = 1e9 + 5;
const int MOD = 1e9 + 7;

vector<int> E[MAXN], P;
bool vis[MAXN];
int n, k, F[505][505];
int ans = INF;

void Floyd() {
	for(int m = 1; m <= n; m ++) {
		for(int u = 1; u <= n; u ++) {
			for(int v = 1; v <= n; v ++) {
				if(u == v) continue ;
				if(F[u][m] == INF || F[m][v] == INF) continue ;
				F[u][v] = min(F[u][v], F[u][m] + F[m][v]);
			}
		}
	}
	return ;
}

int f[15];
int Find(int x) { return x == f[x] ? f[x] : f[x] = Find(f[x]); }
int C[15];

bool Check() {
	for(int i = 1; i <= n; i ++) f[i] = i;
	for(int i = 1; i <= n; i ++) {
		if(!vis[i]) continue ;
		for(auto v : E[i]) {
			if(!vis[v]) continue ;
			int Fv = Find(v), Fu = Find(i);
			f[Fu] = Fv; 
		}
	}
	for(int i = 0; i <= n; i ++) C[i] = 0;
	for(auto v : P) C[Find(v)] = 1;
	for(int i = 1; i <= n; i ++) C[0] += C[i];
	return (C[0] <= 2);
}

void Dfs(int now) {
	if(now == n + 1) {
		P.clear();
		for(int i = 1; i <= n; i ++) if(vis[i]) P.push_back(i);
		if((int)P.size() != k) return ;
		if(!Check()) return ;
		int tot = 0;
		for(int i = 1; i <= n; i ++) {
			if(vis[i]) continue ;
			int now = INF;
			for(auto v : P) now = min(now, F[i][v]);
			tot = max(tot, now);
		}
		ans = min(ans, tot);
		
		return ;
	}
	vis[now] = 1;
	Dfs(now + 1);
	vis[now] = 0;
	Dfs(now + 1);
	return ;
}

void Solve_1() {
	cin >> n >> k;
	ans = INF;
	for(int i = 1; i <= n; i ++) for(int j = 1; j <= n; j ++) F[i][j] = INF, vis[i] = false;
	for(int i = 1; i <= n; i ++) F[i][i] = 0;
	for(int i = 1; i < n; i ++) {
		int u, v; cin >> u >> v;
		E[u].push_back(v);
		E[v].push_back(u);
		F[u][v] = F[v][u] = 1;
	}
	Floyd();
	Dfs(1);
	for(int i = 1; i <= n; i ++) E[i].clear();
	cout << ans << "\n";
	return ;
}

int main() {

	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int c, t; cin >> c >> t;
	if(c <= 25) while(t --) Solve_1();
	 
	return 0;

}


