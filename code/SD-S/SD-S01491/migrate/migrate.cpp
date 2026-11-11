#include<bits/stdc++.h>
using namespace std;
long long a[2000005],dis[2000005],vis[2000005],cnt[2000005];
vector<int> g[2000005];
long long n,d;
void dijie(int s)
{
	for(int i=1;i<=n;i++)
		vis[i]=cnt[i]=0,dis[i]=1e18;
	dis[s]=0;
	cnt[s]=1;
	priority_queue<pair<int,int> > q;
	q.push({0,s});
	while(!q.empty())
	{
		pair<int,int> t=q.top();
		q.pop();
		int u=t.second;
		if(vis[u])
			continue;
		vis[u]=1;
		for(int v:g[u])
		{
			if(dis[v]>dis[u]+1)
			{
				dis[v]=dis[u]+1;
				cnt[v]=cnt[u];
				q.push({-dis[v],v});
			}
			else if(dis[v]==dis[u]+1)
			{
				cnt[v]+=cnt[u];
			}
		}
	 } 
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	if(c==11||c==12)
	{
		while(t--)
		{
			cin>>n>>d;
	//		cout<<n<<" "<<d<<" ";
			for(int i=1;i<=n;i++)
				cin>>a[i];
			long long dd=a[2]-a[1];
	//		cout<<dd<<"\n";
			long long b=d/dd;
			if(b<=1)
				cout<<0<<"\n";
			else
			cout<<max(0ll,n-2*b+1)<<"\n"; 
		}
		return 0;
	}
	while(t--)
	{
		long long ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		cin>>a[i];
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
			{
				if(a[j]-a[i]<=d)
					g[i].push_back(j),g[j].push_back(i);
				else
				{
					break;
				}
			}
		for(int i=1;i<=n;i++)
		{
			dijie(i);
			for(int j=1;j<=n;j++)
				if(cnt[j]==2)
					ans++;
		}
		cout<<ans/2<<"\n";
		for(int i=1;i<=n;i++)
			g[i].clear();
	}
	return 0;
 } 
