#include <bits/stdc++.h>
#define int long long
using namespace std;
using namespace chrono;

namespace FASTIO
{
	void read(int &x)
	{
		x = 0;
		int f = 1;
		char c = getchar();
		while(!('0' <= c && c <= '9'))
		{
			if('-' == c)
				f = -1;
			c = getchar();
		}
		while('0' <= c && c <= '9')
		{
			x = (x << 3) + (x << 1) + (c ^ '0');
			c = getchar();
		}
		x *= f;
	}
	void write(int x)
	{
		if(x < 0)
		{
			putchar('-');
			x = -x;
		}
		if(x >= 10)
			write(x / 10);
		putchar(x % 10 + '0');
	}
}

int coust;
const int N = 500 + 5;
int n;
int Pas;
int K[N], a, t;
const int NM = 5e5 + 5;
int m;
int W[NM];
vector <pair <int, int> > G[NM + N];
const int NQ = 1e5 + 5;
int q;
struct query
{
	int id;
	int st, ed;
	int ans;
} Q[NQ];
void INPUT()
{
	FASTIO::read(coust);
	FASTIO::read(n);
	FASTIO::read(m);
	FASTIO::read(Pas);
	FASTIO::read(q);
	for(int i = 1; i <= m; i ++)
		FASTIO::read(W[i]);
	for(int i = 1; i <= n; i ++)
	{
		FASTIO::read(K[i]);
		for(int k = 1; k <= K[i]; k ++)
		{
			FASTIO::read(a);
			FASTIO::read(t);
			G[a].push_back({m + i, t});
			G[m + i].push_back({a, t});
		}
	}
	for(int i = 1; i <= q; i ++)
	{
		FASTIO::read(Q[i].st);
		FASTIO::read(Q[i].ed);
		Q[i].id = i;
	}
}

void PREPAR()
{
	sort(Q + 1, Q + q + 1, [&](query a, query b)
		{
			return a.st < b.st;
		});
}

const int INF = 0x3f3f3f3f3f3f3f3f;
int dis[NM + N];
int vis[NM + N];
priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > PQ;
void GETANS()
{
	for(int I = 1; I <= q; I ++)
	{
		if(Q[I].st != Q[I - 1].st)
		{
			for(int i = 1; i <= m + n; i ++)
				dis[i] = INF,
				vis[i] = 0;
			while(PQ.size())
				PQ.pop();
			
			dis[Q[I].st] = 0;
			PQ.push({0, Q[I].st});
			while(PQ.size())
			{
				int u = PQ.top().second;
				PQ.pop();
				if(vis[u])
					continue;
				vis[u] = 1;
				
				for(auto i : G[u])
				{
					int v = i.first;
					int w = i.second;
					if(dis[v] > dis[u] + w)
					{
						dis[v] = dis[u] + w;
						PQ.push({dis[v], v});
					}
				}
			}
		}
		
		Q[I].ans = W[Q[I].st] + dis[Q[I].ed] + W[Q[I].ed];
	}
}

void OUTPUT()
{
	sort(Q + 1, Q + q + 1, [&](query a, query b)
		{
			return a.id < b.id;
		});
	for(int I = 1; I <= q; I ++)
	{
		FASTIO::write(Q[I].ans);
		putchar('\n');
	}
}

signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	INPUT();
	PREPAR();
	GETANS();
	OUTPUT();
	
	return 0;
}