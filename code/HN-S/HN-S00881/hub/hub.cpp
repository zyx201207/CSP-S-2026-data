#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int c , t , n , k , u[N] , v[N] , f[N][21] , dep[N] , fa[N] , minn = 1e9;
vector<int>g[N];
bool vis[N];
void dfs(int x , int fa){
	f[x][0] = fa;
	for(int i = 1;i <= 20;i++)f[x][i] = f[f[x][i - 1]][i - 1];
	dep[x] = dep[fa] + 1;
	for(int i : g[x]){
		if(i == fa)continue;
		dfs(i , x);
	}
}
int LCA(int x , int y){
	if(dep[x] < dep[y])swap(x , y);
	for(int i = 19;i >= 0;i--){
		if(dep[f[x][i]] >= dep[y])x = f[x][i];
	}
	if(x == y)return x;
	for(int i = 19;i >= 0;i--){
		if(f[x][i] == f[y][i])continue;
		x = f[x][i]; y = f[y][i];
	}
	return f[x][0];
}
int dist(int x , int y){
	int tmp = LCA(x , y);
	return dep[x] + dep[y] - 2 * dep[tmp];
}
int find(int x){
	if(fa[x] == x)return x;
	return fa[x] = find(fa[x]);
}
void dfs(int step){
	if(step > n){
		for(int i = 1;i <= n;i++)fa[i] = i;
		for(int i = 1;i < n;i++){
			if(!vis[u[i]] || !vis[v[i]])continue;
			int fx = find(u[i]) , fy = find(v[i]);
			if(fx == fy)continue;
			fa[fy] = fx;
		}
		int cnt = 0;
		for(int i = 1;i <= n;i++){
			if(vis[i] && fa[i] == i)cnt++;
		}
		if(cnt > 2)return;
		int ans = 0;
		for(int i = 1;i <= n;i++){
			int tmp = 1e9;
			for(int j = 1;j <= n;j++){
				if(i == j)continue;
				tmp = min(tmp , dist(i , j));
			}
			ans = max(ans , tmp);
		}
		minn = min(minn , ans);
		return;
	}
	vis[step] = true;
	dfs(step + 1);
	vis[step] = false;
	dfs(step + 1);
}
void sol(){
	minn = 1e9;
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		g[i].clear();
		for(int j = 0;j <= 20;j++)f[i][j] = 0;
		dep[i] = vis[i] = 0;
	}
	for(int i = 1;i < n;i++){
		int x , y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
		u[i] = x; v[i] = y;
	}
	dfs(1);
	cout << minn << '\n';
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	while(t--)sol();
	return 0;
}
