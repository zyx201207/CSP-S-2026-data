#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define per(i,r,l) for(int i=r;i>=l;i--)
#define gc() (p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
char ibuf[1<<20],*p1,*p2;
inline void read(int &x)
{
	x=0;bool f=0;char ch=getchar();
	for(;!isdigit(ch);ch=gc())if(ch=='-')f=1;
	for(;isdigit(ch);ch=gc())x=x*10+ch-'0';
	x=f?-x:x; 
}
template<typename ...Args>
void read(int &x,Args&...args)
{
	read(x);read(args...);
}


//
const int N=15,inf=1e9;
int C,T,n,K,ans,f[N],dep[N],fa[N][6]; 
vector<int>G[N];
int find(int x){
	return x==f[x]?x:f[x]=find(f[x]);
}
void U(int x,int y)
{
	x=find(x);y=find(y);
	f[x]=y;
}
bool chk(int s)
{
	int cnt=0;
	rep(i,1,n)if(s&1<<i-1)cnt++;
	if(cnt!=K)return 0;
	rep(i,1,n)f[i]=i;
	rep(u,1,n)
		for(auto v:G[u])if((s&1<<u-1)&&(s&1<<v-1))U(u,v);
	cnt=0;
	rep(i,1,n)if((s&1<<i-1)&&(f[i]==i))cnt++;
	return cnt<=2;
}
void dfs(int u,int pa)
{
	rep(i,1,5)fa[u][i]=fa[fa[u][i-1]][i-1];
	for(auto v:G[u])if(v!=pa)
	{
		dep[v]=dep[u]+1;
		fa[v][0]=u;
		dfs(v,u);
	}
}
int lca(int u,int v)
{
	if(dep[u]<dep[v])swap(u,v);
	per(i,5,0)if(dep[fa[u][i]]>=dep[v])u=fa[u][i];
	if(u==v)return u;
	per(i,5,0)if(fa[u][i]!=fa[v][i])u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
int dis(int u,int v)
{
	return dep[u]+dep[v]-2*dep[lca(u,v)];
}
int cal(int s)
{
	dep[0]=-1;
	dfs(1,0);
	int mx=0;
	rep(i,1,n)
	{
		int mi=inf;
		rep(j,1,n)if(s&1<<j-1)mi=min(mi,dis(i,j));
		mx=max(mx,mi);
	}
	return mx;
}
void solve()
{
	cin>>n>>K;
	rep(i,1,n-1)
	{
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u); 
	}
	ans=inf;
	rep(s,0,(1<<n)-1)if(chk(s))ans=min(ans,cal(s));
	cout<<ans<<'\n';
	rep(i,1,n)G[i].clear();
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>C>>T;
	while(T--)solve();
	
	return 0;
}