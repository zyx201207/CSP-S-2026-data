#include <bits/stdc++.h>
using namespace std;
int c, t;
int n, k;
int f[1000010][2];
int anc[1000010][21];
vector<int> g[1000010];

void init(int x, int pa){
	anc[x][0] = pa;
	for (int i = 1; i <= 20; i++){
		anc[x][i] = anc[anc[x][i-1]][i-1];
	}
	for (auto u : g[x]){
		if (u == pa) continue;
		init(u, x);
	}
}

void dfs(int x, int pa, int k){
	for (auto u : g[x]){
		if (u == pa) continue;
		dfs(u, x);
		f[x][0] += min(f[u][0], f[u][1]);
	}
}

bool check(int x){
	dfs(1, 0, x);
	return min(f[n][1], f[n][0]) <= x;
}

int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while (t--){
		cin >> n >> k;
		for (int i = 1; i < n; i++){
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		
		init(1, 0);
		int l = 0, r = n;
		while (l <= r){
			int mid = l + r >> 1;
			if (check(mid)) r = mid - 1;
			else l = mid + 1;
		}
		cout << l << endl;
	}
	return 0;
}
