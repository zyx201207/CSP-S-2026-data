#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=6e5+10;

struct IKUN
{
	int v,w;
	bool operator > (const IKUN& x) const {return w>x.w;}
};

int ex[N];
int dis[N];
vector <IKUN> g[N];

int Dij(int s,int en)
{
	int ans=1e18;
	memset(dis,0x3f,sizeof(dis));
	priority_queue <IKUN,vector<IKUN>,greater<IKUN>> q;
	q.push({s,ex[s]});
	dis[s]=ex[s];
	while(q.size())
	{
		IKUN t=q.top();
		q.pop();
		if(t.v==en)
		{
			ans=min(ans,dis[en]+ex[en]);
			continue;
		}
		if(t.w>dis[t.v]) continue;
		int u=t.v;
		for(auto x:g[u])
		{
			int v=x.v,w=x.w;
			if(dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				q.push({v,dis[v]});
			}
		}
	}
	return ans;
}

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,cnt;
	scanf("%lld%lld%lld%lld%lld",&c,&m,&n,&d,&q);
	for(int i=1;i<=n;i++) scanf("%lld",&ex[i]);
	cnt=n;
	for(int i=1;i<=m;i++)
	{
		int l;
		scanf("%lld",&l);
		cnt++;
		for(int j=1;j<=l;j++)
		{
			int v,w;
			scanf("%lld%lld",&v,&w);
			g[cnt].push_back({v,w});
			g[v].push_back({cnt,w});
		}
	}
	while(q--)
	{
		int s,t;
		scanf("%lld%lld",&s,&t);
		printf("%lld\n",Dij(s,t));
	}
	return 0;
}
