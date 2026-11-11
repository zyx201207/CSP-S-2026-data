#include<iostream>
#include<vector>
#include<map>
#define ll long long
#define ul unsigned long long
#define inf 1e18
using namespace std;
struct node
{
	int x,y;//×é£¬µã 
};
const int M=5e5+100,N=510;
vector<int>G[M];
map<pair<int,int>,int>ma; // juli
int c,n,m,d,q;
int w[M];
int g[510][510];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		for(int j=i+1;j<=m;j++)
			g[j][i]=g[i][j]=0x3f3f3f3f;
	}	
	if(c>=7&&c<=11)
	{
		for(int i=1;i<=m;i++)cin>>w[i];
		for(int i=1;i<=n;i++)
		{
			int op,u,v,w1,w2;
			cin>>op>>u>>w1>>v>>w2;
			g[u][v]=g[v][u]=min(g[u][v],w1+w2);
		}
		for(int k=1;k<=m;k++)
		{
			for(int i=1;i<=m;i++)
			{
				for(int j=1;j<=m;j++)
				{
					g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
				}
			}
		}
//		for(int i=1;i<=m;i++)
//		{
//			for(int j=1;j<=m;j++)
//			{
//				cout<<g[i][j]<<' ';
//			}cout<<endl;
//		}
//		cout<<g[1][2];
		while(q--)
		{
			int u,v;
			cin>>u>>v;
			cout<<w[u]+w[v]+g[u][v]<<'\n';
		}
	}
	else
	{
		for(int i=1;i<=m;i++)cin>>w[i];
		for(int i=1;i<=n;i++)
		{
			int op;
			cin>>op;
			for(int j=1;j<=op;j++)
			{
				int x,y;
				cin>>x>>y;
				ma[{i,x}]=y;
				G[x].push_back(i);
			}
		}	
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(!ma[{j,i}])continue;
				for(int k=j+1;k<=n;k++)
				{
					if(!ma[{k,i}])continue;
					g[j][k]=g[k][j]=min(g[j][k],ma[{j,i}]+ma[{k,i}]);
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
			int u,v;
			int ans=0x3f3f3f3f;
			cin>>u>>v;
			for(auto i:G[u])
			{
				for(auto j:G[v])
				{
					if(i==j)ans=ma[{i,u}]+ma[{j,v}];
					else ans=min(ans,ma[{i,u}]+g[i][j]+ma[{j,v}]);
				}
			}
			cout<<w[u]+ans+w[v]<<'\n';
		}
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

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
