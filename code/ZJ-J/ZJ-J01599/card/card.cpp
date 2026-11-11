#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[500005];
int pos[300005];
int b[300005], len;
int ans[300005];
int cnt[500005];

signed main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	bool f = true;
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i]);
		if (i > 1 && a[i - 1] > a[i])
			f = false;
	}
	if (m == 1)
	{
		printf("%d", n);
		exit(0);
	}
	if (m == 2)
	{
		for (int i = n; i >= 1; --i)
		{
			if (a[i] == 1)
			{
				if (pos[1] == 1)
				{
					len = 1;
					pos[2] = 0;
				}
				else if (pos[1] == 2)
				{
					
				}
				else
				{
					b[++len] = 1;
					pos[1] = len;
				}
			}
			else
			{
				if (pos[2] == 1)
				{
					len = 1;
					pos[1] = 0;
				}
				else if (pos[2] == 2)
				{
					
				}
				else
				{
					b[++len] = 2;
					pos[2] = len;
				}
			}
			if (pos[1])
				++ans[1];
			if (pos[2])
				++ans[2];
		}
		printf("%d %d", ans[1], ans[2]);
	}
	if (f)
	{
		for (int i = 1; i <= n; ++i)
			pos[a[i]] = i;
		for (int i = 1; i <= m; ++i)
		{
			if (i > 1)
				putchar(' ');
			printf("%d", pos[i]);
		}
		exit(0);
	}
	int nn = 0;
	for (int i = 1; i <= n; )
	{
		a[++nn] = a[i];
		cnt[nn] = 1;
		int j = i + 1;;
		while (j <= n && a[i] == a[j])
			++j, ++cnt[nn];
		i = j;
	}
	n = nn;
	for (int i = 1; i <= n; ++i)
	{
		len = 0;
		for (int j = i; j <= n; ++j)
		{
			if (pos[a[j]])
			{
				for (int k = len; k > pos[a[j]]; --k)
					pos[b[k]] = 0;
				len = pos[a[j]];
			}
			else
			{
				b[++len] = a[j];
				pos[a[j]] = len;
			}
		}
		for (int j = 1; j <= m; ++j)
		{
			ans[j] += (pos[j] != 0) * cnt[i];
			pos[j] = 0;
		}
	}
	for (int i = 1; i <= m; ++i)
	{
		if (i > 1)
			putchar(' ');
		printf("%d", ans[i]);
	}
	return 0;
}
