#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
const int N=700005;
const int M=2000005;
int head[N],nxt[M],to[M],weight[M],tot;
int anc[N],outt[N];
void add_edge(int u,int v,int w)
{
	nxt[++tot]=head[u];
	to[tot]=v;
	weight[tot]=w;
	head[u]=tot;
}
typedef struct node
{
	int u,v,w;
	bool operator < (const struct node & t) const
	{
		return w<t.w;
	}
}NODE;
NODE arr[M];
int side;
int get_anc(int u){return anc[u]=anc[u]==u?anc[u]:get_anc(anc[u]);}
void union_set(int x,int y){anc[get_anc(y)]=get_anc(x);}
void kruskal()
{
	sort(arr+1,arr+1+side);
	for(int i=1;i<=n+m;i++) anc[i]=i;
	for(int i=1,j=1;i<n+m;i++)
	{
		while(j<=side&&get_anc(arr[j].u)==get_anc(arr[j].v)) j++;
		union_set(arr[j].u,arr[j].v);
//		cerr<<"--- "<<arr[j].u<<' '<<arr[j].v<<' '<<arr[j].w<<'\n';
		add_edge(arr[j].u,arr[j].v,arr[j].w);
		add_edge(arr[j].v,arr[j].u,arr[j].w);
	}
}
int dep[N],f[N][20],sum[N];
void dfs(int u,int pre)
{
	dep[u]=dep[pre]+1;
	f[u][0]=pre;
	for(int i=head[u];i;i=nxt[i])
	{
		int v=to[i];
		if(v==pre) continue;
		sum[v]=sum[u]+weight[i];
		dfs(v,u);
	}
}
int get_lca(int x,int y)
{
	if(dep[x]>dep[y]) swap(x,y);
	int t=log2(n+m);
	for(int j=t;j>=0;j--)
		if(dep[f[y][j]]>=dep[x])
			y=f[y][j];
	if(x==y) return x;
	for(int j=t;j>=0;j--)
		if(f[x][j]!=f[y][j])
		{
			x=f[x][j];
			y=f[y][j];
		}
	return f[x][0];
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=n;i++) cin>>outt[i];
	for(int i=1;i<=m;i++)
	{
		int k,v,w; cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>v>>w;
			arr[++side]=(NODE){n+i,v,w};
		}
	}
	kruskal();
	dfs(1,0);
	int t=log2(n+m);
	for(int j=1;j<=t;j++)
		for(int i=1;i<=n+m;i++)
			f[i][j]=f[f[i][j-1]][j-1];
	while(q--)
	{
		int u,v; cin>>u>>v;
		int lca=get_lca(u,v);
//		cerr<<"--- "<<lca<<'\n';
		cout<<sum[u]+sum[v]-2*sum[lca]+outt[u]+outt[v]<<'\n';
	}
	return 0;
}

