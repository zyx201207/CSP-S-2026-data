#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int c, t, n, sum[5005], dis[5005];
ll x[5005], d, ans;
bool vis[5005];
vector<int> g[5005];
queue<int> q;

void bfs(int s){
	memset(sum, 0, sizeof(sum));
	memset(dis, 0, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	vis[s] = 1;
	sum[s] = 1;
	while (!q.empty()){
		int u = q.front();
		q.pop();
		for (int i = 0; i < g[u].size(); i++){
			int v = g[u][i];
			if (vis[v] && dis[v] == dis[u] + 1) sum[v] += sum[u];
			if (!vis[v]){
				sum[v] = sum[u];
				vis[v] = 1;
				dis[v] = dis[u] + 1;
				q.push(v);
			} 
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	//
	cin >> c >> t;
	
	//
	while (t--){
		cin >> n >> d;
		ans = 0;
		for (int i = 1; i <= n; i++){
			cin >> x[i];
			g[i].clear();
		}
		for (int l = 1; l < n; l++){
			for (int r = l + 1; r <= n; r++){
				if (x[r] - x[l] <= d){
					g[l].push_back(r);
					g[r].push_back(l);
				}
				else break;
			}
		}
		for (int i = 1; i <= n; i++){
			q.push(i);
			bfs(i);
			for (int i = 1; i <= n; i++){
				if (sum[i] == 2) ans++;
				//cout << sum[i] << ' ';
			}
		//	cout << ans << '\n';
		}
		cout << ans / 2 << '\n';
	}
	
	//
	
	return 0;
}