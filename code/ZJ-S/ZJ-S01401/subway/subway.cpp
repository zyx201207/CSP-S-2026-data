#include<bits/stdc++.h>
using namespace std;
const int M = 500005;
struct node{
	int V;
	int W;
};
int c, n, m, d, q;
int w[M];
int k[M];
int as[M];
vector<node> edge[M];
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i ++)
	{
		cin >> w[i];
	}
	for (int i = 1; i <= n; i ++)
	{
		cin >> k[i];
//		int nv, nw;
//		int minn = INT_MAX;
//		cin >> nv >> nw;
		for (int j = 1; j <= 2 * k[i]; j ++)
		{
			int v, w;
			cin >> v;
//			minn = min(minn, w);
//			edge[nv].push_back({v, w});
//			edge[v].push_back({nv, w});
		}
//		as[i] = minn;
	}
	for (int i = 1; i <= q; i ++)
	{
		int u, v;
		long long ans = 0;
		cin >> u >> v;
		for (int i = u; i <= v; i ++)
		{
			ans += w[i];
		}
		cout << ans << "\n";
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
/*
priority_queue<int> pq;
*/