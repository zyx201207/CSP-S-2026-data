#include <bits/stdc++.h>
using namespace std;

int a[2000010];

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	for (int w = 1;w <= t;w++)
	{
		int n, d, ans = 0;
		cin >> n >> d;
		memset(a, 0, sizeof(a));
		for (int i = 1;i <= n;i++)
		{
			cin >> a[i];
		}
		for (int i = 1;i < n;i++)
		{
			for (int j = i + 1;j <= n;j++)
			{
				int x = i, s1 = 1, s2 = 1;
				for (int ij = i;ij <= j;ij++)
				{
					if (ij + 1 > j)
					{
						s1 += 1;
						break;
					} 
					if (a[ij + 1] - a[x] > d)
					{
						s1 += 1;
						x = ij;
					}
					if (a[ij + 1] - a[x] == d)
					{
						s1 += 1;
						x = ij + 1;
					}
				}
				x = j;
				for (int ij = j;ij >= i;ij--)
				{
					if (ij - 1 < i)
					{
						s2 += 1;
						break;
					}
					if (a[x] - a[ij-1] > d)
					{
						s2 += 1;
						x = ij;
					}
					if (a[x] - a[ij - 1] == d)
					{
						s2 += 1;
						x = ij - 1; 
					}
				}
				if (s1 == s2) ans += 1;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
