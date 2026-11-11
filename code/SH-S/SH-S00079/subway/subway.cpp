#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,Q,w[500005];

struct edge
{
	int to,nxt,tim;
}e[1001005];
int head[500505],cnt = 1;
void addedge(int u,int v,int t)
{
	e[++cnt].to = v;
	e[cnt].nxt = head[u];
	e[cnt].tim = t;
	head[u] = cnt;
	e[++cnt].to = u;
	e[cnt].nxt = head[v];
	e[cnt].tim = t;
	head[v] = cnt;
}
pair<pair<int,int>,int> q[100005];
int dis[500505];
int ans[500505];
void BF(int st)
{
	queue<int> po;
	po.push(st);
	while(!po.empty())
	{
		int u = po.front();
		po.pop();
		for(int i = head[u];i;i = e[i].nxt)
		{
			int v = e[i].to;
			if(dis[v] > dis[u]+e[i].tim || dis[v] == -1)
			{
				dis[v] = dis[u]+e[i].tim;
				po.push(v);
			}
		}
	}
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> Q;
	for(int i = 1;i <= m;i++)
	{
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++)
	{
		int k;
		cin >> k;
		for(int j = 1;j <= k;j++)
		{
			int a,t;
			cin >> a >> t;
			addedge(i,a+n,t);
		}
	}
	for(int i = 0;i < Q;i++)
	{
		cin >> q[i].first.first >> q[i].first.second;
		if(q[i].first.first > q[i].first.second)
		{
			swap(q[i].first.first,q[i].first.second);
		}
		q[i].second = i;
	}
	sort(q+0,q+Q);
	int nowy = 0;
	for(int i = 0;i < Q;i++)
	{
		if(nowy != q[i].first.first)
		{
			memset(dis,-1,sizeof(dis));
			dis[q[i].first.first+n] = 0;
			BF(q[i].first.first+n);
		}
		ans[q[i].second] = dis[q[i].first.second+n] + w[q[i].first.first] + w[q[i].first.second];
	}
	for(int i = 0;i < Q;i++)
	{
		cout << ans[i] << endl;
	}
	return 0;
}

