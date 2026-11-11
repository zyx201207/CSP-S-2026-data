#include <bits/stdc++.h>
using namespace std;
long long n, m, a[501000], flag[501000], ans[301000];
queue < int > q;
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			if (flag[a[j]] == 1)
			{
				int b[500010], idx = 1;
				while (q.front() != a[j] && !q.empty())
				{
					b[idx] = q.front();
					idx++;
					q.pop();
				}
				while (!q.empty()) q.pop();
				int c = 1;
				while (c <= idx)
				{
					q.push(b[c]);
					c++;
				}
				q.push(a[j]);
				flag[a[j]] = 1;
			}
			else 
			{
				q.push(a[j]);
				flag[a[j]] = 1;
			}
		}
		while (!q.empty())
		{
			int x = q.front();
			ans[x]++;
			q.pop();
		}
	}
	for (int i = 1; i <= m; i++) cout << ans[i] << " ";
	return 0;
}