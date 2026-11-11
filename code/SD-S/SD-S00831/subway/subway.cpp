/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
/*
fc subway.out subway7.ans
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;//!!!gai xiao dian!!
int c,n,m,d,q,w[N];
int e[510][510];
vector<pair<int,int> > a[N];
//struct node{
//	int u,v;
//}Q[N];//
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k,x,y;cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>x>>y;
			a[x].push_back(make_pair(i,y));
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			e[i][j]=1e18;
			if(i==j) e[i][j]=0LL;
		}
	}
	for(int u=1;u<=m;u++)
	{
		int l=a[u].size();
		for(int i=0;i<l;i++)
		{
			for(int j=i+1;j<l;j++)
			{
				int x=a[u][i].first,y=a[u][j].first;
				int z=a[u][i].second,o=a[u][j].second;
				e[x][y]=min(e[x][y],z+o);
				e[y][x]=min(e[y][x],z+o);
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
			}
		}
	}
	while(q--)
	{
		int u,v;
		cin>>u>>v;
		int l1=a[u].size(),l2=a[v].size();
		int ans=1e18;
		for(int i=0;i<l1;i++)
		{
			for(int j=0;j<l2;j++)
			{
				int x=a[u][i].first,y=a[v][j].first;
				int z=a[u][i].second,o=a[v][j].second;				
				ans=min(ans,e[x][y]+z+o+w[u]+w[v]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

