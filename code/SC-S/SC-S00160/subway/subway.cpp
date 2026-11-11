#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int w[500010],sub[20010][20010];
vector<pair<int,int>> p[505];
int c,n,m,d,q;
void init()
{
	for(int i=1;i<=n;i++)
	{
		for(pair<int,int> j:p[i])
		{
			for(pair<int,int> k:p[i])
			{
				if(j.first!=k.first)
				{
					sub[j.first][k.first]=j.second+k.second;
				}
			}
		}
	}
}
void floyd()
{
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int k=1;k<=m;k++)
			{
				if(sub[j][i]!=0x3f3f3f3f && sub[i][k]!=0x3f3f3f3f)
				{
					sub[j][k]=min(sub[j][k],sub[j][i]+sub[i][k]);
				}
			}
		}
	}
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
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int a,t;
			cin>>a>>t;
			p[i].push_back({a,t});
		}
	}
	memset(sub,0x3f,sizeof(sub));
	for(int i=1;i<=m;i++)
	{
		sub[i][i]=0;
	}
	init();
	floyd();
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		cout<<sub[x][y]+w[x]+w[y]<<'\n';
	}
	
	return 0;
}