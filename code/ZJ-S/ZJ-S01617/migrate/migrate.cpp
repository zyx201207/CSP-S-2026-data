#include<bits/stdc++.h>
using namespace std;
#define ll long long;
typedef pair<int, int> PII;
const int N = 5e5 + 10;
int n, d, a[N], vis[N], dis[N], cnt[N], ans;
vector<int> g[N];
bool dij(int s, int t){
	priority_queue<PII, vector<PII>, greater<PII>> q;
	for(int i = 1;i <= n;i ++){
		vis[i] = 0;
		dis[i] = 0x3f;
		cnt[i] = 0;
	}
	dis[s] = 0;
	q.push({0, s});
	while(!q.empty()){
		int u = q.top().second;
		q.pop();
		if(vis[u] == 1) continue;
		vis[u] = 1;
		for(int v : g[u]){
			if(dis[v] > dis[u] + 1){
				cnt[v] = 0;
				dis[v] = dis[u] + 1;
				q.push({dis[v], v});
			}else if(dis[v] == dis[u] + 1){
				cnt[v] ++;
			}
		}
	}
	if(cnt[t] >= 2) return 1;
	else return 0;
}
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, T;
	cin >> c >> T;
	while(T --){
		cin >> n >> d;
		for(int i = 1;i <= n;i ++){
			cin >> a[i];
			g[i].clear();
		}
		for(int i = 1;i <= n;i ++){
			for(int j = i + 1;j <= n ;j ++){
				if(abs(a[i] - a[j]) <= d){
					g[i].push_back(j);
					g[j].push_back(i);
				}
			}
		}
		for(int i = 1;i <= n;i ++){
			for(int j = 1;j <= n && j != i;j ++){
				if(dij(i, j) == 1) ans ++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}