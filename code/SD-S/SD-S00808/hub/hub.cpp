#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
constexpr int N = 2e6 + 5;
int c, t, n, k;
vector<int> adj[N];
long long read();
void solve()
{
	n = read(), k = read();
	for (int i = 1; i < n; i++)
	{
		int u = read(), v = read();
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	if (c == 13 || c == 14)
	{
		int len = n / 2 + 1;
		if (k < n / 2 + 2)
		{
			if (k & 1)
			{
				cout << (len - d + 3) / 4 << "\n";
			}
			else
			{
				cout << (len - d + 3) / 4 + 1 << "\n";
			}
		}
		else
		{
			cout << 1 << "\n";
		}
	}
}
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	c = read(), t = read();
	while (t--)
	{
		solve();
	}
	return 0;
}
long long read()
{
	long long res = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9')
	{
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		res = res * 10 + c - '0';
		c = getchar();
	}
	return res * f;
}
