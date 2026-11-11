#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
int cid,n,m,d,q;
int len[500005];
long long w[500005];
struct node
{
	int pos;
	long long ti;
};
vector<node> v[500005];
long long g[505][505];
long long ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>cid>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			g[i][j]=1e18;
		}
	}
	for(int i=1;i<=n;i++) g[i][i]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>len[i];
		for(int j=1;j<=len[i];j++)
		{
			int a;
			long long t;
			cin>>a>>t;
			v[a].push_back(node{i,t});
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<v[i].size();j++)
		{
			for(int k=0;k<v[i].size();k++)
			{
				if(j==k) continue;
				int x=v[i][j].pos,y=v[i][k].pos;
				g[x][y]=min(g[x][y],v[i][j].ti+v[i][k].ti);
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
			}
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		ans=1e18;
		for(int i=0;i<v[x].size();i++)
		{
			for(int j=0;j<v[y].size();j++)
			{
				ans=min(ans,w[x]+w[y]+v[x][i].ti+v[y][j].ti+g[v[x][i].pos][v[y][j].pos]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
