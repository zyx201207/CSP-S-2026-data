#include <bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+5,Q=1e5+5;
const long long INF=1e18;
int c,n,m,d,q,k[N],a[N][M],x[Q],y[Q];
long long w[M],t[N][M],tt[M][N];
int idx,head[N];
struct Edge
{
	int to,next;
} edge[2*(N+M)];
void jb(int u,int v)
{
	idx++;
	edge[idx].to=v;
	edge[idx].next=head[u];
	head[u]=idx;
}
int dfs(int u,int fa)
{
	long long res=INF;
	for (int i=head[u];i!=-1;i=edge[idx].next)
	{
		int v=edge[i].to;
		if (v==fa) continue;
		if (v>u) swap(u,v);
		res=min(res,tt[u][v]+dfs(v,u));
	}
	return res;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(head,-1,sizeof(head));
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for (int i=1;i<=n;i++)
	{
		cin>>k[i];
		for (int j=1;j<=2*k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
			tt[a[i][j]][i]=t[i][j];
			jb(i,a[i][j]);
			jb(a[i][j],i);
		}
	}
	for (int i=1;i<=q;i++)
	{
		cin>>x[i]>>y[i];
		cout<<w[x[i]]+w[y[i]]+dfs(1,0);
	}
	return 0;
}
