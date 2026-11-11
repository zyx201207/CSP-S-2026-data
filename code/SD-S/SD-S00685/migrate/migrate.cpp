#include<bits/stdc++.h>
using namespace std;
const int N=2e6+1;
int cnt[N],d[N];
#define ll long long
ll x[N];
vector<int>g[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
	    int n,l,ans=0;
		cin>>n>>l;
		for(int i=1;i<=n;++i)
		    while(g[i].size())g[i].pop_back();				
		for(int i=1;i<=n;++i)cin>>x[i];
		for(int i=1;i<n;++i)
		for(int j=i+1;j<=n;++j)
		    if(x[j]-x[i]<=l)
			{
				g[i].push_back(j);
				g[j].push_back(i);
			}
		
		for(int i=1;i<=n;++i)
		{
			memset(cnt,0,sizeof cnt);
			cnt[i]=1;
			memset(d,0x3f,sizeof d);
			d[i]=0;
			queue<int>q;
			q.push(i);
			while(!q.empty())
			{
				int u=q.front();
				q.pop();
				for(int j=0;j<g[u].size();++j)
				{
					int v=g[u][j];
					if(d[v]<=d[u])continue;			
					cnt[v]+=cnt[u];
					d[v]=d[u]+1;
					q.push(v);				
				}
			}
			for(int j=1;j<=n;++j)ans+=(cnt[j]==2);
		}
		cout<<ans/2<<'\n';
	}
	return 0;
}

