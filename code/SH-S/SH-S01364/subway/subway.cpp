#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll c,n,m,d,q,x,y;
const int M = 5e5+5,N = 505;
ll w[M],k[N],dist[M],cnt[M];
bool visited[M];
struct edge
{
	ll to,time;
}a[M][30];

int dijkstra(int start,int end)
{
	memset(dist,0x3f3f3f3f,sizeof(dist));
	memset(visited,false,sizeof(visited));
	priority_queue <pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
	pair <int,int> o;
	o.first = 0;
	o.second = start;
	pq.push(o);
	visited[start] = true;
	while (!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();
		for (int i = 1;i <= cnt[u];i++)
		{
			int v = a[u][i].to;
			if (!visited[v])
			{
				visited[v] = true;
				if(dist[v]<dist[u]+a[u][i].time)
				{
					dist[v] = dist[u]+a[u][i].time;
					pair <int,int> z;
					z.first = dist[v],z.second = v;
					pq.push(z);
				}
			}
		}
	}
	return dist[end];
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i++)
	{
		cin >> w[i];
	}
	if (c >= 7 && c <= 11)
	{
		for (int i = 1;i <= n;i++)
		{
			cin >> k[i];
			ll p[3],t[3];
			for (int j = 1;j <= k[i];j++)
			{
				cin >> p[j] >> t[j];
			}
			if (k[i] == 2)
			{
				edge p1,p2;
				p1.to = p[2],p1.time = t[1]+t[2];
				p2.to = p[1],p2.time = t[1]+t[2];
				a[p[1]][++cnt[p[1]]] =  p1;
				a[p[2]][++cnt[p[2]]] =  p2;
			}
		}
		while (q--)
		{
			cin >> x >> y;
			cout << dijkstra(x,y) << '\n';
		}
	}
	return 0;
}
