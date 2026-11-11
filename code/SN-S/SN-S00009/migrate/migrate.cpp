#include <bits/stdc++.h>
using namespace std;
int c, t;
int main()
{
	freopen("migrate.in", "r", stdin);
 	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--)
	{
		long long n, d, x[300], num[300][300], lu[300][300];
		memset(num, 0, sizeof(num));
		memset(lu, INT_MAX, sizeof(lu));
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
		{
			cin >> x[i];
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				if (abs(x[i] - x[j]) <= d)
				{
					if (1 < lu[i][j])
					{
						lu[i][j] = 1;
						num[i][j] = 1;
					}
					else if (1 == lu[i][j])
					{
						num[i][j]++;
					}
				}
				else if (abs(x[i] - x[j]) > d)
				{
					for (int l = i; l <= j; l++)
					{
						if (abs(x[i] - x[l]) <= d and abs(x[l] - x[j]) <= d)
						{
							if (2 < lu[i][j])
							{
								lu[i][j] = 2;
								num[i][j] = 1;
							}
							else if (2 == lu[i][j])
							{
								num[i][j]++;
							}
						}
					}
				}
			}
		}
		int sum = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				if (num[i][j] == 2)
				{
					sum++;
				}
			}
		}
		cout << sum << '\n'; 
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
