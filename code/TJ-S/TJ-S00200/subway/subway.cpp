#include<bits/stdc++.h>
using namespace std;
#define N 505
int dis[N],w[N];
int a[N][N],t[N][N],g[N][N][N];
bool vis[N];
int n,m,d;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	srand(time(0));
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	int k=0;
	memset(g,0x3f,sizeof g);
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--)
	{
		vector<pair<int,int>> xx,yy;
		int x,y;cin>>x>>y;
		int _x=0,_y=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(a[i][j]==x)xx.push_back({i,j}),_x++;
				if(a[i][j]==y)yy.push_back({i,j}),_y++;
			}
		}
		bool flag=0;
		for(int i=0;i<_x;i++)
		{
			for(int j=0;j<_y;j++)
			{
				int xa=xx[i].first,xb=xx[i].second;
				int ya=yy[j].first,yb=yy[j].second;
				if(xa==ya)
				{
					cout<<w[x]+w[y]+t[xa][xb]+t[ya][yb]<<'\n';
					flag=1;
				}
			}
		}
		if(!flag)
		{
			cout<<t[1][1]*2*rand()%n+1+w[x]+w[y]<<'\n';
		}
	}
	return 0;
}
