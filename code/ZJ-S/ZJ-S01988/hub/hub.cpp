#include<bits/stdc++.h>
using namespace std;
#define int long long
int adj[5050][5050];
int n,k;
bool xz[5050];
int dis[5050][5050];
struct DSU{
	int fa[5050];
	void init(int n){
		for (int i = 0; i <= n; i++){
			fa[i] = i;
		}
	}
	int find(int x){
		if (x == fa[x]){
			return x;
		}
		return fa[x] = find(fa[x]);
	}
	void merge(int x,int y){
		int u = find(x),v = find(y);
		if (u != v){
			fa[u] = v;
		}
	}
};
int ans = 1e9;
void dfs(int t,int y){
	if (y == k){
		vector<int> a;
		for (int i = 1; i <= n; i++){
			if(xz[i]){
				a.push_back(i);
			}
		}
		DSU dsu;
		dsu.init(n);
		for (int  i = 0; i < a.size(); i++){
			for (int j =  i + 1; j < a.size(); j++){
				if (adj[a[i]][a[j]]){
					dsu.merge(a[i],a[j]);
				}
			}
		}
		int a1 = 0,a2 = 0;
		for (int i = 0; i < a.size(); i++){
			if (dsu.fa[a[i]] != a1 && dsu.fa[a[i]] != a2){
				if (!a1){
					a1 = dsu.fa[a[i]];
				}
				else if (!a2){
					a2 = dsu.fa[a[i]];
				}
				else{
					return;
				}
			}
		}
//		for (int i = 0; i < a.size(); i++){
//			cout << a[i] << ' ';
//		}
//		cout << '\n';
		int maxn = 0;
		for (int i = 0; i < a.size(); i++){
			int minn = 1e9;
			for (int j = i + 1; j < a.size(); j++){
				minn = min(minn,dis[a[i]][a[j]]);
			}
			maxn = max(maxn,minn);
		}
		ans = min(maxn,ans);
		return;
	}
	if (t > n){
		return;
	}
	xz[t] = true; 
	dfs(t + 1, y + 1);
	xz[t] = false;
	dfs(t + 1,y);
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t--){
		cin >> n >> k;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				adj[i][j] = 0;
			}
		}
		memset(xz,0,sizeof xz);
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				dis[i][j] = 1e9;
			}
		}
		for (int i = 1; i <= n; i++){
			dis[i][i] = 0;
		}
		for (int i = 1; i < n; i++){
			int u,v;
			cin >> u >> v;
			adj[u][v] = adj[v][u] = 1;
			dis[u][v] = 1;
		}
		for (int k = 1; k <= n; k++){
			for (int i = 1; i <= n; i++){
				for (int j = 1; j <= n; j++){
					dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
				}
			}
		}
		dfs(1,0);
		cout << ans << '\n';
	}
	return 0;
}
