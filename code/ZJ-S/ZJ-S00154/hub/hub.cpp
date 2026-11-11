#include<bits/stdc++.h>
using namespace std;
int C,T;
int n,k;
int ans;
bool vis[100010];
int viss[100010];
int dis[100010];
vector <int> e[100010];
void dfss(int u,int fa){
	for(int v:e[u])
		if(v!=fa)
			dis[v]=min(dis[u]+1,dis[v]),dfss(v,u);
	return;
}
void dfsss(int col,int u,int fa){
	for(int v:e[u])
		if(v!=fa&&vis[v])
			viss[v]=col,dfsss(col,v,u);
	return;
}
int f(){
	int ans=0;
	for(int i=0;i<=n;i++)
		viss[i]=0;
	for(int i=1;i<=n;i++)
		if(vis[i]&&viss[i]==0)
			dfsss(++viss[0],i,-1);
	if(viss[0]>2)	return INT_MAX;
	for(int i=1;i<=n;i++)
		dis[i]=INT_MAX;
	for(int i=1;i<=n;i++)
		if(vis[i])
			dis[i]=0,dfss(i,-1);
	for(int i=1;i<=n;i++)
		ans=max(ans,dis[i]); 
//	if(ans==1){for(int i=1;i<=n;i++)cout<<dis[i]<<" ";cout<<"\n";}
	return ans;
}
void dfs(int u,int sum){
	if(sum>k)	return;
	if(u==n){
		if(sum==k)
			ans=min(ans,f());
		return;
	}
	vis[u+1]=false;
	dfs(u+1,sum);
	vis[u+1]=true;
	dfs(u+1,sum+1);
	vis[u+1]=false;
	return;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>C>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)
			e[i].clear(),vis[i]=false;
		for(int i=1,u,v;i<n;i++) 
			cin>>u>>v,e[u].push_back(v),e[v].push_back(u);
		ans=INT_MAX;
		dfs(0,0);
		cout<<ans<<"\n";
	}
	return 0;
}//Baixie 0513DTY
//I often recall the past.
//100+32+24+15=171pts, How to get 1=?
//Qu(4) Nian(2) Jin(1) Ri(4), Bu(2) Ye(3) Shi(4) Ru(2) Ci(3) Shui(3) Ping(2)?
//I think I can't.
