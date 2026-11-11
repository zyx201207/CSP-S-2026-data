#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2e6+10;
int c, t, n, d, x[N], dis[N], cnt[N], ans;
bool vis[N];
vector<int> g[N];

void bfs(int s){
	queue<int> q;
	memset(dis, 0x3f, sizeof dis);
	memset(vis, false, sizeof vis);
	memset(cnt, 0, sizeof cnt);
	q.push(s);
	dis[s] = 0;
	vis[s] = true;
	cnt[s] = 1;
	while(!q.empty()){
		int u = q.front(); q.pop();
		for (auto v: g[u]){
			if (vis[v]){
				if (dis[u]+1==dis[v]){
					cnt[v]++;
				}
			} else{
				vis[v] = true;
				dis[v] = dis[u]+1;
				cnt[v] = 1;
				q.push(v);
			}
		}
	}
	for (int i = s; i <= n; i++){
		if (vis[i] && cnt[i] == 2) ans++;
	}
}

void solve(){
	ans = 0;
	cin >> n >> d;
	for (int i = 1; i <= n; i++){
		cin >> x[i];
	}
	for (int i = 1; i <= n; i++){
		g[i].clear();
		for (int j = i+1; j <= n; j++){
			if (x[j]-x[i] <= d){
				g[i].push_back(j);
			} else{
				break;
			}
		}
	}
	for (int i = 1; i <= n; i++){
		bfs(i);
	}
	cout << ans << endl;
}

signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--){
		solve();
	}
	return 0;
}
