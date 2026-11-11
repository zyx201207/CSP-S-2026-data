#include<bits/stdc++.h>
using namespace std;
#define sp " "
#define Ios ios::sync_with_stdio(0);cin.tie(0);
typedef long long ll;
const int N = 5e5 + 5;
const int NM = 5e5 + 505;
const int Q = 1e5 + 5;
int c, n, d;
ll m, q, W[N], dis[N], ans[N];
struct Node
{
	int v;
	ll w;
	bool operator<(const Node &T) const
	{
		return w < T.w;
	}
};
vector<vector<Node> > G;
struct priq
{
	ll l, r, idi;
} quest[N];
inline bool cmp(const priq &x, const priq &y)
{
	return x.l < y.l;
}
inline int id(int x) //将地铁站下标转换 
{
	return x + n;
}
queue<Node> que;
void dijkstra(int s)
{
	for(int i = 1; i <= n+m; i++) dis[i] = INT_MAX;
	que.push({id(s), 0});
	dis[id(s)] = 0;
	while(!que.empty())
	{
		Node u = que.front();
		que.pop();
		int len = G[u.v].size();
		for(Node v : G[u.v])
		{
			if(v.v != u.v && dis[u.v] + v.w < dis[v.v])
			{
				dis[v.v] = dis[u.v] + v.w;
				que.push({v.v, dis[v.v]});
			}
		}
	}
}
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	Ios;
	cin >> c >> n >> m >> d >> q;
	G.resize(n + m + 1);
	for(int i = 1; i <= m; i++) cin >> W[i];
	for(int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		for(int j = 1; j <= k; j++)
		{
			int v;
			ll t;
			cin >> v >> t;
			G[i].push_back({id(v), t});
			G[id(v)].push_back({i, t});
		}
	}
	for(int i = 1; i <= q; i++)
		cin >> quest[i].l >> quest[i].r, quest[i].idi = i;
	sort(quest + 1, quest + q + 1, cmp);
	for(int l = 1; l <= q;)
	{
		dijkstra(quest[l].l);
		ll pos = l;
		do
		{
			ans[quest[pos].idi] = W[quest[pos].l] + dis[id(quest[pos].r)] + W[quest[pos].r];
			pos++;
		} while(quest[l].l == quest[pos].l && pos <= q);
		l = l + (pos - l);
	}
	for(int i = 1; i <= q; i++)
		cout << ans[i] << endl;
	return 0;
}
