# include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> P;

const int N	= 500010;
struct node {ll to, num;};
struct node2 {ll u, dis, num;};
ll c, n, m, d, q, ed, st, ans;
ll w[N], dis[1010];
vector <ll> t[N];
vector <node> G[N];
bool vis[410][510];

bool operator < (node2 x, node2 y) {return x.dis > y.dis;}

void DFS(ll u, ll sum, ll sub)
{
//	cout<<u<<" "<<sum<<" "<<sub<<endl;
	if (u == ed)
	{
//		cout<<t[u][sub]<<endl;
		ans = min(ans, sum + t[u][sub]);
		return;
	}
	vis[u][sub] = true;
	for (int i = 0; i < G[u].size(); i++)
	{
		ll v, num;
		v = G[u][i].to, num = G[u][i].num;
		if (!sub)
		{
//			cout<<"1: "<<v<<" "<<sum+t[u][num]<<" "<<num<<endl;
			DFS(v, sum + t[u][num], num); //任意线路 
			vis[v][num] = false;
			continue;
		}
		if (num == sub)
		{
			if (!vis[v][sub]) DFS(v, sum, sub), vis[v][sub] = false;
//			cout<<"2: "<<v<<" "<<sum<<" "<<sub<<endl;
//			DFS(v, sum, sub); //未换 
//			vis[v][sub] = false;
		}
		if (num != sub)
		{
			if (!vis[v][num])
			{
				
				DFS(v, sum + t[u][sub] + t[u][num], num); //换了 
				vis[v][num] = false;
			}
//			cout<<"3: "<<v<<" "<<sum<<" "<<t[u][sub]<<" "<<t[u][num]<<" "<<num<<endl;
				
		}
	}
}

void Dijkstra() //边权为0 or tu+tv  
{
	set <int> vis;
	ans = 1e18;
	priority_queue <node2> q;
	q.push({st, 0, 0});
	dis[st] = 0;
	while (!q.empty())
	{
		ll u, v, sub, num;
		u = q.top().u;
		sub = q.top().num;
		q.pop();
		vis.insert(u);
		if (u == ed)
		{
			ans = min(ans, t[u][sub] + dis[u]);
			continue;
		}
		for (int i = 0; i < G[u].size(); i++)
		{
			v = G[u][i].to, num = G[u][i].num;
			if (num == sub)
			{
				if (dis[v] > dis[u])
				{
					dis[v] = dis[u];
					q.push({v, dis[v], sub});
				}
			}
			else
			{
				if (dis[v] > dis[u] + t[u][sub] + t[u][num])
				{
					dis[v] = dis[u] + t[u][sub] + t[u][num];
					q.push({v, dis[v], num});
				}
			}
		}
	}
	printf("%lld\n", ans + w[st] + w[ed]);
	for (auto x : vis) dis[x] = 1e18;
}

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%lld%lld%lld%lld%lld", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++) scanf("%lld", &w[i]), t[i].push_back(0);
	for (int i = 1; i <= n; i++)
	{
		ll k, lst;
		scanf("%lld", &k);
		lst = -1;
		while (k--)
		{
			ll a, T;
			scanf("%lld%lld", &a, &T);
			if (lst != -1) G[lst].push_back({a, i}), G[a].push_back({lst, i});
			t[a].resize(i + 1);
			t[a][i] = T;
//			cout<<a<<" "<<T<<endl;
			lst = a;
		}
	}
//	for (int i = 1; i <= m; i++)
//	{
//		for (int j = 1; j <= G[i].size();j++)cout<<i<<" "<<t[i][j]<<endl;
//	}
	if (1 <= c && c <= 6) //~12pts
	{
		while (q--)
		{
			scanf("%lld%lld", &st, &ed);
			ans = 1e18;
			DFS(st, 0, 0);
			vis[st][0] = false;
			printf("%lld\n", w[st] + w[ed] + ans);
		}
	}
	else if (c >= 7 && c <= 11) //~8pts
	{
		for (int i = 1; i <= m; i++) dis[i] = 1e18;
		while (q--)
		{
			scanf("%lld%lld", &st, &ed);
			Dijkstra();
		}
	}
	else if (c >= 20 && c <= 21) //~8pts
	{
//		while (q--)
//		{
//			scanf("%lld%lld", &st, &ed);
//			if (n == 1) printf("%lld\n", w[st] + t[st][1] + t[ed][1] + w[ed]);
//			else
//			{
//				if (G[st].size() == 1);
//			}
//		}
//		if (n == 1) printf("%lld\n");
//		for (int i = 1; i <= m; i++)
//		{
//			if (G[i].size() == 2)
//			{
//				n1 = G[i][0].num, n2 = G[i][1].num;
//				if (G[i][0].num == G[i][1].num) printf("%lld\n", w[st] + t[st][n1] + t[ed][n1] + w[ed]);
//				else
//				{
//					
//				}
//			}
//		}
	}
	else if (c >= 22 && c <= 23)
	{
		
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
*/
