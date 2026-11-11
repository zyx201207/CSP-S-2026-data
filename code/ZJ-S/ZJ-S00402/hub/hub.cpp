#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
vector<int> e[1000010];
bool vis[1000010];
int vis1[1000010];
long long da=1e18;
long long bfs(int sh){
	memset(vis1,0,sizeof(vis1));
	queue<int> q;
	vis1[sh]=1;
	q.push(sh);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(vis[u]) return vis1[u]-1;
		for(auto v:e[u]){
			if(!vis1[v]){
				vis1[v]=vis1[u]+1;
				q.push(v);
			}
		}
	}
}
void dfs(int u,int gs,int f,int po){
	if(gs==k){
		long long ans=0;
		for(int i=1;i<=n;i++){
			if(vis[i]) continue;
			ans=max(ans,bfs(i));
		}
		da=min(da,ans);
		return;
	}
	if(!vis[u] && po==2) return;
	for(auto v:e[u]){
		if(v==f) continue;
		vis[v]=1;
		if(vis[u]) dfs(v,gs+1,u,po);
		else dfs(v,gs+1,u,po+1);
		vis[v]=0;
		dfs(v,gs,u,po);
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> c >> t;
	while(t--){
		da=1e18;
		cin >> n >> k;
		for(int i=1;i<=n;i++) e[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		e[0].push_back(1);
		memset(vis,0,sizeof vis);
		dfs(0,0,-1,0);
		cout << da << '\n';
	}
	return 0;
}
