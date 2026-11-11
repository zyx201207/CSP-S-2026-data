#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>

vector<vector<pii> > conn;

vector<int> f, w;
int n, m;

inline int dijkstra(int st, int ed)
{
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	pq.emplace(0, st);
	f.resize(n * m + m + 1, LLONG_MAX / 2);
	f[st] = 0;
	while(!pq.empty())
	{
		int u = pq.top().second, tmp = pq.top().first;
		pq.pop();
		if(f[u] != tmp) continue;
		for(auto j : conn[u])
		{
			int v = j.first, w = j.second;
			if(f[v] > f[u] + w)
			{
				f[v] = f[u] + w;
				pq.emplace(f[v], v);
			}
		}
	}
	return f[ed];
}

signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int c, d, q;
	cin >> c >> n >> m >> d >> q;
	w.resize(m + 1);
	conn.resize(n * m + m + 1);

	for(int i = 1; i <= m; i++)
		cin >> w[i];
	
	for(int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		vector<int> tmp(k + 1);
		for(int j = 1; j <= k; j++)
		{
			int a, t;
			cin >> a >> t;
			tmp[j] = i * m + a;
			conn[a].emplace_back(tmp[j], t);
			conn[tmp[1]].emplace_back(a, t);
		}
		if(k >= 2)
			conn[tmp[1]].emplace_back(tmp[2], 0), conn[tmp[k]].emplace_back(tmp[k - 1], 0);
		for(int i = 2; i < k; i++) conn[tmp[i]].emplace_back(tmp[i - 1], 0), conn[tmp[i]].emplace_back(tmp[i + 1], 0);
	}
	
	while(q--)
	{
		int st, ed;
		cin >> st >> ed;
		cout << w[st] + w[ed] + dijkstra(st, ed) << '\n';
	}
	return 0;
}/*
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
2 3*/
