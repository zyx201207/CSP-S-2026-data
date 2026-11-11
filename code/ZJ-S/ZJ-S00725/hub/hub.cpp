#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t;
ll n,k;
ll a[101];
bool vis[101];
bool tp[101];
struct node
{
	ll id,step;
};
bool check(ll p)
{
	memset(a,0,sizeof(a));
	ll cnt=1,sum=0;
	while(p)
	{
		a[cnt]=p%2;
		sum+=a[cnt];
		p=p/2;
		cnt++;
	}
	if(sum!=k)
	{
		return false;
	}
	else
	{
		return true;
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		ll ans=1e18;
		vector<ll>g[101];
		cin>>n>>k;
		for(ll i=1;i<n;i++)
		{
			ll u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for(ll sta=0;sta<(1<<n);sta++)
		{
			if(check(sta))
			{
				ll num=0;
				for(ll i=1;i<=n;i++)
				{
					if(vis[i]==false&&a[i]>0)
					{
						memset(tp,0,sizeof(tp));
						num++;
						ll p=i;
						vis[p]=true;
						tp[p]=true;
						queue<ll>q;
						q.push(p);
						while(!q.empty())
						{
							ll r=q.front();
							q.pop();
							for(ll j=0;j<g[r].size();j++)
							{
								ll e=g[r][j];
								if(a[e]>0&&tp[e]==false)
								{
									tp[e]=true;
									vis[e]=true;
									q.push(e);
								}
							}
						}
					}
				}
				if(num<=2)
				{
					ll mx=0;
					for(ll i=1;i<=n;i++)
					{
						if(!vis[i])
						{
							continue;
						}
						memset(tp,0,sizeof(tp));
						queue<node>q;
						tp[i]=true;
						q.push({i,0});
						while(!q.empty())
						{
							ll u=q.front().id;
							ll w=q.front().step;
							q.pop();
							for(ll j=0;j<g[u].size();j++)
							{
								
								ll e=g[u][j];
								if(tp[e]==false&&a[e]==0)
								{
									tp[e]=true;
									mx=max(mx,w+1);
									q.push({e,w+1});
								}
							}
						}
					}
					ans=min(mx,ans);
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
