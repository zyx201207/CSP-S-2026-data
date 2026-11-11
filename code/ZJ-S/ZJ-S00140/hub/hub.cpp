#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 +100;
int f[400][400];
int x[N];
int n,k;
bool vis[20];
int fa[20];
vector<int> g[20];
int find(int x){
	if(x == fa[x] ) return x;
	return fa[x] = find(fa[x]);
}
int d[20];
int maxn;
int ans;
int c ,t;
void ldfs(int u,int ff,int dep){

	for(int v:g[u]){
		if(v == ff) continue;
		if(vis[v]) d[v] = 0;
		else d[v] = min(dep + 1,d[v]);

		ldfs(v,u,dep + 1);
	} 
}
void check(){
	for(int i = 1;i <= n;i++){
		fa[i] = i;
		d[i] = 1e18;
	}
	int tot = k;
	for(int i = 1;i <= n;i++){
		if(vis[i]){

			for(int v : g[i]){
				if(vis[v]){
			
					int ru = find(i) , rv = find(v);
					if(ru == rv) continue;
					fa[ru] = rv;
					tot--;
				}
			}
		}
	}

	if(tot > 2) return ;

	maxn = -1;
	for(int i = 1;i <= n;i++){
		if(vis[i])  ldfs(i,0,0);
	}
	for(int i = 1;i <= n;i++) maxn = max(maxn,d[i]);
	
	if(maxn > 0) ans = min(ans , maxn);
}

void dfs(int x,int p){
	if(p == k){
	
		check();
		return ;
	}
	if(x > n) return ;
	vis[x] = true; 
	dfs(x + 1,p + 1);
	vis[x] = false;
	dfs(x + 1,p);
	
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> c >> t;
	if(c <= 20){
		while(t--){
	
			ans = 1e9;
			cin >> n >> k;
			for(int i =1;i <= n;i++){
				vis[i] = false;
				g[i].clear();
			}
			for(int i = 1;i < n;i++){
				int u,v;
				cin >> u >> v;
				g[u].push_back(v);
				g[v].push_back(u);
			}
			dfs(1,0);
			cout << ans <<"\n";
		}
	}
	
	return 0;
}
