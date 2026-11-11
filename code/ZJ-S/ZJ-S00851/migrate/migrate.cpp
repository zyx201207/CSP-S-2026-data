#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2000010,M=2010,INF=0x3f3f3f3f3f3f3f3f;
ll c,t,n,m,x[N],dist[M],cnt[M],ans;
bool vis[M];
priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> heap;
vector<ll> E[M];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		ans=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		if(n<=2000)
		{
			for(int i=1;i<=n;i++)
			{
				E[i].clear();
			}
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					if(x[j]-x[i]<=m)
					{
						E[i].push_back(j);
						E[j].push_back(i);
					}
				}
			}
			for(int i=1;i<=n;i++)
			{
				for(int j=0;j<=n;j++)
				{
					dist[j]=INF;
					vis[j]=false;
					cnt[j]=0;
				}
				dist[i]=0;
				heap.push({0,i});
				cnt[i]=1;
				while(heap.size())
				{
					ll u=heap.top().second;
					heap.pop();
					if(vis[u])
					{
						continue;
					}
					vis[u]=true;
					for(ll j:E[u])
					{
						if(dist[j]==dist[u]+1)
						{
							cnt[j]+=cnt[u];
						}
						if(dist[j]>dist[u]+1)
						{
							dist[j]=dist[u]+1;
							cnt[j]=cnt[u];
							heap.push({dist[j],j});
						}
					}
				}
				for(int j=1;j<=n;j++)
				{
					if(cnt[j]==2)
					{
						ans++;
					}
				}
			}
			cout<<ans/2<<"\n";
		}
		else
		{
			cout<<"0\n";
		}
	}
	return 0;
}