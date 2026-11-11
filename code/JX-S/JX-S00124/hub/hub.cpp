#include<bits/stdc++.h>
using namespace std;
vector<int>g[1000050];
int n,k,mn=1e9;
bool vis[100005];
int fa[1005];
int find(int x){
	if(fa[x]==x)return fa[x];
	else return fa[x]=find(fa[x]);
}
int dis[1005];
void dfs(int u,int fa){
	//cout<<"a\n";
	for(int i=0;i<(int)g[u].size();i++){
		if(g[u][i]==fa||vis[g[u][i]])continue;
		dis[g[u][i]]=min(dis[g[u][i]],dis[u]+1);
		dfs(g[u][i],u);
	}
}
void solve(){
	mn=1e9;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		g[i].clear();
	}
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=0;i<(1<<n)-1;i++){
		for(int j=1;j<=n;j++)vis[j]=0;
		int p=i,c=0,t=0;
		while(p!=0){
			t++;
			if(p&1)c++,vis[t]=1;
			p/=2;
		}
		
		if(c!=k){
			for(int j=1;j<=n;j++)vis[j]=0;
			continue;
		}
		for(int j=1;j<=n;j++)fa[j]=j;
		//cout<<i<<'\n';
		for(int j=1;j<=n;j++){
			if(vis[j]){
				for(int e=0;e<(int)g[j].size();e++){
					if(vis[g[j][e]]){
						//cout<<j<<' '<<g[j][e]<<'\n';
						fa[find(g[j][e])]=find(j);
					}
				}
			}
			
		}
		for(int j=1;j<=n;j++){
			//cout<<find(j)<<'\n';
			if(find(j)==j)p++;
		}
		if(p!=n-k+2){
			for(int j=1;j<=n;j++)vis[j]=0;
			continue;
		}
		for(int j=1;j<=n;j++)dis[j]=1e9;
		for(int j=1;j<=n;j++){
			if(vis[j]){
				dis[j]=0;
			dfs(j,0);
		}
		}
		int mx=0;
		for(int j=1;j<=n;j++)mx=max(dis[j],mx);
		if(mx<mn){
			//cout<<i<<'\n';
			mn=mx;
		}
		for(int j=1;j<=n;j++)vis[j]=0;
		
	}
	cout<<mn<<'\n';
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}
