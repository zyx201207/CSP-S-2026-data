#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> adj[5010];
struct Node {
	int v,w;
};
int dis[5010],dd[5010],vis[5010];
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t--) {
		int n,d;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			adj[i].clear();
		}
		vector<int> a(n + 1);
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (a[j] - a[i] <= d) {
					adj[i].push_back(j);
					adj[j].push_back(i);
				} else {
					break;
				}
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dis[j] = 1e18;
				dd[j]  = 0;
			}
			queue<Node> q;
			q.push({i,0});
			dis[i] = 0;
			dd[i] = 1;
//				vis[i] = 1;
			while(!q.empty()) {
				int u = q.front().v,w = q.front().w;
				q.pop();
				for (int j = 0; j < adj[u].size(); j++) {
					int v = adj[u][j];
//						if (vis[v]){
//							continue;
//						}
//						vis[v] = 1;
					if (dis[v] > w + 1) {
						dis[v] = w + 1;
						dd[v] = dd[u];
						q.push({v,dis[v]});
//							vis[v] = 1;
					} else if (dis[v] == w + 1) {
						dd[v] += dd[u];
//							q.push({v,dis[v]});
					}
				}
			}
			for (int j = 1; j <= i; j++) {
				if (dd[j] == 2) {
					ans++;
//						cout << i << ' ' << j << '\n';
				}
//					cout << dd[j] << ' ';
			}
//				cout << '\n';
		}
		cout << ans << '\n';
	}
	return 0;
}
