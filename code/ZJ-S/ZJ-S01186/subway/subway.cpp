#include <bits/stdc++.h>
using namespace std;

const int M = 5e5 + 5, N = 505, Q1 = 1e5 + 5;

int c, n, m, d, q;

int w[M];

struct Node
{
	int v, id;
};

vector<Node> g[M];
vector<int> line[M];
int t[M][N], a[M];

struct QUES
{
	int st, ed, ans, idx;
}p[Q1];

int dis[M], out[M];
bool vis[M];

struct way
{
	int u, d, l;
	
	bool operator < (way w) const
	{	
		return d < w.d;
	}
};

void dijkstra(int s)
{
	memset(dis, 0x3f, sizeof dis);
	memset(out, 0, sizeof out);
	memset(vis, 0, sizeof vis);
	priority_queue<way> pq;
	
	for (int l: line[s])
		pq.push({s, t[s][l], l});
	
	while (!pq.empty())
	{
		way now = pq.top();
		pq.pop();
		
		int u = now.u, d = now.d, l = now.l;
		if (vis[u])
			continue;
		vis[u] = 1;
		
		for (auto i: g[u])
		{
			int v = i.v, id = i.id;
			int c = 0;
			if (id != l)
				c = t[u][id] + t[u][l];

			if (dis[v] > d + c || (out[v] != id && dis[v] + t[v][out[v]] + t[v][id] > d + c))
			{	
				dis[v] = d + c;
				out[v] = id;
				pq.push({v, dis[v], id});
			}
		}
	}
}

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	cin >> c >> n >> m >> d >> q;
	
	for (int i = 1; i <= m; i++)
		cin >> w[i];
		
	for (int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		
		for (int j = 1; j <= k; j++)
		{
			int x;
			cin >> a[j] >> x;
			t[a[j]][i] = x;
			line[a[j]].push_back(i);
			if (j > 1)
			{
				g[a[j - 1]].push_back({a[j], i});
				g[a[j]].push_back({a[j - 1], i});
			}
		}
	}
	
	for (int i = 1; i <= q; i++)
	{
		int s, e;
		cin >> s >> e;
		p[i] = {s, e, 0, i};
	}
	
	sort(p + 1, p + 1 + q, [](QUES l1, QUES l2)
	{
		return l1.st < l2.st;	
	});
	
	for (int i = 1; i <= q; i++)
	{
		if (p[i].st != p[i - 1].st)
			dijkstra(p[i].st);
	
		p[i].ans = dis[p[i].ed];
	}
	
	sort(p + 1, p + 1 + q, [](QUES l1, QUES l2)
	{
		return l1.idx < l2.idx;	
	});
	
	for (int i = 1; i <= q; i++)
		cout << p[i].ans + w[p[i].st] + w[p[i].ed] + t[p[i].ed][out[p[i].ed]] << "\n";
	
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/