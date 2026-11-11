#include<bits/stdc++.h>
using namespace std;
typedef int i32;
typedef unsigned int u32;
typedef long long i64;
typedef unsigned long long u64;
typedef __int128 i128;
typedef float f32;
typedef double f64;
typedef long double f128;
#define endl '\n'
const i32 N=1e6+10;
i32 n,k,nE,hd[N],to[2*N],nxt[2*N],ans,q[N],num;
i32 L,p[N][25],dep[N];
bool ch[N],vis[N];
void add(i32 u,i32 v){
	nE++,nxt[nE]=hd[u],hd[u]=nE,to[nE]=v;
}
i32 lca(i32 u,i32 v){
	if(dep[u]<dep[v])swap(u,v);
	for(i32 i=L;i>=0;i--)if(dep[u]-(1<<i)>=dep[v])u=p[u][i];
	if(u==v)return u;
	for(i32 i=L;i>=0;i--)if(p[u][i]!=p[v][i])u=p[u][i],v=p[v][i];
	return p[u][0];
}
i32 dis(i32 u,i32 v){
	i32 l=lca(u,v);
	return dep[u]+dep[v]-2*dep[l];
}
i32 val(){
	i32 res=0;
	for(i32 i=1;i<=n;i++){
		i32 res_=n+1;
		for(i32 j=1;j<=num;j++)res_=min(res_,dis(i,q[j]));
		res=max(res,res_);
	}
	return res;
}
void dfs(i32 u,i32 fa){
	vis[u]=1;
	for(i32 i=hd[u];i;i=nxt[i]){
		i32 v=to[i];
		if(v==fa)continue;
		if(!ch[v])continue;
		dfs(v,u);
	}
}
bool check(){
	i32 cnt=0;
	for(i32 i=1;i<=n;i++)vis[i]=0;
	for(i32 i=1;i<=num;i++){
		i32 u=q[i];
		if(vis[u])continue;
		dfs(u,0);
		cnt++;
		if(cnt>2)return 0;
	}
	return 1;
}
void solve(i32 id,i32 cnt){
	if(cnt>k)return;
	if(id==n+1){
		if(cnt!=k)return;
		num=cnt;
		if(check())ans=min(ans,val());
		return;
	}
	solve(id+1,cnt);
	ch[id]=1,q[cnt+1]=id;
	solve(id+1,cnt+1);
	ch[id]=0;
}
void dfs_init(i32 u,i32 fa){
	p[u][0]=fa,dep[u]=dep[fa]+1;
	for(i32 i=1;i<=L;i++)p[u][i]=p[p[u][i-1]][i-1];
	for(i32 i=hd[u];i;i=nxt[i]){
		i32 v=to[i];
		if(v==fa)continue;
		dfs_init(v,u);
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	i32 c,t;cin>>c>>t;
	while(t--){
		cin>>n>>k,nE=0,L=log2(n);
		for(i32 i=1;i<=n;i++)hd[i]=0;
		for(i32 i=1;i<n;i++){
			i32 u,v;cin>>u>>v;
			add(u,v);
			add(v,u);
		}
		dfs_init(1,0);
		ans=n+1;
		solve(1,0);
		cout<<ans<<endl;
	}
	return 0;
}
