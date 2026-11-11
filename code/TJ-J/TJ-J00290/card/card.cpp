#include <bits/stdc++.h>
using namespace std;
const int N = 5 * 1e5 + 5, M = 3 * 1e5 + 5;
int n, m, a[N], cnt[M], s[N], last;
bool f[M];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", a + i);
	}
	for (int i = 1; i <= n; i++)
	{
		last = 0;
		memset(f, sizeof(f), 0);
		memset(s, sizeof(s), 0);
		for (int j = i; j <= n; j++)
		{
			if (f[a[j]])
			{
				while (s[last-1] != a[j])
				{
					f[s[--last]] = 0;
				}
				continue;
			}
			s[last++] = a[j];
			f[a[j]] = 1;
		}
		for (int j = 0; j < last; j++)
		{
			cnt[s[j]]++;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		printf("%d ", cnt[i]);
	}
	return 0;
}