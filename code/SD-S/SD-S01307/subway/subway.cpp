#include<bits/stdc++.h>
#define int long long
using namespace std;
int e[529][529],n,m,d,q,c,w[1000009];
vector<pair<int,int> > v[1000009];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	int len=0,x=0,y=0;
	for(int i=1;i<=n;i++)
	{
		cin>>len;
		for(int j=1;j<=len;j++)
		{
			cin>>x>>y;
			v[x].push_back({i,y});
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j)
			{
				e[i][j]=0;
			}
			else
			{
				e[i][j]=0x3f3f3f3f3f3f3f3f;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<v[i].size();j++)
		{
			for(int k=0;k<v[i].size();k++)
			{
				e[v[i][j].first][v[i][k].first]=min(e[v[i][j].first][v[i][k].first],v[i][j].second+v[i][k].second);
				e[v[i][k].first][v[i][j].first]=min(e[v[i][j].first][v[i][k].first],v[i][j].second+v[i][k].second);
			}
		}
	}
	for(int k=n;k>=1;k--)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(e[i][k]<0x3f3f3f3f3f3f3f3f&&e[k][j]<0x3f3f3f3f3f3f3f3f)
				{
					e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
				}
			}
		}
	}
	while(q--)
	{
		cin>>x>>y;
		int ans=0x3f3f3f3f3f3f3f3f;
		for(int j=0;j<v[x].size();j++)
		{
			for(int k=0;k<v[y].size();k++)
			{
				ans=min(ans,w[x]+w[y]+v[x][j].second+v[y][k].second+e[v[x][j].first][v[y][k].first]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
 } 
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
