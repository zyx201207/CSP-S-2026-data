#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
int w[500001];
bool dis[500001];
long long vis[500001];
vector<pair<int,int> > vv[500001];
vector<pair<int,int> > v[501];
struct node
{
	int u;
	long long s;
	bool operator < (const node t)const
	{
		return s>t.s;
	}
};
long long zzx(int x,int y)
{
	for (int i=1;i<=m;i++) dis[i]=0,vis[i]=LONG_LONG_MAX;
	priority_queue<node> q;
	q.push({x,0});
	while(!q.empty())
	{
		node t=q.top();
		q.pop();
		if(dis[t.u]) continue;
		dis[t.u]=true;
		vis[t.u]=t.s;
		for (int i=0;i<(int)vv[t.u].size();i++)
		{
			for (int j=0;j<(int)v[vv[t.u][i].first].size();j++)
				if(!dis[v[vv[t.u][i].first][j].first])
				{
					if(vis[t.u]+vv[t.u][i].second+v[vv[t.u][i].first][j].second>=vis[v[vv[t.u][i].first][j].first]) continue;
					vis[v[vv[t.u][i].first][j].first]=vis[t.u]+vv[t.u][i].second+v[vv[t.u][i].first][j].second;
					q.push({v[vv[t.u][i].first][j].first,vis[v[vv[t.u][i].first][j].first]});
				}
		}
	}
	return vis[y];
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for (int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for (int i=1;i<=n;i++)
	{
		int k;
		scanf("%lld",&k);
		for (int j=1;j<=k;j++)
		{
			int a,t;
			scanf("%lld%lld",&a,&t);
			v[i].push_back(make_pair(a,t));
			vv[a].push_back(make_pair(i,t));
		}
	}
	while(q--)
	{
		int x,y;
		scanf("%lld%lld",&x,&y);
		printf("%lld\n",w[x]+w[y]+zzx(x,y));
	}
	return 0;
}
