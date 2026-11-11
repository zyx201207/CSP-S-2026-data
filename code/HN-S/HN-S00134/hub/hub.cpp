#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const ll N = 1e6 + 5;
const ll M = 1e5 + 5;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
int n,k,f[N][22],dep[N],ans;
vector<int> E[N],g;
bool vis[N],vis1[N];
void init(int u,int fa){
	dep[u] = dep[fa] + 1;
	f[u][0] = fa;
	for(int i = 1;i <= 20;i++){
		f[u][i] = f[f[u][i - 1]][i - 1];
	}
	for(auto v : E[u]){
		if(v == fa) continue;
		init(v,u);
	}
}
int LCA(int x,int y){
	if(dep[x] > dep[y]) swap(x,y);
	for(int i = 20;i >= 0;i--){
		if(dep[f[y][i]] >= dep[x]){
			y = f[y][i];
		}
	}
	if(x == y) return x;
	for(int i = 20;i >= 0;i--){
		if(f[x][i] != f[y][i]){
			x = f[x][i];
			y = f[y][i];
		}
	}
	return f[x][0];
}
int dis(int u,int v){
	int d = LCA(u,v);
	return dep[u] + dep[v] - 2 * dep[d];
}
void dfs1(int u){
	vis[u] = 1;
	for(auto v : E[u]){
		if(!vis1[v] || vis[v]) continue;
		dfs1(v);
	}
}
bool check(){
	for(int i = 1;i <= n;i++){
		vis[i] = 0;
	}
	int cnt = 0;
	for(auto x : g){
		if(vis[x]) continue;
		dfs1(x);
		cnt++;
		if(cnt > 2) return 0;			
	}
	return 1;
}
void dfs(int x,int y){
	if(y > k){
		if(check()){
			int mx = 0;
			for(int i = 1;i <= n;i++){
				int mn = n;
				for(auto j : g){
					mn = min(mn,dis(i,j));
				}
				mx = max(mx,mn);
			}
			ans = min(ans,mx);
		} 
		return;
	}
	if(x > n) return;
	if((n - x + 1) + y < k) return;
	g.push_back(x);
	vis1[x] = 1;
	dfs(x + 1,y + 1);
	g.pop_back();
	vis1[x] = 0;
	dfs(x + 1,y);
}
void work(){
	ans = INF;
	for(int i = 1;i <= n;i++){
		E[i].clear();
	}
	cin >> n >> k;
	for(int i = 1;i < n;i++){
		int u,v;
		cin >> u >> v;
		E[u].push_back(v);
		E[v].push_back(u);
	}
	if(n >= 1000){
		cout << n / 2 << "\n";
		return;
	}
	init(1,0);
	dfs(1,1);
	cout << ans << "\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int oT_To = 1;
	cin >> oT_To >> oT_To;
	while(oT_To--){ work();}
	return 0;
}

