#include <bits/stdc++.h>
using namespace std;

int n, m;
int ans;
int a[200005];
int cnt[4];
int pre1[200005], pre2[200005];

void dfs(int u, int cnt, int ad)
{
	if (n - u + 1 + cnt < m)
		return;
	if (cnt == m)
	{
		if (ad > ans)
			ans = ad;
		return;
	}
	dfs(u + 1, cnt, ad);
	dfs(u + 1, cnt + 1, ad & a[u]);
}

signed main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d%d", &n, &m);
	int mx = 0, ad;
	bool f1 = true, f2 = true, f3 = true;
	int nn = n;
	int len = 1;
	while ((nn & 1) == 0)
		nn >>= 1, ++len;
	if (nn != 1)
		f3 = false;
 	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i]);
		if (a[i] > mx)
			mx = a[i];
		if (a[i] == 1)
			ad = a[i];
		else
			ad &= a[i];
		if (a[i] < 4)
			++cnt[a[i]];
		else
			f1 = false;
		int x = a[i];
		while (x & 1)
			x >>= 1;
		if (x)
			f2 = false;
		if (a[i] != i - 1)
			f3 = false;
	}
	if (m == 1)
	{
		printf("%d\n", mx);
		exit(0);
	}
	if (m == 2 && n <= 5000)
	{
		mx = 0;
		for (int i = 1; i < n; ++i)
			for (int j = i + 1; j <= n; ++j)
				if ((a[i] & a[j]) > mx)
					mx = (a[i] & a[j]);
		printf("%d\n", mx);
		exit(0);
	}
	if (m == n)
	{
		printf("%d\n", ad);
		exit(0);
	}
	if (n <= 20)
	{
		for (int i = 1; i <= n - m + 1; ++i)
			dfs(i + 1, 1, a[i]);
		printf("%d\n", ans);
		exit(0);
	}
	if (f1)
	{
		if (cnt[3] >= m)
			printf("3\n");
		else if (cnt[3] + cnt[2] >= m)
			printf("2\n");
		else if (cnt[3] + cnt[1] >= m)
			printf("1\n");
		else
			printf("0\n");
		exit(0);
	}
	if (f2)
	{
		sort(a + 1, a + n + 1, greater<int>());
		printf("%d\n", a[m]);
		exit(0);
	}
	if (f3)
	{
		int i = 1;
		while (i < n && m > i)
			i <<= 1;
		printf("%d\n", n - i);
		exit(0);
	}
	if (m == n - 1)
	{
		pre1[1] = a[1];
		pre2[n] = a[n];
		for (int i = 2; i <= n; ++i)
			pre1[i] = pre1[i - 1] & a[i];
		for (int i = n - 1; i >= 1; --i)
			pre2[i] = pre2[i + 1] & a[i];
		for (int i = 1; i <= n; ++i)
		{
			int res;
			if (i == 1)
				res = pre2[2];
			else if (i == n)
				res = pre1[n - 1];
			else
				res = pre1[i - 1] & pre2[i + 1];
			if (res > ans)
				res = ans;
		}
		printf("%d\n", ans);
	}
	return 0;
}
