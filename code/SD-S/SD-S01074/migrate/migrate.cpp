#include <bits/stdc++.h> 

using namespace std;

const int maxn = 1e4 + 10;

long long x[maxn];
int dis[maxn], num[maxn];

void solve()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int n, d;
	cin >> n >> d;
	vector<int> con[maxn];
	for(int i = 1; i <= n; i++)
		cin >> x[i];
	for(int i = 1; i <= n; i++)
		for(int j = i + 1; j <= n; j++)
			if(x[i] + d >= x[j])
				con[i].push_back(j);
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
			dis[j] = 1e9, num[j] = 0;
		dis[i] = 0;
		queue<int> q;
		q.push(i);
		while(!q.empty())
		{
			int u = q.front();
			q.pop();
			for(int v : con[u])
				if(dis[v] > dis[u] + 1)
				{
					dis[v] = dis[u] + 1, num[v] = 1;
					q.push(v);
				}
				else if(dis[v] == dis[u] + 1)
					num[v]++;
		}
		for(int i = 1; i <= n; i++)
			if(num[i] == 2) ans++;
	}
	cout << ans << endl;
}

int main()
{
	int c, t;
	cin >> c >> t;
	while(t--) solve();
}

/*

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5


0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6




*/
