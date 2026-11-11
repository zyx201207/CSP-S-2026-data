#include<iostream>
#include<vector>
using namespace std;
const int inf=0x3f3f3f3f;
const int N=1e6+5;
int n,m;
struct Edge{
	int v,nxt;
}edge[N<<1];
int head[N],cnt=0;
void addedge(int u,int v){
	edge[++cnt].v=v;
	edge[cnt].nxt=head[u];
	head[u]=cnt;
}
int dfn[N],stk[N],dep[N],fa[N],idx=0;
void dfs1(int u){
	dfn[u]=++idx;
	stk[idx]=u;
	for(int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].v;
		if(v==fa[u])continue;
		fa[v]=u;
		dep[v]=dep[u]+1;
		dfs1(v);
	}
}
int lg[N],st[25][N];
void initlca(){
	for(int i=2;i<n;++i)lg[i]=lg[i>>1]+1;
	for(int i=1;i<n;++i)st[0][i]=dfn[fa[stk[i+1]]];
	for(int i=1;(1<<i)<n;++i)
		for(int j=1;j+(1<<i)-1<n;++j){
			int k=j+(1<<(i-1));
			st[i][j]=min(st[i-1][j],st[i-1][k]); 
		}
}
int lca(int x,int y){
	if(x==y)return x;
	int l=min(dfn[x],dfn[y]),r=max(dfn[x],dfn[y])-1;
	int i=lg[r-l+1];
	return stk[min(st[i][l],st[i][r-(1<<i)+1])];
}
int dis(int x,int y){
	int z=lca(x,y);
//	cerr<<x<<","<<y<<","<<z<<"="<<dep[x]+dep[y]-dep[z]*2<<"\n";
	return dep[x]+dep[y]-dep[z]*2;
}
vector<int>S;
bool vis[N],ano[N];
int ans=inf;
void rem(int u){
	ano[u]=false;
	for(int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].v;
		if(!ano[v])continue;
		rem(v);
	}
}
void check(){
	int tmp=0;
	for(int i=1;i<=n;++i){
		if(vis[i])continue;
		int mn=inf;
		for(int j:S)
			mn=min(mn,dis(i,j));
		tmp=max(tmp,mn);
	}
	if(tmp>=ans)return;
	copy(vis+1,vis+n+1,ano+1);
	int blk=0;
	for(int i=1;i<=n;++i){
		if(ano[i]){
			rem(i);
			++blk;
			if(blk>2)return;
		}
	}
	ans=min(ans,tmp);
}
void dfs2(int u,int t){
	if(u>n){
		if(t!=m)return;
		check();
		return;
	}
	dfs2(u+1,t);
	S.push_back(u);
	vis[u]=true;
	dfs2(u+1,t+1);
	S.pop_back();
	vis[u]=false;
}
void solve(){
//	cerr<<"==========\n";
	cnt=0;
	ans=inf;
	cin>>n>>m;
	fill(head+1,head+n+1,0);
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		addedge(u,v);
		addedge(v,u);
	}
	idx=0;
	dep[1]=1;
	dfs1(1);
	initlca();
	dfs2(1,0);
	cout<<ans<<'\n';
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c,t;
	cin>>c>>t;
	while(t--)solve();
	return 0;
}

