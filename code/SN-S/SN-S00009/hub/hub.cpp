#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
int c, t;
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while (t--)
	{
		int n, k, u, v,a[2 * N], b[2 * N];
		memset(b, -1, sizeof(b));
		cin >> n >> k;
		for (int i = 1; i < n; i++)
		{
			cin >> u >> v;
			a[i] = u;
			a[2 * i] = v;
		}
		queue<int> q;
		q.push(1);
		b[1] = 0;
		while (q.size())
		{
			int x = q.front();
			q.pop();
			for (int i = x; i; 2 * i)
			{
				if (b[i] == -1)
				{
					b[i] = b[x] + 1;
					q.push(i);
				}
			}
		}
		int minn = 1, c[N];
		memset(c, INT_MAX, sizeof(c));
		for (int i = 1; 2 * i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				c[j] = min(c[j], b[j] - b[i]);
			}
		}
		for (int i = n; i >= n / 2; i--)
		{
			for (int j = 1; j <= n; j++)
			{
				c[j] = min(c[j], b[j] - b[i]);
			}
		}
		for (int i = 1; i <= n; i++)
		{
			minn = min(minn, c[i]);
		}
		cout << minn << '\n';
	}
	return 0;
}
