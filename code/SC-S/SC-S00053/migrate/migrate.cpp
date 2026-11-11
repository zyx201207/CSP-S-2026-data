#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 2e6 + 5;
int c, n, dis[N];
ll d, x[N], cnt[N];
bool vis[N];
vector<int> g[N];

void solve(){
	cin >> n >> d;
	for(int i = 1; i <= n; ++ i) cin >> x[i], g[i].clear();
	if(c > 10){
		cout << "0\n";
		continue;
	}
	for(int i = 1; i <= n; ++ i){
		for(int j = i + 1; j <= n; ++ j){
			if(x[j] - x[i] <= d){
//				cout << i << "--" << j << "\n";
				g[i].push_back(j);
				g[j].push_back(i);
			}
		}
	}
	ll ans = 0;
	for(int i = 1; i <= n; ++ i){
		queue<int> q;
		q.push(i);
		for(int j = 1; j <= n; ++ j) cnt[j] = 1, dis[j] = (int)1e9, vis[j] = 0;
		dis[i] = 0;
		while(!q.empty()){
			int u = q.front();
			q.pop();
			vis[u] = 1;
			for(int v : g[u]){
//				cout << u << "--->>" << v << "\n";
				if(dis[v] > dis[u] + 1){
					dis[v] = dis[u] + 1;
					if(!vis[v]) q.push(v);
				}
				else if(dis[v] == dis[u] + 1){
					cnt[v] += cnt[u];
				}
			}
		}
		for(int j = 1; j <= n; ++ j){
//			cout << "dis[" << j << "] = " << dis[j] << ", cnt[" << j << "] = " << cnt[j] << "\n";
			if(cnt[j] == 2) ++ ans;
		}
	}
	cout << ans / 2 << "\n";
}

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> c >> t;
	while(t --) solve();
	
	return 0;
}