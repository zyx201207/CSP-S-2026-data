#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define lowbit(x) (x&-x)
#define PII pair<int,int>
#define P(x,y) make_pair(x,y)
#define c(x) cout<<#x<<"="<<x<<endl;
using namespace std;
const int inf=1e18;
const int N=5e5+10,M=510;
int c,n,m,d,Q;
vector<PII> q[N];
int dis[M][M];
int w[N];

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int len;
		cin>>len;
		for(int j=1;j<=len;j++)
		{
			int x,t;
			cin>>x>>t;
			q[x].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j) continue;
			dis[i][j]=inf;
		}
	}
	
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<(int)q[i].size();j++)
		{
			for(int k=j+1;k<(int)q[i].size();k++)
			{
				int x=q[i][j].first,y=q[i][k].first;
				dis[y][x]=dis[x][y]=min(dis[x][y],q[i][j].second+q[i][k].second);
			} 
		}
	}
	
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	
	while(Q--)
	{
		int x,y;
		cin>>x>>y;
		int ans=inf;
		for(int i=0;i<(int)q[x].size();i++)
		{
			for(int j=0;j<(int)q[y].size();j++)
			{
				ans=min(ans,q[x][i].second+q[y][j].second+dis[q[x][i].first][q[y][j].first]);
			}
		}
		ans+=w[x]+w[y];
		cout<<ans<<"\n";
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

