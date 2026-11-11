#include <bits/stdc++.h>
#define MAXN (1000010)
using namespace std;
int C, T;
int N, K;
const int INF = 100;
vector <int> G[MAXN];
bool choose[MAXN];
int ans = INF;
int dis[22];
bool vis[22];
int Bfs() {
	queue <int> Qu;
	for(int i=1;i<=N;i++) {
		if(choose[i]) {
			vis[i] = 1;
			dis[i] = 0;
			Qu.push(i);
		}else {
			vis[i] = 0;
			dis[i] = INF;
		}
	}
	int res = 0;
	while(!Qu.empty()) {
		int u = Qu.front();
		Qu.pop();
		res = max(res, dis[u]);
		//cout << u << " " << dis[u] << '\n';
		for(int v : G[u]) {
			if(!vis[v]) {
				dis[v] = dis[u] + 1;
				vis[v] = 1;
				Qu.push(v);
			}
		}
	}
	return res;
}
int par[MAXN];
int Find(int x) {
	if(par[x] == x) return x;
	else return par[x] = Find(par[x]);
}
bool used[MAXN];
void Dfs(int pos, int k) {
	if(pos > N) {
		if(k != K) return;
		int num = 0;
		memset(used, 0, sizeof used);
		for(int i=1;i<=N;i++) par[i] = i;
		for(int u=1;u<=N;u++) {
			if(!choose[u]) continue;
			int fu = Find(u);
			if(!used[u]) num ++;
			for(int v : G[u]) {
				if(choose[v]) {
					used[v] = 1;
					int fv = Find(v);
					if(used[v] && fu != fv) num --;
				}
			}
			used[u] = 1;
		}
		if(num > 2) return;
		ans = min(ans, Bfs());
		return;
	}
	if(k < K) {
		choose[pos] = 1;
		Dfs(pos+1, k+1);
	}
	choose[pos] = 0;
	Dfs(pos+1, k);
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> C >> T;
	while(T --) {
		cin >> N >> K;
		for(int i=1;i<=N;i++) {
			par[i] = i;
		}
			
		for(int i=1;i<N;i++) {
			int u, v;
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		Dfs(1, 0);
		cout << ans << '\n';
	}
	return 0;
}
/*
0 10
10 4
1 2
1 3
1 4
2 9
3 5
3 6
6 7
6 8
4 10

*/
