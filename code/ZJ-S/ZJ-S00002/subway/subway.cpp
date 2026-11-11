#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,MAXM=5e2+5;
struct node{
	int v,w;
	bool operator<(const node &x)const{
		return w>x.w;
	}
};
struct line{
	int a,t;
};
int c,n,m,d,q;
int w[N];
int k[MAXM];
vector<node> g[N];
vector<line> lid[N];
int tot[N];
int f[N];
int in_fac[MAXM];
int find(int x)
{
	if(x==f[x])
	{
		return x;
	}
	return f[x]=find(f[x]);
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			int a,t;
			cin>>a>>t;
			tot[a]++;
			lid[i].push_back({a,t});
		}
	}
	for(int i=1;i<=n;i++)
	{
		int v=lid[0][j].a;
		for(int j=1;j<k[i];j++)
		{
			int u=lid[i][j].a;
			int t=lid[i][j].t;
			if(tot[u]<2)
			{
				
			}
		}
	}
	while(q--)
	{
		int u,v;
		cout<<w[u]+w[v]+g[0][u].w+g[0][v].w<<'\n';
	}
	return 0;
}
