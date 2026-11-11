#include<bits/stdc++.h>
using namespace std;
const int N = 2005;
const int M = 5e5 + 5;
struct node{
	int to;
	long long w;
	bool operator < (const node &other)	const{
		return w > other.w;
	}
};
vector <node> H[M];
vector <node> G[N];
int n, m, c, d, q, a[M];
long long dis[N][N], INF;
bool vis[N];
inline void read(int &x)	{
	char ch = getchar();
	x = 0;
	while (ch < '0' || ch > '9')	ch = getchar();
	while (ch >= '0' && ch <= '9')	{
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
}
int main()	{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	memset(dis, 0x3f, sizeof dis);
	INF = dis[1][1];
	read(c);
	read(n);
	read(m);
	read(d);
	read(q);
	for (int i = 1; i <= m; ++i)	read(a[i]);
	for (int i = 1; i <= n; ++i)	{
		int k, u, w;
		read(k);
		while (k--)	{
			read(u);
			read(w);
			H[u].push_back((node){i, w});
		}
	}
	for (int u = 1; u <= m; ++u)	{
		for (int i = 0; i < H[u].size(); ++i)	{
			int v = H[u][i].to;
			for (int j = i + 1; j < H[u].size(); ++j)	{
				int w = H[u][j].to, t = H[u][i].w + H[u][j].w;
				if (dis[v][w] > t)	dis[v][w] = dis[w][v] = t;
			}
		}
	}
	for (int i = 1; i <= n; ++i)	{
		for (int j = i + 1; j <= n; ++j)	{
			if (dis[i][j] < INF)	{
				G[i].push_back((node){j, dis[i][j]});
				G[j].push_back((node){i, dis[i][j]});
			}
		}
	}
	memset(dis, 0x3f, sizeof dis);
	for (int i = 1; i <= n; ++i)	{
		memset(vis, false, sizeof vis);
		priority_queue <node, vector<node> > PQ;
		dis[i][i] = 0;
		PQ.push((node){i, 0});
		while (!PQ.empty())	{
			int u = PQ.top().to;
			PQ.pop();
			if (vis[u])	continue;
			vis[u] = true;
			for (int j = 0; j < G[u].size(); ++j)	{
				int v = G[u][j].to, w = G[u][j].w;
				if (!vis[v] && dis[i][v] > dis[i][u] + w)	{
					dis[i][v] = dis[i][u] + w;
					PQ.push((node){v, dis[i][v]});
				}
			}
		}
	}
	while (q--)	{
		int x, y;
		read(x);
		read(y);
		long long minn = INF;
		for (int i = 0; i < H[x].size(); ++i)	{
			int u = H[x][i].to, w = H[x][i].w;
			for (int j = 0; j < H[y].size(); ++j)	{
				int v = H[y][j].to;
				if (dis[u][v] + w + H[y][j].w < minn)	
					minn = dis[u][v] + w + H[y][j].w;
			}
		}
		printf("%lld\n", minn + a[x] + a[y]);
	}
	return 0;
}
