#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10,M=1010;
vector<int> e[N];
int siz[N],dep[N],mxd[N],fae[N],sz[N],to[N];
int n,k,tot;
int dfn[N],ti,vis[N],mxs[N],col[N];
void dfs(int u,int fa){
	sz[u]=1,fae[u]=fa,dfn[u]=++ti,to[dfn[u]]=u;
	for(auto v:e[u])if(v!=fa&&!vis[v]){
		dfs(v,u),sz[u]+=sz[v];
	};
}
void dfs1(int u,int fa){
	siz[u]=mxs[u]=1,dep[u]=mxd[u]=dep[fa]+1;
	for(auto v:e[u])if(v!=fa&&!vis[v]){
		dfs1(v,u),siz[u]+=siz[v],mxs[u]=max(mxs[u],siz[v]),mxd[u]=max(mxd[u],mxd[v]);
	}mxs[u]=max(mxs[u],tot-siz[u]);
}
void dfs2(int u,int fa){
	siz[u]=mxs[u]=1,dep[u]=mxd[u]=dep[fa]+1;
	for(auto v:e[u])if(v!=fa&&vis[v]){
		dfs2(v,u),siz[u]+=siz[v],mxs[u]=max(mxs[u],siz[v]),mxd[u]=max(mxd[u],mxd[v]);
	}mxs[u]=max(mxs[u],(n-tot)-siz[u]);
}
void dfs3(int u,int fa,int maxd){
	if(mxd[u]-dep[u]>=maxd) col[u]=1;
	for(auto v:e[u])if(v!=fa&&!vis[v]){
		dfs3(v,u,maxd);
	}
}
void dfs4(int u,int fa,int maxd){
	if(mxd[u]-dep[u]>=maxd) col[u]=1;
	for(auto v:e[u])if(v!=fa&&vis[v]){
		dfs4(v,u,maxd);
	}
}
bool check(int maxd){
	for(int i=2;i<=n;i++){
		tot=n;
		for(int j=dfn[i];j<dfn[i]+sz[i];j++) vis[to[j]]=1,tot--;
		dfs1(1,0),dfs2(i,fae[i]);
//		for(int j=1;j<=n;j++) cout<<j<<":"<<siz[j]<<" "<<mxs[j]<<endl;
		int g1,g2;for(int j=1;j<=n;j++)if(!vis[j]&&mxs[j]<=(tot)/2){g1=j;break;}
		for(int j=1;j<=n;j++)if(vis[j]&&mxs[j]<=(n-tot)/2){g2=j;break;}
//		cout<<g1<<" "<<g2<<endl; 
		dfs1(g1,0),dfs2(g2,0);
		dfs3(g1,0,maxd),dfs4(g2,0,maxd);
//		for(int j=1;j<=n;j++) cout<<j<<" "<<mxd[j]<<" "<<dep[j]<<endl;
//		for(int j=1;j<=n;j++) cout<<vis[i]<<endl;
//		cout<<"i "<<i<<" "<<tot<<" "<<g1<<" "<<g2<<" "<<maxd<<endl;
//		for(int j=1;j<=n;j++) cout<<col[j]<<" ";cout<<endl;
		int sum=0;for(int j=1;j<=n;j++) sum+=col[j],col[j]=0,vis[j]=0;
		if(sum<=k) return 1;
	}dfs1(1,0);int g1;for(int j=1;j<=n;j++)if(mxs[j]<=tot/2){g1=j;break;}
	dfs3(g1,0,maxd);int sum=0;for(int j=1;j<=n;j++) sum+=col[j];
//	cout<<"  ";
	for(int i=1;i<=n;i++) col[i]=0;
	if(sum<=k) return 1;
	return 0;
}
void solve(){
	cin>>n>>k;ti=0;
	for(int i=1;i<=n;i++) e[i].clear();
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v; 
		e[u].push_back(v),e[v].push_back(u);
	}dfs(1,0);
//	for(int i=1;i<=n;i++) cout<<"dfnsz"<<dfn[i]<<" "<<sz[i]<<endl;
	int l=0,r=n,mid,ans;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}cout<<ans<<endl;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--) solve();
	//Man 
	//What can I say
	//Manba out
	return 0;
}
/*
0 1
6 5
1 2
2 5
4 5
5 3
3 6
*/