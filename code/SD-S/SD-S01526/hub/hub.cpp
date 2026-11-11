#include <bits/stdc++.h>
#define eb emplace_back
using namespace std;
const int N = 1e6 + 10;
int c, T, n, k;
int is[N], vis[N], res, mx, mn;
vector<int> e[N];
void dfs2(int u){
	vis[u] = 1;
	for(auto v : e[u]){
		if(is[u] && !vis[v]) dfs2(v);
	} 
}
void dfs3(int u, int dis){
	vis[u] = 1;
	if(is[u]) mn = min(mn, dis);
	for(auto v : e[u]){
		if(!vis[v]){
			dfs3(v, dis + 1);
		}
	}
}
void dfs(int x, int cnt){
	if(x == n + 1){
		if(cnt != k) return;
		for(int i = 1; i <= n; i++) vis[i] = 0;
		int b = 0;
		for(int i = 1; i <= n; i++){
			if(!vis[i] && is[i]) dfs2(i), b++;
		}
		if(b > 2) return;
		mx = 0;
		for(int i = 1; i <= n; i++){
			if(!is[i]){
				mn = n + 1;
				for(int j = 1; j <= n; j++) vis[j] = 0;
				dfs3(i, 0);
				mx = max(mx, mn);
			}
		}
		res = min(mx, res);
		return;
	}
	is[x] = 1;
	dfs(x + 1, cnt + 1);
	is[x] = 0;
	dfs(x + 1, cnt);
}
void solve1(){
	cin >> n >> k;
	for(int i = 1; i <= n - 1; i++){
		int u, v;
		cin >> u >> v;
		e[u].eb(v);
		e[v].eb(u);
	}
	for(int i = 1; i <= n; i++) is[i] = 0;
	res = n + 1;
	dfs(1, 0);
	cout << res << "\n";
}
signed main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin.tie(0);
	std::ios::sync_with_stdio(0);
	cin >> c >> T;
	while(T--){
		solve1();
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

在 十七岁
你太了解自己和我
我与你共通的软弱
青柑下我们相对而坐 

当 你说出 
关于生命所有错误
最夏天的词是残酷
形容质量的词是天赋 

*/
