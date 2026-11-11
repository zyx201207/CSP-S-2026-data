#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[300005], b[300005];
bool chachong(int c, int i, int n)
{
	int sum;
	for(; i <= n; i++)
	{
		if (a[i] == c)
		{
			sum++;
		}
	}
	if (sum == 1)
	{
		return true;
	}
	return false;
}
int xiabiao(int c, int i, int n)
{
	for(; i <= n; i++)
	{
		if (a[i] == c)
		{
			return i;
		}
	}
}
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	int ans;
	for (int i = 1; i <= n; i++)
	{
		int q = 0;
		ans = 0;
		for (int j = i-(i-1); j <= n; j++)
		{
			if (chachong(a[j], i-(i-1), j))
			{
				b[j] = a[j];
			}
			else
			{
				q = xiabiao(a[j], i-(i-1), j);
				memset(b+q, 0, sizeof(b) - q);
			}
		}
		if (q > i)
		{
			ans++;
		}
		else
		{
			continue;
		}
	}
	cout << ans;
	return 0;
}