#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10,M=1e18+10;
int c,t,dist[N];
vector<int>e[N];
bool vis[N];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q,qu;
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		int n,k,ans=M;
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		for(int st=0;st<(1<<n);st++)
		{
			int maax=-M,cnt=0;
			for(int i=1;i<=n;i++)
			{
				vis[i]=0;
				if((st>>(i-1))&1)
				{
					vis[i]=1;
					cnt++;
				}
				for(int kk=1;kk<=n;kk++)
				{
					dist[kk]=M;
				}
			}
			if(cnt>k)
			{
				continue;
			}
			for(int i=1;i<=n;i++)
			{
				if(vis[i]==0)
				{
					continue;
				}
				q.push({0,i});
				dist[i]=0;
				while(!q.empty())
				{
					int x=q.top().first,y=q.top().second;
					q.pop();
					if(dist[y])
					{
						continue;
					}
					for(auto v:e[y])
					{
						if(x+1<dist[v])
						{
							dist[v]=x+1;
							q.push({x+1,v});
						}
					}
				}
			}
			for(int kk=1;kk<=n;kk++)
			{
				maax=max(maax,dist[kk]);
			}
			ans=min(ans,maax);
		}
		cout<<ans<<endl;
	}
	return 0;
}
//zhishaonadianfenba
