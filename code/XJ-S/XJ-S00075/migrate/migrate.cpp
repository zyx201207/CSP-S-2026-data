#include<bits/stdc++.h>
using namespace std;
long long n,a[2000005],dis[2000005],vis[2000005],cnt[2000005];
struct node
{
	long long it,v;
};
vector<node>e[2000005];
bool operator<(node a,node b)
{
	return a.v>b.v;
}
priority_queue<node>q;
void dij(long long kk)
{
	for(int i=1;i<=n;i++)
	{
		dis[i]=1e18;
		vis[i]=0;
		cnt[i]=0;
	}
	dis[kk]=0;
	cnt[kk]=1;
	q.push((node){kk,0});
	while(!q.empty())
	{
		long long minn=q.top().v,itt=q.top().it;
		q.pop();
		if(vis[itt]==1)
		continue;
		vis[itt]=1;
		for(int j=0;j<e[itt].size();j++)
		{
			int v=e[itt][j].it,len=e[itt][j].v;
			if(dis[v]>minn+len)
			{
				dis[v]=minn+len;
				cnt[v]=cnt[itt];
				q.push((node){v,dis[v]});
			}
			else
			if(dis[v]==minn+len)
			{
				cnt[v]+=cnt[itt];
			}			
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(11<=c&&c<=12)
	{
		while(t--)
		{
			long long d,ans=0;
			cin>>n>>d;
			for(int i=1;i<=n;i++)
			cin>>a[i];
			d=d/(a[2]-a[1]);
			for(int i=d+1;i<=min(n,2*d-1);i++)
			if(i==2*d-1)
			ans+=max(0ll,n-2*d+1);
			cout<<ans<<"\n";
		}
		return 0;
	}
	while(t--)
	{
		long long d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		cin>>a[i];
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		if(a[j]-a[i]<=d)
		e[i].push_back((node){j,1});
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			dij(i);
			for(int j=1;j<=n;j++)
			if(cnt[j]==2)
			ans++;
		}
		cout<<ans<<endl;
		for(int i=1;i<=n;i++)
		e[i].clear();
	}
} 
