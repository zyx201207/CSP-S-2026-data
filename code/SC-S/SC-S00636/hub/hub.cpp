#include<bits/stdc++.h>
#define int long long
using namespace std;
using pii = pair<int,int>;
const int INF = 0x3f3f3f3f3f3f3f3f;
int c,t,n,k,ans = INF;
vector<bool> vis;
vector<vector<int>> g;
struct DSU{
	vector<int> fa;
	DSU(int m) : fa(m + 1){
		for(int i = 1;i <= m;i++){
			if(vis[i] == true){
				fa[i] = i;
			}
			else{
				fa[i] = -1;
			}
		}
	}
	int find(int m){
		return fa[m] == m ? m : fa[m] = find(fa[m]);
	}
	void merge(int x,int y){
		int fx = find(x),fy = find(y);
		if(fx != fy){
			fa[fx] = fy;
		}
	}
	int size(){
		int cnt = 0;
		for(int i = 1;i <= n;i++){
			if(fa[i] == i){
				cnt++;
			}
		}
		return cnt;
	}
};
void dfs(int siz){
	if(siz >= k){
		DSU d(n);
		for(int i = 1;i <= n;i++){
			if(vis[i] == true){
				for(int j : g[i]){
					if(vis[j] == true){
						d.merge(i,j);
					}
				}
			}
		}
		if(d.size() <= 2){
			int mx = -INF;
			for(int i = 1;i <= n;i++){
				if(vis[i] == false){
					priority_queue<pii,vector<pii>,greater<pii>> pq;
					vector<int> dist(n + 1,INF);
					vector<bool> viss(n + 1,false);
					pq.push({dist[i] = 0,i});
					while(pq.empty() == false){
						pii a = pq.top();
						pq.pop();
						int var = a.second;
						if(viss[var] == true){
							continue;
						}
						viss[var] = true;
						for(int b : g[var]){
							if(dist[b] > dist[var] + 1){
								pq.push({dist[b] = dist[var] + 1,b});
							}
						}
					}
					int mn = INF;
					for(int j = 1;j <= n;j++){
						if(vis[j] == true){
							mn = min(mn,dist[j]);
						}
					}
					mx = max(mx,mn);
				}
			}
			ans = min(ans,mx);
		}
		return;
	}
	for(int i = 1;i <= n;i++){
		if(vis[i] == false){
			vis[i] = true;
			dfs(siz + 1);
			vis[i] = false;
		}
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(nullptr) -> ios::sync_with_stdio(false);
	cin >> c >> t;
	while(t--){
		cin >> n >> k;
		vis.resize(n + 1);
		g.resize(n + 1);
		for(int i = 1;i < n;i++){
			int u,v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(0);
		cout << ans << '\n';
	}
	return 0;
}