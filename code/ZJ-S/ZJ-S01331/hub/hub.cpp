#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k,ans,vis[1005],dis[1005],v[1005];
vector<int> g[1005];
void dfs(int x){
	vis[x]=1;
	for(int y:g[x]){
		if(vis[y]) continue;
		if(!v[y]) continue;
		dfs(y);
	}
}
void dfs2(int x,int s,int f){
	dis[x]=min(dis[x],s);
	for(int y:g[x]){
		if(y==f) continue;
		dfs2(y,s+1,x);
	}
}
void check(int s){
	if(s!=k) return;
	for(int i=1;i<=n;i++) vis[i]=0,dis[i]=0x3f3f3f3f;
	int cnt=0;
	for(int i=1;i<=n;i++) if(!vis[i]&&v[i]) dfs(i),cnt++;
	if(cnt>2) return;
	for(int i=1;i<=n;i++) if(v[i]) dfs2(i,0,0);
	int mx=0;
	for(int i=1;i<=n;i++) mx=max(mx,dis[i]);
	ans=min(ans,mx);
}
void dfs3(int x,int s){
	if(x>n){
		check(s);
		return;
	}
	v[x]=0,dfs3(x+1,s);
	v[x]=1,dfs3(x+1,s+1);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int type,T;
	cin>>type>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1,u,v;i<n;i++) cin>>u>>v,g[u].push_back(v),g[v].push_back(u);
		ans=0x3f3f3f3f;
		dfs3(1,0);
		cout<<ans<<endl;
	}
	return 0;
}