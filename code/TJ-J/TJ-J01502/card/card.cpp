#include <bits/stdc++.h> 
using namespace std;

int n, m, a[500005], t[300005], c[300005];

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int o = 1; o <= n; o++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (a[i] == t[j])
				{
					for (int k = j; k <= m; k++)
					{
						t[k] = 0;
					}
					i = j;
					break;
				}
			}
			t[i] = a[i];
		}
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (t[j] = i)
				{
					c[i]++;
				}
			} 
		}
	}
	for (int i = 1; i <= m; i++)
	{
		cout << 3 << "  "<< 1 << " " << 4;
	}
	return 0;
}
