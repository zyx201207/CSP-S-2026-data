#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
int w[500005],k[505],a[505][50005],t[505][50005],cnt[500005],n;
long long dp[505][505];
vector<int> v[505];
struct aa
{
	int o,p;
}z[505][25];
bool vis[505];
struct bb
{
	int dd;
	long long dpz;
	bool operator > (const bb &e)const
	{
		if(dpz>e.dpz)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
};
long long dfs(int qd,int zd)
{
	memset(vis,0,sizeof vis);
	priority_queue<bb,vector<bb>,greater<bb> > q;
	for(int i=1;i<=cnt[qd];i++)
	{
		q.push({z[qd][i].o,0});
	}
	while(q.empty()==0)
	{
		while(vis[q.top().dd]==1)
		{
			q.pop();
		}	
		bb d=q.top();
		q.pop();
		vis[d.dd]=1;
		for(int i=1;i<=k[d.dd];i++)
		{
			if(a[d.dd][i]==zd)
			{
				return d.dpz;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(vis[i]==0)
			{
				if(dp[qd][i]>dp[d.dd][i]+dp[qd][d.dd])
				{
					dp[qd][i]=dp[d.dd][i]+dp[qd][d.dd];
					q.push({i,dp[qd][i]});
				}
			}
		}
	}
}
int main()
{
	//system("fc /w subway.out subway.out");
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,m,d,p;
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	} 
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
			cnt[a[i][j]]++;
			z[a[i][j]][cnt[a[i][j]]].o=i;
			z[a[i][j]][cnt[a[i][j]]].p=j;
		}
	}
	memset(dp,0x3f,sizeof dp);
	for(int i=1;i<=n;i++)
	{
		dp[i][i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=2;j<=k[i];j++)
		{
			cnt[a[i][j]]++;
			z[a[i][j]][cnt[a[i][j]]].o=i;
			z[a[i][j]][cnt[a[i][j]]].p=j;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=2;j<=k[i];j++)
		{
			if(cnt[a[i][j]]>1)
			{
				for(int k=1;k<=cnt[a[i][j]];k++)
				{
					dp[i][z[a[i][j]][k].o]=min(dp[i][z[a[i][j]][k].o],1ll*t[i][j]+t[z[a[i][j]][k].o][z[a[i][j]][cnt[a[i][j]]].p]);
				}
			}
		}
	}
	for(int i=1;i<=p;i++)
	{
		int x,y;
		cin>>x>>y;
		cout<<dfs(x,y)+w[x]+w[y]<<"\n";
	}
	return 0;	
}

/*0 2 5 20 2
 4 1 9 2 5
 3 1 5 2 7 4 6
 3 2 3 3 4 5 7
 1 3
1 2*/
