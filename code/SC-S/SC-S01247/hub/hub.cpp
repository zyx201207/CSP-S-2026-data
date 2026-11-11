#include <bits/stdc++.h>
#define E(i, l, r) for(int i = l; i <= r; ++ i)
#define D(i, r, l) for(int i = r; i >= l; -- i)
using namespace std;
const int N = 1E5 + 10;
int cc, tt;
int n, k, block, Min = N, dis[N], f[N];
vector <int> g[N];
bool use[N];

int gf(int x) {
	return x == f[x]? x: f[x] = gf(f[x]);
}

inline void mer(int x, int y) {
	int u = gf(x), v = gf(y);
	if(u ^ v) {
		-- block;
		f[u] = v;
	}
}

inline void dfs(int u, int fa) {
	for(int v: g[u]) {
		if(v ^ fa) dis[v] = min(dis[v], dis[u] + 1), dfs(v, u);
	}
}

inline void work1() {
	Min = N;
	E(I, 0, (1 << n) - 1) {
		E(i, 1, n) use[i] = (I >> (i - 1) & 1);
		if(__builtin_popcount(I) != k) continue;
		E(i, 1, n) f[i] = i;
		block = k;
		E(i, 1, n) dis[i] = N;
		E(i, 1, n) {
			for(int j: g[i]) {
				if(use[i] && use[j]) mer(i, j);
			}
			if(use[i]) dis[i] = 0;
		}
		
		if(block <= 2) {
			E(i, 1, n) if(!dis[i]) dfs(i, 0);
			int Max = 0;
			E(i, 1, n) Max = max(Max, dis[i]);
			Min = min(Min, Max);
			if(Max == 0) {
				E(i, 1, n) cerr << use[i] << " ";
				cerr << "\n";
			}
		}
	}
	cout << Min << "\n";
	return;
}

inline void work2() {
	E(v1, 1, n) E(v2, v1 + 1, n) {
		E(i, 1, n) dis[i] = N;
		queue <int> q;
		q.emplace(v1), q.emplace(v2);
		dis[v1] = dis[v2] = 0;
		while(!q.empty()) {
			int u = q.front();
			q.pop();
			
			for(int v: g[u]) {
				if(dis[v] < N) continue;
				dis[v] = dis[u] + 1;
				q.emplace(v);
			}
		}
		int Max = 0;
		E(i, 1, n) Max = max(Max, dis[i]);
		Min = min(Min, Max);
	}
	cout << Min << "\n";
	return;
}

inline void work() {
	E(i, 1, n) g[i].clear();
	Min = N;
	
	cin >> n >> k;
	E(i, 1, n - 1) {
		int u, v;
		cin >> u >> v;
		g[u].emplace_back(v), g[v].emplace_back(u);
	}
	
	if(cc <= 3) work1();
	else work2();
}

int main() {
	freopen("hub.in", "r", stdin), freopen("hub.out", "w", stdout);
	cin >> cc >> tt;
	while(tt --) work();
	return 0;
}