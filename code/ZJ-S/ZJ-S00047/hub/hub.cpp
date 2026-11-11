#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int inf=0x3f3f3f3f;
int c,T;
int n,k;
vector<int> g[1000005];
int fa[1000005],ft[1000000],dep[1000005];
void init(int u,int f){
	fa[u]=u;
	ft[u]=f;
	dep[u]=dep[f]+1;
	for(int v:g[u]){
		if(v!=f){
			init(v,u);
		}
	}
}
bool vis[1000005];
int dis[1000005];
int ans=inf;
void check(int u,int f){
	if(vis[u]==1){
		dis[u]=0;
		return;
	}
	dis[u]=inf;
	for(int v:g[u]){
		if(v==f) continue;
		check(v,u);
		dis[u]=min(dis[u],dis[v]+1);
	}
}
int Find(int u){
	if(fa[u]==u) return u;
	return Find(fa[u]);
}
bool Merge(int x,int y){
	x=Find(x),y=Find(y);
	if(vis[x]==0) return 0;
	if(vis[x]==1&&vis[y]==0) return 1;
	fa[x]=y;
	return 0;
}
void dfs(int x,int cnt){
	//cout<<x<<"|\n";
	if(cnt==k){
		int ck=0;
		for(int i=1;i<=n;i++){
			ck+=Merge(i,ft[i]);
		}
		if(ck>2) return;
		int nans=0;
		for(int i=1;i<=n;i++){
			check(i,0);
			nans=max(nans,dis[i]);
			fa[i]=i;
		}
		ans=min(ans,nans);
		return;
	}
	if(x>n) return;
	dfs(x+1,cnt);
	vis[x]=1;
	dfs(x+1,cnt+1);
	vis[x]=0;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//don't forget to delete!!!!!
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			//cout<<u<<"->"<<v<<'\n';
			if(n>k+1){
				g[u].push_back(v);
				g[v].push_back(u);
			}
		}
		if(n<=k+1){
			cout<<n-k<<'\n';
			continue;
		}
		//cout<<"Yes\n";
		init(1,0);
		dfs(1,0);
		cout<<ans<<'\n';
		for(int i=1;i<=n;i++){
			g[i].clear();
		}
		ans=inf;
	}
	return 0;
}