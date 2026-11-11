#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node
{
	int to;
	int value;
};
int c,n,m,d,q,dis[500005],dist[1005][1005],went[505],dxg;//m station n ways
vector<node>g[600005];
void flord()
{
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(i==j) continue;
			for(int k=1;k<=m+n;k++)
			{
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[j][k]);
				dist[j][i]=dist[i][j];
			}
		}
	}
	return;
}
int ask(int a,int b)//边数<=1e7
{
	if(c>=12&&c<=19)
	{
		//dfs(a,b,a,0);
		return dxg;
	}
	else if(c<=11)
	{
		return dist[a][b]+dis[a]+dis[b];
	}
	return 0;
}
signed main()
{
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>dis[i];
	}
	if(c<=11)
	{
		for(int i=1;i<=n+m;i++)
		{
			for(int j=1;j<=n+m;j++)
			{
				dist[i][j]=998244353998244353;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int a,b;
			cin>>a>>b;
			g[m+i].push_back({a,b});
			if(c<=11)
			{
				dist[m+i][a]=b;
				dist[a][m+i]=b;
			}
		}
	}
	if(c<=11) flord();
	for(int i=1;i<=q;i++)
	{
		int a,b;
		cin>>a>>b;
		cout<<ask(a,b)<<endl;
	}
	return 0;
}
