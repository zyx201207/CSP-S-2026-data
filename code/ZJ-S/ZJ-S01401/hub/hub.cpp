#include<bits/stdc++.h>
using namespace std;
int c, t;
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> c >> t;
	for (int i = 1; i <= t; i ++)
	{
		int n, k;
		cin >> n >> k;
		for (int i = 1; i < n; i ++)
		{
			int u, v;
			cin >> u >> v;
		}
		cout << (n - 1) / 2 << "\n";
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
/*
priority_queue<int> pq;
*/