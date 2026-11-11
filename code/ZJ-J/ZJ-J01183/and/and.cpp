#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, m;
int a[N];

int sum = 0;
inline void dfs(int i, int c, int num)
{
	if (c == m)
	{
		sum = max(sum, num);
		return;
	}
	
	if (n - i + 1 < m - c)
		return;
		
	if (num < sum)
		return;
	
	if (!c)
		dfs(i + 1, c + 1, a[i]);
	else
		dfs(i + 1, c + 1, num & a[i]);
	dfs(i + 1, c, num);
}

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin >> n >> m;
	
	bool f = 0, f1 = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] > 4)
			f1 = 1;
		int x = a[i];
		while (x)
		{
			if (!(x & 1))
				f = 1;
			x >>= 1;
		}
	}
		
	if (m == 1)
	{
		int ans = 0;
		for (int i = 1; i <= n; i++)
			ans = max(ans, a[i]);
		cout << ans;
		return 0;
	}
	
	if (m == 2)
	{
		int ans = 0;
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
				ans = max(ans, a[i] & a[j]);
		cout << ans;
		return 0;
	}
	
	if (!f)
	{
		sort(a + 1, a + 1 + n);
		int ans = a[n];
		for (int i = n - 1; i >= n - m + 1; i--)
			ans &= a[i];
		cout << ans;
		return 0;
	}
	
	if (!f1)
	{
		int cnt[5];
		for (int i = 1; i <= n; i++)
			cnt[a[i]]++;
		if (cnt[3] >= m)
			cout << 3;
		else if (cnt[3] + cnt[2] >= m)
			cout << 2;
		else if (cnt[3] + cnt[1] >= m)
			cout << 1;
		else
			cout << 0;
		return 0;
	}
	
	if (m == n)
	{
		int ans = a[1];
		for (int i = 2; i <= n; i++)
			ans &= a[i];
		cout << ans;
		return 0;
	}
	
	sort(a + 1, a + 1 + n, [](int x, int y)
	{
		return x > y;
	});
	
	dfs(1, 0, 0);
	
	cout << sum;
	
	return 0;
}