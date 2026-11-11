#include<bits/stdc++.h>
#define int long long 
#define endl "\n"
using namespace std;
const int N = 5050;
int c,t,n,k,ans,dis[N][N];
vector<int> edge[N];
void init() {
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			dis[i][j] = 1e18 + 1;
		}
	}
}
void floyd() {
	for(int k=1;k<=n;k++) {
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) {
				if(i == j)continue;
				dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
			}
		}
	}
}
void solve() {
	init();
	cin >> n >> k;
	init();
	for(int i=1;i<n;i++) {
		int u,v;
		cin >> u >> v;
		dis[u][v] = dis[v][u] = 1;
	}
	floyd();
	vector<int> res;
	for(int i=1;i<=n;i++) {
		sort(dis[i] + 1,dis[i] + n + 1);
		res.push_back(dis[i][1]);
	}
	sort(res.begin(),res.end(),greater<int>());
	cout << res[k] << endl;
}
signed main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios :: sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> c >> t;
	while(t--) {
		solve();
	}
	return 0;
}