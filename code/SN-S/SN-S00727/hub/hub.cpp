#include<bits/stdc++.h>
#define N 200005
#define mod 998244353
#define il inline
#define ll long long
using namespace std;
namespace xzz{
bool beg;
int T=1;
int n,m,k,st[N][20],son[N],siz[N],mx,c[N],dep[N];
vector<int> e[N];
int kth(int u,int k){
	for(int i=19;i>=0;i--){
		if((k>>i)&1)	u=st[u][i];
	}
	return u;
}
int lca(int u,int v){
	if(dep[u]<dep[v])	swap(u,v);
	for(int i=19;i>=0;i--){
		if(dep[st[u][i]]>=dep[v])	u=st[u][i];
	}
	if(u==v)	return u;
	for(int i=19;i>=0;i--){
		if(st[u][i]!=st[v][i])	u=st[u][i],v=st[v][i];
	}
	return st[u][0];
}
void dfs(int u,int f){
	st[u][0]=f,siz[u]=1,dep[u]=dep[f]+1;
	for(int i=1;i<20;i++)	st[u][i]=st[st[u][i-1]][i-1];
	for(auto v:e[u]){
		if(v==f)	continue;
		dfs(v,u),siz[u]+=siz[v];
		if(siz[v]>=siz[son[u]])	son[u]=v;
	}
}
void solve(int u,int f){
	for(auto v:e[u]){
		if(v==f)	continue;
		solve(v,u),siz[u]+=siz[v];
	}
}
bool check(){
	mx=0;
	for(int i=1;i<=n;i++)	siz[i]=0;
	for(int i=1;i<=n;i++)	siz[i]++,siz[kth(i,m+1)]--;
	solve(1,0);
	for(int i=1;i<=n;i++){
		int x=kth(i,m+2),y=kth(i,m*2+1);
		if(m+2>2*m+1)	continue;
		while(x!=y){
			mx=max(mx,siz[i]+siz[x]);
			x=st[x][0];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int l=lca(i,j);
			if(l==i||l==j||dep[i]+dep[j]-2*dep[l]>m)	continue;
			mx=max(mx,siz[i]+siz[j]);
		}
	}
	return mx>=k;
}
void newmain(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)	e[i].clear();
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		e[u].push_back(v),e[v].push_back(u);
	}
	dfs(1,0);
	int res=n+1;
	for(int i=1;i<=n;i++){
		m=i;
		if(check())	res=min(res,i);
	}
	cout<<res<<'\n';
}
bool ed;
void main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>T>>T;
	while(T--)	newmain();
	return;
}
}
signed main(){xzz::main();return 0;}

