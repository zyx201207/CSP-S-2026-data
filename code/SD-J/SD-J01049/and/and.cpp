#include <bits/stdc++.h>
using namespace std;
int n,a[200005],m;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	if (m == 1)
	{
		int maxn = -1;
		for (int i = 1;i <= n;i++)
		{
			maxn = max(maxn,a[i]);
		}
		cout << maxn;
		return 0;
	}
	if (m == n)
	{
		int ans = a[1];
		for (int i = 2;i <= n;i++)
		{
			ans = ans & a[i];
		}
		cout << ans;
		return 0;
	}
	if (m == 2)
	{
		int maxn = -1;
		for (int i = 1;i <= n;i++)
		{
			for (int j = i + 1;j <= n;j++)
			{
				maxn = max(maxn,a[i] & a[j]);
			}
		}
		cout << maxn;
		return 0;
	}
	return 0;
}

