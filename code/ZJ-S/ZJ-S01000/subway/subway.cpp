#include<bits/stdc++.h> /*_*/
using namespace std;
// T2-subway

const int N = 5e5 + 10, M = 2 * N, L = 110;
int h[N], e[M], w[M], ne[M], idx;
int c, n, m, d, q;
int dist[N];
bool st[N];
int line[L];
int mp[L];

void add(int a, int b, int c)
{
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}
void spfa(int start)
{
	memset(dist, 0x3f, sizeof dist);
	dist[start] = 0;
	queue<int> q;
	q.push(start);
	memset(st, 0, sizeof st);
	st[start] = 1;
	while(q.size())
	{
		int u = q.front();
		q.pop();
		st[u] = 0;
		for(int i = h[u]; ~i; i = ne[i])
		{
			int j = e[i];
			if(dist[j] > dist[u] + w[i])
			{
				dist[j] = dist[u] + w[i];
				if(!st[j])
				{
					q.push(j);
					st[j] = 1;
				}
			}
		}
	}
}

signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	memset(h, -1, sizeof h);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i ++)
	{
		int x;
		cin >> x;
		add(i, i + m, x), add(i + m, i, x);
	}
	for(int l = 1; l <= n; l ++)
	{
		memset(line, -1, sizeof line);
		int k;
		cin >> k;
		int tmap = 0;
		for(int i = 1; i <= k; i ++)
		{
			int j;
			cin >> j;
			cin >> line[j];
			mp[tmap ++] = j;
		}
		for(int i = 0; i < tmap; i ++)
			for(int j = i + 1; j < tmap; j ++)
			{
				add(mp[i], mp[j], line[mp[i]] + line[mp[j]]);
				add(mp[j], mp[i], line[mp[i]] + line[mp[j]]);
			}
	}
	for(int i = 1; i <= q; i ++)
	{
		int a, b;
		cin >> a >> b;
		spfa(a + m);
		cout << dist[b + m] << endl;
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

Oct31==Dec25?
*/
