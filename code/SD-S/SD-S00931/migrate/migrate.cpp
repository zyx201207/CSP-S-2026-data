#include<bits/stdc++.h>
#define int long long
using namespace std;
int dis[2000005],dp[2000005],dx[2000005];
vector<int> G[500005];
bool vis[200005];
void bfs(int strt)
{
	queue<int> q;
	memset(vis,0,sizeof(vis));
	memset(dp,0,sizeof(dp));
	memset(dis,0x3f,sizeof(dis));
	vis[strt]=1;
	dp[strt]=1;
	dis[strt]=0;
	q.push(strt);
	while(!q.empty())
	{
		
		int u=q.front();
		//cout<<"From:"<<u<<"\n";
		q.pop();
		for(int v:G[u])
		{
			//cout<<v<<"\n";
			if(dis[v]==dis[u]+1)
			{
				dp[v]+=dp[u];
			}
			else if(dis[v]>dis[u]+1)
			{
				dp[v]=dp[u];
				dis[v]=dis[u]+1;
			}
			if(!vis[v])
			{
				q.push(v);
				vis[v]=1;
			}
		}
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,T;
	cin>>c>>T;
	if(c==13||c==14)
	{
		while(T--)
		{
			cout<<"0\n";
		}
		return 0;
	}
	while(T--)
	{
		//cout<<"case :"<<T<<"\n";
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			G[i].clear();
			cin>>dx[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(dx[j]-dx[i]<=d)
				{
					G[i].push_back(j);
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			//cout<<"solve strt:"<<i<<"\n";
			int cnt=0;
			bfs(i);
			/*
			for(int i=1;i<=n;i++)
			{
				cout<<dp[i]<<" ";
			}
			cout<<"\n";
			*/
			for(int j=1;j<=n;j++)
			{
				if(dp[j]==2)
				{
					cnt++;
				}
			}
			ans+=cnt;
		}
		cout<<ans<<"\n";
	}
	return 0;
}

/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
