#include <bits/stdc++.h>
using namespace std;
int c, t, n, d, a[5001], vis[5001], h[5001], ans;
vector<int>g[5001];
struct node{
	int n, s;
}u;
queue<node>q;
int main(){
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
	scanf ("%d%d" ,&c ,&t);
	while (t --){
		ans = 0;
		scanf ("%d%d" ,&n ,&d);
		for (int i = 1;i <= n;i ++){
			g[i].clear();
		}
		for (int i = 1;i <= n;i ++){
			scanf ("%d" ,&a[i]);
			for (int j = i - 1;j >= 1;j --){
				if (a[i] - a[j] <= d){
					g[i].push_back(j);
					g[j].push_back(i);
				} else {
					break;
				}
			}
		}
		for (int j = 1;j <= n;j ++){
			memset(vis, 0x3f, sizeof(vis));
			memset(h, 0, sizeof(h));
			q.push({j, 0});
			while (q.size()){
				u = q.front();
				q.pop();
				if (u.n > j || vis[u.n] < u.s){
					continue;
				}
				if (vis[u.n] > u.s){
					vis[u.n] = u.s;
					h[u.n] = 1;
				} else {
					h[u.n] ++;
				}
				for (int k = 0;k < g[u.n].size();k ++){
					q.push({g[u.n][k], u.s + 1});
				}
			}
			for (int k = 1;k <= j;k ++){
				if (h[k] == 2){
					ans ++;
				}
			}
		}
		printf ("%d\n" ,ans);
	}
	return 0;
}

