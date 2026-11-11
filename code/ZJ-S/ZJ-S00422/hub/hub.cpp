#include<bits/stdc++.h>
//#define int long long
using namespace std;
int c,t,n,k,a[13],ans,dis[13][13],inf=1000000000,b[13],vis[13];
vector<int>mp[13];
void dfs3(int x,int la){
	vis[x]=1;
	for(int i=0;i<mp[x].size();i++){
		if(mp[x][i]==la||!a[mp[x][i]]) continue;
		dfs3(mp[x][i],x);
	}
}
void check(){
	for(int i=1;i<=n;i++) b[i]=inf,vis[i]=0;
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i]&&!vis[i]){
			cnt++;
			dfs3(i,0);
		}
	}
	if(cnt>2) return ;
	for(int i=1;i<=n;i++){
		if(a[i]){
			b[i]=0;
			for(int j=1;j<=n;j++) b[j]=min(dis[i][j],b[j]);
		}
	}
	int mx=0;
	for(int i=1;i<=n;i++) mx=max(mx,b[i]);
	ans=min(ans,mx);
}
void dfs(int x,int y){
	if(x==n+1){
		check();
		return ;
	}
	if(y<k) a[x]=1,dfs(x+1,y+1);
	a[x]=0;
	dfs(x+1,y);
}
int s;
void dfs2(int x,int la,int dep){
	dis[s][x]=dep;
	for(int i=0;i<mp[x].size();i++){
		if(mp[x][i]==la) continue;
		dfs2(mp[x][i],x,dep+1);
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;ans=inf;
		for(int i=1;i<n;i++){
			int u,v;cin>>u>>v;
			mp[u].push_back(v);
			mp[v].push_back(u);
		}
		for(int i=1;i<=n;i++) s=i,dfs2(i,0,0);
		dfs(1,0);
		cout<<ans<<"\n";
		for(int i=1;i<=n;i++) mp[i].clear();
	}
	return 0;
}

