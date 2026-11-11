#include <bits/stdc++.h>
using namespace std;
int a[50005];
int n, d;
#define pii pair <int, int>
int v[500005];
int vis[500005];
queue <pii> q;
vector <pii> g[500005];
int flag[505][505];
int cnt;
void dij(int xx, int yy){
	memset(vis, 0x3f, sizeof(vis));
	memset(flag, 0, sizeof(flag));
	q.push({xx, 0});
	vis[xx] = 0;
	while(!q.empty()){
		pii u = q.front();
		q.pop();
		if (vis[u.first] < u.second){
			continue;
		}
		for (pii v : g[u.first]){
			if (u.first == v.first){
				continue;
			}
			if (v.second > d){
				continue;
			}
			int ntime = vis[u.first] + v.second;
			if (ntime == vis[v.first] && flag[u.first][v.first] == 0){
				cnt++;
				flag[u.first][v.first] = 1;
			}else if(ntime == vis[v.first] && flag[u.first][v.first] == 1){
				cnt--;
				flag[u.first][v.first] = 2;
			}
			if (ntime < vis[v.first]){
				if (flag[u.first][v.first] == 1){
					cnt--;
				}
				
				flag[u.first][v.first] = 0;
				q.push({v.first, ntime});
				vis[v.first] = ntime;
			}
		}
	}
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;

	while(t--){
		
		cin >> n >> d;
		for (int i = 1; i <= n; i++){
			cin >> a[i];
		}
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				if (i == j){
					continue;
				}
				g[i].push_back({j, abs(a[i] - a[j])});
				g[j].push_back({i, abs(a[j] - a[i])});
			}
		}
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				if (i == j){
					continue;
				}
				dij(i, j);
			}
		}
		cout << cnt <<'\n';
	}
	
	return 0;
}
