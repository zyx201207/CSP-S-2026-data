#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 505, M = 1.5e6 + 5;
struct Edge
{
	ll v, w;
};
ll C, n, m, d, q, ext[N], st[N], num, id, t, dis[M], ans[N][N], l, r;
bool vis[M];
vector<Edge> e[M];
vector<pair<ll, ll> > v[M];
void dijkstra(ll s)
{
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > > q;
	q.push({0, s});
	dis[s] = 0;
	while(!q.empty())
	{
		ll tmp = q.top().second;
		q.pop();
		if(vis[tmp])
		{
			continue;
		}
		vis[tmp] = 1;
		for(auto i : e[tmp])
		{
			if(dis[i.v] > dis[tmp] + i.w)
			{
				dis[i.v] = dis[tmp] + i.w;
				q.push({dis[i.v], i.v});
			}
		}
	}
}
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin >> C >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++)
	{
		scanf("%lld", &ext[i]);
	}
	st[1] = n + m;
	for(int i = 1; i <= n; i++)
	{
		scanf("%lld", &num);
		st[i + 1] = st[i] + num;
		for(int j = 1; j <= num; j++)
		{
			scanf("%lld%lld", &id, &t);
			v[id].push_back({i, t});
			e[i].push_back({st[i] + j, 0});
			e[st[i] + j].push_back({i, 0});
			e[n + id].push_back({st[i] + j, t});
			e[st[i] + j].push_back({n + id, t});
//			cout << "?" << i << " " << st[i] + j << " " << 0 << endl;
//			cout << "?" << n + id << " " << st[i] + j << " " << t  << endl;
		}
	}
	for(int i = 1; i <= n; i++)
	{
		dijkstra(i);
//		cout << "!";
		for(int j = 1; j <= n; j++)
		{
			ans[i][j] = dis[j];
//			cout << ans[i][j] << " ";
		}
//		cout << endl;
	}
	for(int i = 1; i <= q; i++)
	{
		ll ANS = 1e18;
		scanf("%lld%lld", &l, &r);
		if(l == r)
		{
			cout << 0 << endl;
			continue;
		}
		for(auto j : v[l])
		{
			for(auto k : v[r])
			{
				ANS = min(ANS, ans[j.first][k.first] + j.second + k.second);
			}
		}
		printf("%lld\n", ANS + ext[l] + ext[r]);
	}
	return 0;
}
