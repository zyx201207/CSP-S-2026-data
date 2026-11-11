#include<bits/stdc++.h>
#define int long long 
#define endl "\n"
using namespace std;
const int N = 2e6 + 10;
int c,t,n,d,ans,a[N]; 
vector<pair<int,int>> edge[N];
int dis[N],vis[N],f[N];
void init1() {
	ans = 0;
	for(int i=1;i<=n;i++) {
		edge[i].clear();
	}
}
void init2() {
	for(int i=1;i<=n;i++) {
		dis[i] = 1e9 + 1;
		vis[i] = 0,f[i] = 0;
	}
}
void djikstra(int s) {
	init2();
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
	dis[s] = 0,f[s] = 1;
	q.push({0,s});
	while(!q.empty()) {
		int u = q.top().second;
		q.pop();
		if(vis[u]) {
			continue;
		}
		vis[u] = 1;
		for(auto i : edge[u]) {
			int to = i.first;
			int w = i.second;
			if(dis[u] + w < dis[to]) {
				dis[to] = dis[u] + w;
				f[to] = f[u];
				q.push({dis[to],to});
			}else if(dis[u] + w == dis[to]) {
				f[to] += f[u];
			}
		}
	}
}
void solve() {
	cin >> n >> d;
	init1();
	for(int i=1;i<=n;i++) {
		cin >> a[i];
	}
	for(int i=1;i<=n;i++) {
		for(int j=i+1;j<=n;j++) {
			if(abs(a[i] - a[j]) <= d) {
				edge[i].push_back({j,1});
			}
		}
	}
	for(int i=1;i<=n;i++) {
		djikstra(i);
		for(int j=i+1;j<=n;j++) {
			if(f[j] == 2) {
				ans++;
			}
		}
	}
	cout << ans << endl;
}
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios :: sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> c >> t;
	while(t--) {
		solve();
	}
	return 0;
}