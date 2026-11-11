#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=4e5+13;
int n,m,a[N],ans,t,used[N],dis[N],cnt[N+1],vis[N];
vector<int>b[N];
void spfa(int s)
{
	memset(dis,32,sizeof(dis));
	memset(used,0,sizeof(used));
	dis[s]=0;
	queue<int>q;
	q.push(s);
	while(q.size())
	{
		int u=q.front();q.pop();
		used[u]=0;
		for(int i=0;i<b[u].size();i++)
		{
			int v=b[u][i];
			if(dis[v]>dis[u]+1)
			{
				dis[v]=dis[u]+1;
				if(!used[v])
				{
					used[v]=1;
					q.push(v);
				}
			}
		}
	}
}
void spfa_(int s)
{
	queue<int>q;
	memset(used,0,sizeof(used));
	q.push(s);
	used[s]=1;
	while(q.size())
	{
		int u=q.front();q.pop();
		used[u]=0;
		for(int i=0;i<b[u].size();i++)
		{
			int v=b[u][i];
			if(dis[v]==dis[u]+1)cnt[v]++;
			if(!used[v])
			{
				used[v]=1;
				q.push(v);
			}
		}
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c;
	cin>>c>>t;
	while(t--)
	{
		int d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(a[n]-a[1]<=d)
		{
			cout<<max(n-2,0ll)<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++)
			if(b[i].size())b[i].clear();
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(a[j]-a[i]<=d)b[i].push_back(j);
				else break;
		for(int i=1;i<n;i++)
		{
			spfa(i);
			spfa_(i);
			for(int j=i;j<=n;j++)
				if(cnt[j]==2&&!vis[j])
					ans++,vis[j]=1;
			memset(cnt,0,sizeof(cnt));
		}
		cout<<ans<<"\n";
		memset(vis,0,sizeof(vis));
		ans=0;
	}
}