#include<bits/stdc++.h>
#define N 1000010
using namespace std;
int T,n,k,u,v,rt,rr,l,r,x,sm,mx,ans,d[N],fa[N],f[N],fl[N],mk[N];
vector<int>e[N],vc[N];
void dfs1(int u){for(int v:e[u])if(v^fa[u])d[v]=d[u]+1,fa[v]=u,dfs1(v);}
void dfs2(int u,int fa){
	f[u]=1,fl[u]=0;
	for(int v:e[u])if(v^fa){
		dfs2(v,u);
		if(!fl[v])f[u]=max(f[u],f[v]+1);
		else if(!fl[u])fl[u]=fl[v];
	}if(f[u]>x)fl[u]=u;
}
void dfs3(int u,int fa){
	for(int v:e[u])if(v^fa){
		dfs3(v,u);
		if(fl[v])fl[u]=!fl[u]?fl[v]:u;
	}sm+=!!fl[u];
	if(fl[u]&&fl[u]^u)vc[fl[u]].push_back(x-f[u]);
}
bool chk(){
	dfs2(rt,0),sm=mx=0;
	for(int i=1;i<=n;i++)if(fl[i]==i)rr=i;else if(fl[i])fl[i]=0;
	dfs3(rr,0);
	for(int i=1;i<=n;i++)if(vc[i].size()){
		for(int j=0,k=0;j<vc[i].size();j++)u=vc[i][j],mk[j+u]=max(mk[j+u],j-u),mx=max(mx,j-k+1),k=max(k,mk[j]);
		for(int j=0;j<vc[i].size();j++)mk[j+vc[i][j]]=0;
		vc[i].clear();
	}return sm-mx<=k;
}
int main(){
	freopen("hub.in","r",stdin),freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	for(cin>>T>>T;T--;){
		cin>>n>>k,l=rt=1;
		for(int i=1;i<=n;i++)e[i].clear();
		for(int i=1;i<n;i++)cin>>u>>v,e[u].push_back(v),e[v].push_back(u);
		if(k==n){cout<<0<<"\n";continue;}
		d[1]=fa[1]=0,dfs1(1);
		for(int i=1;i<=n;i++)if(d[i]>d[u])u=i;
		d[u]=fa[u]=0,dfs1(u);
		for(int i=1;i<=n;i++)if(d[i]>d[rt])rt=i;
		r=d[rt]/2;
		for(int i=1;i<=r;i++)rt=fa[rt];
		for(;l<=r;)if((x=l+r>>1)&&chk())ans=x,r=x-1;else l=x+1;
		cout<<ans<<"\n";
	}
	return 0;
}
