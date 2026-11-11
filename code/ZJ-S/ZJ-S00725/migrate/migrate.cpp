#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t,ans;
ll n,d;
ll a[5005];
ll dis[5005];
ll cnt[5005];
struct node
{
	ll id,step;
};
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		vector<ll>g[5005];
		ans=0;
		cin>>n>>d;
		for(ll i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(ll i=1;i<=n;i++)
		{
			for(ll j=i+1;j<=n;j++)
			{
				if(a[j]-a[i]<=d)
				{
					g[i].push_back(j);
				}
			}
		}
		for(ll j=1;j<=n;j++)
		{
			ll s=j;
			for(ll i=1;i<=5000;i++)
			{
				dis[i]=1e18;
				cnt[i]=0;
			}
			dis[s]=0;
			cnt[s]=1;
			queue<node>q;
			q.push({s,0});
			while(!q.empty())
			{
				node u=q.front();
				q.pop();
				for(ll i=0;i<g[u.id].size();i++)
				{
					ll e=g[u.id][i];
					if(dis[e]>u.step+1)
					{
						dis[e]=u.step+1;
						cnt[e]=cnt[u.id];
						q.push({e,dis[e]});
					}
					else if(dis[e]==u.step+1)
					{
						cnt[e]+=cnt[u.id];
					}
				}
			}
			for(ll i=s+1;i<=n;i++)
			{
				if(cnt[i]==2)
				{
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
