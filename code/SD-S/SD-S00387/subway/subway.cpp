#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int, int>
#define fi first
#define se second
using namespace std;
const int MAXN = 5e5 + 7;

inline int read()
{
	int w = 0, c = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9')
	{
		c = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		w = w * 10 + ch - '0';
		ch = getchar();
	}
	return w * c;
}

int w[MAXN];

int head[MAXN], nxt[MAXN], to[MAXN], val[MAXN], tot;

void add(int u, int v, int w)
{
	nxt[++tot] = head[u];
	to[tot] = v;
	val[tot] = w;
	head[tot] = u;
}

int dis[MAXN];
int vis[MAXN];

void dij(int s)
{
	memset(vis, 0, sizeof(vis));
//	memset(dis, 0x3f, sizeof(dis));
	priority_queue<PII, vector<PII >, greater<PII > > q;
	q.push({0, s});
	dis[s] = 0;
	while(!q.empty())
	{
		auto now = q.top();
		q.pop();
		int u = now.se;
		if(vis[u])
		{
			continue;
		}
		vis[u] = 1;
		for(int i = head[u]; i; i = nxt[i])
		{
			int v = to[i], w = val[i];
			cout<<w<<endl;
			if(dis[v] > dis[u] + w)
			{
//				cout<<"1111\n";
				dis[v] = dis[u] + w;
				q.push({dis[v], v});
			}
		}
	}
}

signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	int c = read(), n = read(), m = read(), d = read(), q = read();
	
	for(int i = 1;  i <= m;  i++)
	{
		w[i] = read();
	}
	
	for(int i = 1;  i <= n;  i++)
	{
		int x = read();
		int u = i;
		for(int j = 1;  j <= x;  j++)
		{
			int v = read(), w = read();
			add(u, v, w);
			add(v, u, w);
		}
	}
	
	while(q--)
	{
		int s = read(), t = read();
		dij(s);
//		for(int i = 1;  i <= 2 * m;  i++)
//		{
//			cout<<dis[i]<<endl;
//		}
		cout<<dis[t] + w[s] + w[t]<<endl;
	}
	
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
