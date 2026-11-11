#include<bits/stdc++.h>
#define ll long long
#define pi pair<ll,ll>
using namespace std;
const ll INF=(1ll<<62);
ll C,T,n,d,ans,a[2000010],f[2000010],cnt[2000010];
priority_queue<pi,vector<pi>,greater<pi>>q;
vector<ll>g[2000010];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T--)
	{
		cin>>n>>d;
		ans=0;
		for(ll i=1;i<=n;i++)
		{
			cnt[i]=0;f[i]=INF;
		}	
		for(ll i=1;i<=n;i++)cin>>a[i];
		for(ll i=1;i<=n;i++)
		{
			for(ll j=i+1;j<=n;j++)
			{
				if(abs(a[j]-a[i])<=d)
				{
					g[i].push_back(j);
				}
			}
		}
		for(ll i=1;i<n;i++)
		{
			q.push({0,i});
			f[i]=0;cnt[i]=1;
			while(!q.empty())
			{
				auto cur=q.top();q.pop();
				ll u=cur.second,s=cur.first+1;//cout<<s<<'\n';
				for(auto v:g[u])
				{					
					if(s>f[v])continue; 
					if(s<f[v])
					{
						f[v]=s;
						cnt[v]=cnt[u];
					}
					else if(s==f[v])cnt[v]=cnt[u]+1;
					q.push({s,v});  
				}
			}	            			                             
			for(ll j=1+i;j<=n;j++)
				if(cnt[j]==2)ans++;				
		}                         
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
