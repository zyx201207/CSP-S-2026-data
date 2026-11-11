#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int c, t, n, k, cnt, tot, d[N], sum[N], f[N], vis[N];
vector<int> st, g[N];

void dfs(int u, int fa, int x){
	f[u] = fa;
	for(int v : g[u]){
		if(v == fa){
			continue;
		}
		dfs(v, u, x);
		d[u] = max(d[u], d[v] + 1);
		sum[u] += sum[v];
	}
	if(d[u] >= x){
		cnt++;
		sum[u]++;
		d[u] = -1;
		vis[u] = 1;
	}
}

void Work(int u, int fa, int x){
	int son = 0;
//	cout << u << ' ' << x << '\n';
	for(int v : g[u]){
		if(v == fa){
			continue;
		}
		if(sum[v]){
			son++;
		}
	}
	if(son <= 1){
		if(x){
			tot += !vis[u];
		}
	}else{
		tot += !vis[u];
		x = 1;
	}
	if(vis[u]){
		x = 1;
	}
	for(int v : g[u]){
		if(v == fa){
			continue;
		}
		if(sum[v]){
			Work(v, u, x);
		}
	}
}

int Check(int x){
	cnt = 0;
	memset(d, 0, sizeof(d));
	memset(sum, 0, sizeof(sum));
	memset(vis, 0, sizeof(vis));
	dfs(1, 0, x);
//	cout << x << ' ' << cnt << '\n';
	if(cnt > k){
		return 0;
	}
	for(int i = 1; i <= n; ++i){
		tot = 0;
		Work(i, f[i], 0);
//		cout << x << ' ' << i << ' ' << tot << '\n';
		int ttt = sum[i];
		for(int j = i; j; j = f[j]){
			sum[j] -= sum[i];
		}
		Work(1, 0, 0);
//		cout << "# " << x << ' ' << i << ' ' << tot << ' ' << (cnt + tot) << '\n';
		if(cnt + tot <= k){
			return 1;
		}
		for(int j = i; j; j = f[j]){
			sum[j] += ttt;
		}
	}
	return 0;
}

void Solve(){
	cin >> n >> k;
	for(int i = 1; i <= n; ++i){
		g[i].clear();
		f[i] = 0;
	}
	for(int i = 1, u, v; i < n; ++i){
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int l = 0, r = n, ans = n;
	while(l <= r){
		int mid = (l + r) >> 1;
		if(Check(mid)){
			ans = mid;
			r = mid - 1;
		}else{
			l = mid + 1;
		}
	}
	cout << ans << '\n';
}

int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> c >> t;
	while(t--){
		Solve();
	}
	return 0;
}
/*
0 1
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
