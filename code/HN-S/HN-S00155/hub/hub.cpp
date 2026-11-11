#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e6 + 2;
int n, k;
int U[N], V[N];
int degree[N];
int G[N << 1];

int fa[N][21], dep[N];
int p, q;
int l[N], lc;
bool in[N];
int maxd[N];

inline void dfs0(int u){
	dep[u] = dep[fa[u][0]] + 1;
	if(dep[u] > dep[q]) q = u;

	for(int i = degree[u], v; i < degree[u + 1]; ++ i){
		v = G[i];
		if(v == fa[u][0]) continue;
		fa[v][0] = u;
		dfs0(v);
	}
}

inline void dfs1(int u){
	dep[u] = dep[fa[u][0]] + 1;
	maxd[u] = dep[u];

	for(int i = degree[u], v; i < degree[u + 1]; ++ i){
		v = G[i];
		if(v == fa[u][0] || in[v]) continue;
		fa[v][0] = u;
		dfs1(v);
		maxd[u] = max(maxd[u], maxd[v]);
	}
}

bool use[N];

inline void dfs2(int u, int len){
	if(degree[u] + 1 == degree[u + 1]){
		for(int i = 20; i >= 0; -- i){
			if(len >> i & 1) u = fa[u][i];
		}
		use[u] = 1;
		return;
	}

	for(int i = degree[u], v; i < degree[u + 1]; ++ i){
		v = G[i];
		if(u != fa[v][0]) continue;
		dfs2(v, len);
	}
}

inline void dfs3(int u){
	for(int i = degree[u], v; i < degree[u + 1]; ++ i){
		v = G[i];
		if(u != fa[v][0]) continue;
		dfs3(v);
		use[u] |= use[v];
	}
}

inline bool check(int len){
	int L = 1 + len, R = lc - len, mid = L + R >> 1;
	for(int i = 1; i <= n; ++ i){
		use[i] = 0;
	}
	use[l[L]] = use[l[R]] = 1;

//	cout << "LR: " << L << ' ' << R << '\n';

	for(int i = L; i <= R; ++ i){
		dfs2(l[i], len);
		dfs3(l[i]);
	}
	for(int i = L; i <= mid; ++ i){
		int u = l[i];
		if(!use[u]){
			use[l[max(L, i - max(0, len - maxd[u] + 1))]] = 1;
		}
	}
	for(int i = mid + 1; i <= R; ++ i){
		int u = l[i];
		if(!use[u]){
			use[l[min(R, i + max(0, len - maxd[u] + 1))]] = 1;
		}
	}

	for(int i = mid; i > L; -- i){
		use[l[i - 1]] |= use[l[i]];
	}
	for(int i = mid + 1; i < R; ++ i){
		use[l[i + 1]] |= use[l[i]];
	}

	int cnt = 0;
	for(int i = 1; i <= n; ++ i){
		cnt += use[i];
	}
//	cout << lc << ' ' << k << ' ' << len << ' ' << cnt << '\n';

	return cnt <= k;
}

inline void solve(){
	cin >> n >> k;
	for(int i = 1; i < n; ++ i){
		cin >> U[i] >> V[i];
		++ degree[U[i]];
		++ degree[V[i]];
	}
	for(int i = 1; i <= n; ++ i){
		degree[i + 1] += degree[i];
	}
	for(int i = 1; i < n; ++ i){
		G[-- degree[U[i]]] = V[i];
		G[-- degree[V[i]]] = U[i];
	}

	q = 0, fa[1][0] = 0;
	dfs0(1);
	p = q, fa[p][0] = 0;
	dfs0(p);

	lc = 0;
	for(int u = q; ; u = fa[u][0]){
		l[++ lc] = u;
		in[u] = 1;
		if(u == p) break;
	}

	for(int i = 1; i <= lc; ++ i){
		fa[l[i]][0] = 0;
		dfs1(l[i]);
	}

	for(int j = 1; j <= 20; ++ j){
		for(int i = 1; i <= n; ++ i){
			fa[i][j] = fa[fa[i][j - 1]][j - 1];
		}
	}

	int L = 0, R = (lc - 1 >> 1), mid, ans = 1e9;
	while(L <= R){
		mid = L + R >> 1;
//		cout << "mid: " << mid << '\n';
		if(check(mid)){
			ans = mid;
			R = mid - 1;
		}
		else L = mid + 1;
	}
	cout << ans << '\n';
}

int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);

	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int _C, _T_;
	cin >> _C >> _T_;
	while(_T_ --){
		for(int i = 1; i <= n + 1; ++ i){
			degree[i] = 0;
			in[i] = 0;
		}
		solve();
	}

	return 0;
}

/*

g++ hub.cpp -o hub -std=c++14 -O2 -Wall
./hub

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