#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

#define int long long

#define INF 0x0CCFCCFCCFCCFCCF

#define rank(p) (p + n)

using namespace std;

struct Edge
{
	int v, w;	
};

struct Node
{
	int id, dis;
	
	bool operator < (const Node & b) const
	{
		return dis > b . dis;
	}
};

const int MAXN = 5e2 + 5;
const int MAXM = 5e5 + 5;
const int MAXQ = 1e5 + 5;

void cleardis();
void Dijkstra(int s);

int read();

vector <Edge> g[MAXM + MAXN];

int w[MAXM], dis[MAXM + MAXN];

bool check[MAXM + MAXN];

int c, n, m, d, q;

signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	c = read();
	n = read();
	m = read();
	d = read();
	q = read();
	for(int i = 1; i <= m; i++)
	{
		w[i] = read();
	}
	for(int i = 1; i <= n; i++)
	{
		int k = read();
		for(int j = 1; j <= k; j++)
		{
			int a = read();
			int x = read();
			g[i] . push_back({rank(a), x});
			g[rank(a)] . push_back({i, x});
		}
	}
//	cout << "!\n";
//	for(int i = 1; i <= m + n; i++)
//	{
//		cout << "#" << i << endl;
//		for(auto j : g[i])
//		{
//			cout << "@ " << j . v << " " << j . w << endl;
//		}
//	}
	while(q--)
	{
		int x = read();
		int y = read();
		cleardis();
		Dijkstra(rank(x));
		printf("%lld\n", (dis[rank(y)] + w[x] + w[y]));
	}
	return 0;
}

int read()
{
	int f = 1;
	char op = getchar();
	while(op > '9' || op < '0')
	{
		if(op == '-')
		{
			f = -1;
		}
		op = getchar();
	}
	int ans = 0;
	while(op >= '0' && op <= '9')
	{
		ans = (ans << 3) + (ans << 1) + op - '0';
		op = getchar();
	}
	return f * ans;
}

void cleardis()
{
	for(int i = 1; i <= m + n; i++)
	{
		dis[i] = INF;
		check[i] = false;
	}
	return;
}

void Dijkstra(int s)
{
	priority_queue <Node> q;
	dis[s] = 0;
	q . push({s, 0});
	while(!q . empty())
	{
//		cout << "$" << endl;
		Node tmp = q . top();
		q . pop();
		if(check[tmp . id])
		{
			continue;
		}
		check[tmp . id] = true;
		for(auto i : g[tmp . id])
		{
			if(dis[i . v] > tmp . dis + i . w)
			{
				dis[i . v] = tmp . dis + i . w;
				q . push({i . v, dis[i . v]});
//				cout << "^" << i.v << " " << dis[i.v] << endl;
			}
		}
	}
	return;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
