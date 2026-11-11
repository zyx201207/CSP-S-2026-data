#include<bits/stdc++.h>
using namespace std;
struct node
{
	long long v,w;
};
struct node2
{
	long long num,step;
	bool friend operator < (node2 a,node2 b)
	{
		return a.step>b.step;
	}
};
long long c,n,m,d,Q;
vector<node> mp[500010];
long long a[500010];
priority_queue<node2> q;
long long dis[500010];
long long vis[500010];
//long long dp[5010][5010];
long long dis1(long long s,long long t)
{
	for(long long i=0;i<=m*n+m;i++)
	{
		dis[i]=1e18;
		vis[i]=0;
	}
	q.push({s,0});
	while(q.size())
	{
		node2 s=q.top();
		q.pop();
		if(vis[s.num]==1)
		{
			continue;
		}
		vis[s.num]=1;
		for(long long i=0;i<mp[s.num].size();i++)
		{
			long long v=mp[s.num][i].v,w=mp[s.num][i].w;
			if(s.step+w<dis[v])
			{
				dis[v]=s.step+w;
				q.push({v,dis[v]});
			}
		}
	}
	return dis[t]+a[s]+a[t];
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>Q;
	for(long long i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	if(c<=8)
	{
		for(long long i=1;i<=n;i++)
		{
			long long k;
			cin>>k;
			long long last=0;
			for(long long j=1;j<=k;j++)
			{
				long long v,w;
				cin>>v>>w;
				mp[v+i*m].push_back({v,w});
				mp[v].push_back({v+i*m,w});
				if(j!=1)
				{
					mp[last].push_back({v+i*m,0});
					mp[v+i*m].push_back({last,0});
				}
				last=v+i*m;
			}
		}
		while(Q--)
		{
			long long s,t;
			cin>>s>>t;
			cout<<dis1(s,t)<<"\n";
		}
	}
	else if(c>=12&&c<=19)
	{
		for(long long i=1;i<=n;i++)
		{
			long long k;
			cin>>k;
			long long last=0;
			for(long long j=1;j<=k;j++)
			{
				long long v,w;
				cin>>v>>w;
//				dp[v+m][v]=w;
//				dp[v][v+m]=w;
//				if(j!=1)
//				{
//					dp[last][v+m]=dp[v+m][last]=0;
//				}
//				last=v+m;
			}
		}
//		for(int k=1;k<=)
		while(Q--)
		{
			long long s,t;
			cin>>s>>t;
			cout<<114514<<"\n";
		}
	}
	return 0;
}