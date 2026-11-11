#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d;
const int MAXN=2e6+5;
long long x[MAXN],dis[MAXN],mark[MAXN],ans;
vector<int> g[MAXN];
void dij(int st)
{
	for(int i=1;i<=n;i++)
		dis[i]=LONG_LONG_MAX,mark[i]=0;
	queue<long long> q;
	dis[st]=0;
	q.push(st);
	while(!q.empty())
	{
		long long u=q.front();
		q.pop();
		for(int v:g[u])
		{
			if(dis[v]>dis[u]+1)
			{
				if(mark[v]!=0)
					ans--;
				mark[v]=0;
				dis[v]=dis[u]+1;
				q.push(v);
			}
			else if(dis[v]==dis[u]+1)
			{
				if(mark[v]==0)
					ans++;
				mark[v]++;
				if(mark[v]>1)
					ans--;
			}
				
		}
	}
}
void solve()
{
	ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++)
		cin>>x[i];
	if(c==11||c==12)
	{
		int diff=x[2]-x[1];
		if(diff*2>d)
		{
			cout<<0<<"\n";
			return;
		}
	}
	for(int i=1;i<=n;i++)
		g[i].clear();
	for(int i=1;i<=n;i++)
	{
		for(int j=i-1;j>=1;j--)
		{
			if(x[i]-x[j]>d)
				break;
			g[j].push_back(i);
			g[i].push_back(j);
		}
	}
	for(int i=1;i<=n;i++)
		dij(i);
	cout<<ans<<"\n";
	
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		solve();
	}
}