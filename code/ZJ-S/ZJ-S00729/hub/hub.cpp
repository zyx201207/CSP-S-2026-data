#include<bits/stdc++.h>
#define ll long long

using namespace std;
const int N=1005,INF=0x3f3f3f3f;
int c,tt;
int n,k;
vector<int>G[N];
int d[N],fa[12][N];
void dfs(int u,int p){
	d[u]=d[p]+1,fa[0][u]=p;
	for(int v:G[u])if(v!=p)dfs(v,u);
}
int LCA(int x,int y){
	if(d[x]<d[y])swap(x,y);
	for(int i=10;i>=0;i--)if(d[fa[i][x]]>=d[y])x=fa[i][x];
	if(x==y)return x;
	for(int i=10;i>=0;i--)if(fa[i][x]!=fa[i][y])x=fa[i][x],y=fa[i][y];
	return fa[0][x];
}
int dis(int u,int v){return d[u]+d[v]-2*d[LCA(u,v)];}
int p[N];
int ans;
void dfs1(int u,int t){
	if(u==n+1){
		int cur=0;
		vector<int>ss;
		for(int i=1;i<=n;i++)if(p[i])ss.push_back(i);
		for(int i=1;i<=n;i++){
			int mi=INF;
			for(int j:ss)mi=min(mi,dis(i,j));
			cur=max(cur,mi);
		}
		ans=min(ans,cur);
		return;
	}
	if(t<k){
		p[u]=1,dfs1(u+1,t+1);
	}
	p[u]=0,dfs1(u+1,t);
}
void solve(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)G[i].clear();
	for(int i=1,u,v;i<n;i++)scanf("%d%d",&u,&v),G[u].push_back(v),G[v].push_back(u);
	dfs(1,0);
	for(int i=1;i<=10;i++)for(int j=1;j<=n;j++)fa[i][j]=fa[i-1][fa[i-1][j]];
	ans=INF,dfs1(1,0);      
	printf("%d\n",ans);
}
signed main()
{
	freopen("hub.in","r",stdin),freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&tt);
	while(tt--)solve();
	return 0;
}