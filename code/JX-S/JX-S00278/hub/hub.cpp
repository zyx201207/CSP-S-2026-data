#include<bits/stdc++.h>
#define pii pair<int,int>
#define lowbit(x) ((x)&(-(x)))
#define allof(o) (o).begin(),(o).end()
using namespace std;

vector<int> G[1000005];
int c,t;
int n,k;

bitset<1000005> vis,in;

void dfs(int x,int fa)
{
	for(auto y:G[x])
	{
		if(y==fa)
			continue;
		if(!in[y])
			continue;
		vis[y]=1;
		dfs(y,x);
	}
}

int dfs2(int x,int fa)
{
	if(vis[x])
		return 0;
	for(auto y:G[x])
	{
		if(y==fa)
			continue;
		int t=dfs2(y,x);
		if(t>=0)
			return t+1;
	}
	return -1;
}

void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		G[i].clear();
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	long long ans=0x7fffffffffffffffLL;
	vis=0;
	for(int s=(1<<n)-1;s>0;s--)
		if(__builtin_popcount(s)==k)
		{
			int cnt=0;
			for(int i=1;i<=n;i++)
				if((s>>i)&1)
					in[i]=1;
				else
					in[i]=0;
			for(int i=1;i<=n;i++)
				if((s>>i)&1)
					if(!vis[i])
					{
						cnt++;
						vis[i]=1;
						dfs(i,0);
					}
			if(cnt>2)
				continue;
			long long res=0;
			for(int i=1;i<=n;i++)
				if(!in[i])
					res=max<long long>(res,dfs2(i,0));
			ans=min(ans,res);
		}
	cout<<ans<<'\n';
}

signed main()
{
#ifndef _WJW_LOCAL_JUDGE
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	for(cin>>c>>t;t--;solve());
	return 0;
}