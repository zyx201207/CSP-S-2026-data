#include<bits/stdc++.h>
#define int long long

using namespace std;
typedef long long ll;

const int N = 2e6+5;
const int INF = 0x3f3f3f3f3f3f3f3f;
int n,d;
int x[N];
vector<int> g[N];
int dis[N],ans,is[N];
bool vis[N];

void bfs(int s) {
	queue<int> q;
	for(int i = 1; i <= n; ++i) dis[i] = INF,vis[i] = 0,is[i] = 0;
	q.push(s);
	dis[s] = 0;
	vis[s] = 1;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(int v:g[u]) {
			if(vis[v] && dis[v]==dis[u]+1) is[v]++;
			if(!vis[v]) {
				vis[v] = 1;
				dis[v] = min(dis[v],dis[u]+1);
				is[v]=1;
				q.push(v);
			}
			
		}
	}
	for(int i = 1; i <= n; ++i) {
		if(i!=s && is[i]==2) {
			ans++;
		}
	}
}

void solve() {
	ans = 0;
	cin >> n >> d;
	for(int i = 1; i <= n; ++i) g[i].clear();
	for(int i = 1; i <= n; ++i) {
		cin >> x[i];
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = i+1; j <= n; ++j) {
			if(x[j]-x[i] <= d) {
				g[i].push_back(j);
				g[j].push_back(i);
			}
		}
	}
	for(int i = 1; i <= n; ++i) {
		bfs(i);
	}
	cout << ans/2 << '\n';
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int c,t;
	cin >> c >> t;
	while(t--) {
		solve();
	}


	return 0;
}
