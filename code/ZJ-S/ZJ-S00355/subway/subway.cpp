#include <bits/stdc++.h>

using namespace std;

const int N = 2e4 + 10, M = 1080;
int c, n, m, d, q, k, u, v, op;
int a[N], t[N], e[M][M];
int dis[N], vis[N], w[N];

int spfa(int st, int end){
	queue <int> q;
	memset(dis, 0x3f, sizeof dis);
	vis[st] = 1;q.push(st);dis[st] = 0;
	
	while(!q.empty()){
		int x = q.front();q.pop();
		vis[x] = 0;
		for(int i = 1;i <= m;i ++){
			if(e[x][i] + dis[x] < dis[i]){
				dis[i] = e[x][i] + dis[x];
				if(!vis[i]) q.push(i), vis[i] = 1;
			}
		}
	}
	return dis[v];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	memset(e, 0x3f, sizeof e);
	for(int i = 1;i <= m;i ++) e[i][i] = 0;

	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i ++) cin >> w[i];
	for(int i = 1;i <= n;i ++){
		cin >> op;
		memset(t, 0x3f, sizeof t);
		for(int j = 1;j <= op;j ++){
			cin >> a[j] >> t[j];
		}
		for(int j = 1;j <= op;j ++){
			for(int k = j;k <= op;k ++){
//				cout << a[j]<<" "<< a[k] << " "<<t[k] << "\n";
				e[a[j]][a[k]] = min(e[a[j]][a[k]], t[j] + t[k]);
//				cout << a[j]<<" "<< a[k] << " "<<t[k] << "\n";
				e[a[k]][a[j]] = min(e[a[k]][a[j]], t[j] + t[k]);
			}
		}
	}
	while(q --){
		cin >> u >> v;
		cout << spfa(u, v) + w[u] + w[v] << "\n";	
	}
	return 0;
}
