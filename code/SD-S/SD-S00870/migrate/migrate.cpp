#include<bits/stdc++.h>
using namespace std;

const int N=2e6;
long long x[N+5],dis[N+5],cnt[N+5];
vector<long long>g[N+5];
long long n,d;
void bfs(long long s)
{
	for(long long i=1;i<=n;i++)
	{
		dis[i]=-1;
		cnt[i]=0; 
	}
	queue<long long>q;
	q.push(s);
	cnt[s]=1;
	dis[s]=0;
	while(!q.empty())
	{
		long long u=q.front();
		q.pop();
		for(long long i=0;i<g[u].size();i++)
		{
			long long v=g[u][i];
			if(dis[v]==-1)
			{
				dis[v]=dis[u]+1;
				q.push(v);
				cnt[v]+=cnt[u]; 
			}
			else if(dis[v]==dis[u]+1) cnt[v]+=cnt[u];
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(long long i=1;i<=n;i++) cin>>x[i];
		for(long long i=1;i<=n;i++) g[i].clear();
		for(long long i=1;i<=n;i++)
		{
			for(long long j=i+1;j<=n;j++)
			{
				if(x[j]-x[i]<=d)
				{
					g[i].push_back(j);
					g[j].push_back(i);
				}
			}
		}
		long long sum=0;
		for(long long i=1;i<=n;i++)
		{
			bfs(i);
			for(long long j=i+1;j<=n;j++)
			{
				if(cnt[j]==2) sum++;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
