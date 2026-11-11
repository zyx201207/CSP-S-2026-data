#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
long long cnt;
int q;
struct edge{
	int u,v,w;
}e[N];

int dis[N][N];
void add(int u,int v,int w)
{
	e[cnt].u=u;
	e[cnt].v=v;
	e[cnt].w=w;
	cnt++;
}
int ans;


bool cmp(edge a,edge b)
{
	return a.w<b.w;
}
int c,n,m,d;

int zh[N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>zh[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		int a[505];
		for(int j=1;j<=k;j++)
		{
			int t;
			cin>>a[j]>>t;
			add(a[j]*1000,a[j]*1000+i,t);
			add(a[j]*1000+i,a[j]*1000,t);
		}
		for(int j=2;j<=k;j++)
		{
			add(a[j]*1000,a[j-1]*1000,0);
			add(a[j-1]*1000,a[j]*1000,0);
		}
	}
	sort(e,e+cnt,cmp);
	for(int i=1;i<=cnt;i++)
	{
		dis[e[i].u][e[i].v]=e[i].w;
		
	}
	for(int i=1;i<=q;i++)
	{
		int u,v;
		cin>>u>>v;
		for(int j=u;j<=v;j++)
		{
			ans+=dis[u][v];
		}
		cout<<ans+zh[u]+zh[v];
	}
	
}
