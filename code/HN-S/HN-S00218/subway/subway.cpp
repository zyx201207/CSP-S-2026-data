#include<bits/stdc++.h> 
#define int long long
using namespace std;
int xxxxx,y,dp[1005],vis[1005],e[1005][1005];
int c,n,m,d,q,a[1005],xxx=-1,flag=1;
struct Node
{
	int a,b;
};
vector<Node>b[1005];

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i<=m;i++)
	{
		for(int j = 1;j<=m;j++)
		{
			e[i][j]=1000000000;
		}
	}
	for(int i = 1;i<=m;i++)
	{
		cin>>a[i];
	}
	
	for(int i = 1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j = 1;j<=k;j++)
		{
			int x,xx;
			cin>>x>>xx;
			b[i].push_back({x,xx}); 
		}
		for(int j = 0;j<=k-1;j++)
		{
			for(int z = 0;z<=k-1;z++)
			{
				if(b[i][z].a==b[i][j].a)
				{
					e[b[i][z].a][b[i][j].a]=min(e[b[i][z].a][b[i][j].a],b[i][j].b);
					
				}
				else
				{
					e[b[i][z].a][b[i][j].a]=min(e[b[i][z].a][b[i][j].a],b[i][j].b*2);
					e[b[i][j].a][b[i][z].a]=min(e[b[i][j].a][b[i][z].a],b[i][z].b*2);
				}
				
			}
		}
	}
	
	for(int k = 1;k<=m;k++)
	{
		for(int i = 1;i<=m;i++)
		{
			for(int j = 1;j<=m;j++)
			{
				if(e[i][j]>e[i][k]+e[k][j])
				{
					e[i][j]=e[i][k]+e[k][j];
				}
			}
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		
		cout<<e[x][y]+a[x]+a[y]<<'\n';
	}
	
	
	
	return 0;
}
