#include <bits/stdc++.h>
#define int long long 
#define pii pair<int,int>
using namespace std;
const int N=2e5+5;
void sol()
{
	int n,p;
	cin>>n>>p;
	vector<int> a(n+1);
	int is=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>1e17||a[i]<-1e17)
			is=1;
	}
	if(is==1)
	{
		p=p*1.0/1.1;
		for(int i=1;i<=n;i++)
			a[i]=a[i]*1.0/1.1;
	}
	vector<int> dis(n+1,LONG_LONG_MAX);
	vector<int> vis(n+1);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(a[j]-a[i]<=p)
				continue;
			priority_queue<pii,vector<pii>,greater<pii>> qu;
			for(int k=1;k<=n;k++)
				dis[k]=LONG_LONG_MAX;
			for(int k=1;k<=n;k++)
				vis[k]=0;
			dis[i]=0;
			qu.push({dis[i],i});
			vis[i]=1;
			int cnt=0;
			while(!qu.empty())
			{
				int u=qu.top().second;
				qu.pop();
				for(int k=u+1;k<=n;k++)
				{
					if(a[k]-a[u]>p)
						break;
					if(dis[k]==dis[u]+1&&k==j)
						cnt+=1;
					if(!vis[k]||dis[k]>dis[u]+1)
					{
						if(dis[k]>dis[u]+1&&k==j)
							cnt=1;
						dis[k]=dis[u]+1;
						vis[k]=1;
						qu.push({dis[k],k});
					}
				}
				for(int k=i-1;k>=1;k--)
				{
					if(a[u]-a[k]>p)
						break;
					if(dis[k]==dis[u]+1&&k==j)
						cnt+=1;
					if(!vis[k]||dis[k]>dis[u]+1)
					{
						if(dis[k]>dis[u]+1&&k==j)
							cnt=1;
						dis[k]=dis[u]+1;
						vis[k]=1;
						qu.push({dis[k],k});
					}
				}
			}
			if(cnt==2)
				ans+=1;
		}
	}
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
		sol();
}