#include<bits/stdc++.h>
#define int long long 
#define endl '\n'
using namespace std;
vector<int>e[10005],sol;
int dis[10005];
bool vis[10005];
inline int count____(int x){
	int cnt=0;
	while(x>0){
		cnt+=x&1;
		x>>=1;
	}
	return cnt;
}
int fa[10005];
inline int find(int x){
	if(!fa[x])return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
inline void unionn(int x,int y){
	x=find(x);
	y=find(y);
	if(x!=y){
		fa[x]=y;
	} 
}
inline void dfs(int x,int fa){
	if(vis[x])return;
	vis[x]=true;
	dis[x]=INT_MAX;
	for(int i=0;i<e[x].size();i++){
		if(e[x][i]==fa)continue;
		int u=e[x][i];
		dfs(u,x);
		dis[x]=min(dis[x],dis[u]+1);
	}
}
inline void solve(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	int ans=INT_MAX;
	for(int i=0;i<(1<<n);i++){
		int x=count____(i); 
		if(x!=k)continue;
		sol.clear();
		for(int j=0;j<n;j++){
			vis[j+1]=false;
			fa[j+1]=dis[j+1]=0;
			if((i>>j)^1)continue;
			sol.push_back(j+1);
			vis[j+1]=true;
		}
		for(int j=0;j<sol.size();j++){
			for(int k=0;k<e[sol[j]].size();k++){
				if(!vis[e[sol[j]][k]])continue;
				unionn(sol[j],e[sol[j]][k]);
			} 
		}
		int cnt=1;
		for(int j=1;j<sol.size();j++){
			if(find(sol[j])!=find(sol[j-1]))cnt++;
		}
		if(cnt>2)continue;
		int maxn=0;
		for(int j=1;j<=n;j++){
			if(vis[j])continue;
			dfs(j,0);
			maxn=max(maxn,dis[j]);
		}
		ans=min(ans,maxn);
	}
	cout<<ans<<endl;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		solve();
	} 
	return 0;
} 
