#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500010],g[510][510];
pair<int,int> fir[500010],sec[500010];
vector<pair<int,int> > vec[510],arr[500010];
int c,n,m,d,q,t,u,v,w,ans;
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",&a[i]); 
		fir[i].second=sec[i].second=2e18;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&t); 
		while(t--)
		{
			scanf("%lld%lld",&v,&w); 
			arr[v].push_back({i,w}); 
			vec[i].push_back({v,w});
			if(w<fir[v].second)
			{
				sec[v]=fir[v];
				fir[v]={i,w};
			}else if(w<sec[v].second)
				sec[v]={i,w};
		}
	}
	memset(g,0x3f,sizeof(g));
	for(int i=1;i<=n;i++)
	{
		for(pair<int,int> temp:vec[i])
		{
			if(fir[temp.first].first==i)
			{
				if(sec[temp.first].first)
					g[i][sec[temp.first].first]=g[sec[temp.first].first][i]=min(g[i][sec[temp.first].first],temp.second+sec[temp.first].second);
			}else
				g[i][fir[temp.first].first]=g[fir[temp.first].first][i]=min(g[i][fir[temp.first].first],temp.second+fir[temp.first].second);
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			if(i==k)
				continue;
			for(int j=1;j<=n;j++)
			{
				if(i==j)
					g[i][j]=0;
				if(j==k||i==j)
					continue;
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
			}
		}
	}
	while(q--)
	{
		ans=2e18;
		scanf("%lld%lld",&u,&v); 
		for(pair<int,int> x:arr[u])
		{
			for(pair<int,int> k:arr[v])
				ans=min(ans,x.second+k.second+g[x.first][k.first]+a[u]+a[v]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}

