#include<bits/stdc++.h>
#define pii pair<int,int>
#define lowbit(x) ((x)&(-(x)))
#define allof(o) (o).begin(),(o).end()
using namespace std;

vector<pii> subway_lines[500005];
int a[500005];
int c,n,m,d,q;

long long G[505][505];

void Floyd()
{
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
}

signed main()
{
#ifndef _WJW_LOCAL_JUDGE
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int x,y;
			cin>>x>>y;
			subway_lines[x].push_back({i,y});
		}
	}
	memset(G,0x3f,sizeof(G));
	for(int i=1;i<=n;i++)
		G[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		int len=subway_lines[i].size();
		for(int x=0;x+1<len;x++)
			for(int y=x+1;y<len;y++)
			{
				long long w=subway_lines[i][x].second+subway_lines[i][y].second;
				int xx=subway_lines[i][x].first,yy=subway_lines[i][y].first;
// cerr<<"Add edge: "<<xx<<" -- "<<yy<<" = "<<w<<'\n';
				G[xx][yy]=G[yy][xx]=min(G[xx][yy],w);
			}
	}
	Floyd();
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		long long res=0x7fffffffffffffffLL;
		for(int i=0;i<subway_lines[x].size();i++)
			for(int j=0;j<subway_lines[y].size();j++)
			{
				int xx=subway_lines[x][i].first,yy=subway_lines[y][j].first;
				res=min(res,G[xx][yy]+subway_lines[x][i].second+subway_lines[y][j].second);
			}
		cout<<res+a[x]+a[y]<<'\n';
	}
	return 0;
}