#include <bits/stdc++.h>
using namespace std;
int n, m, a[200010];
bool used[200010];

int find(int m)
{
	if (m == 1)
	{
		int minn = 1e9;
		for (int i = 1; i <= n; i++)
		{
			if (minn > i) minn = i;
		}
		return minn;
	}
	int minn = 1e9;
	for (int i = 1; i <= n; i++)
	{
		if (used[i] == 0)
		{
			int k = a[i] & find(m - 1);
			if (minn > k) minn = k;
		}
		used[i] = 1;
	}
	return minn;
}

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	int ans = find(m);
	printf("%d", ans);
	return 0;
}