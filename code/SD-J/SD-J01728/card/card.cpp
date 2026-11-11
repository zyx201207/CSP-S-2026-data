#include <bits/stdc++.h>
using namespace std;
int n, m, a[1000005], s[1000005];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	int t = n, k = 1;
	while(t--)
	{
		int num[1000005] = {0};
		for (int i = k; i <= n; i++)
		{
			num[i] = 1;
			for (int j = 1; j <= i; j++)
			{
				if (num[j] == num[i])
				{
					for (int l = j; l <= i; l++)
					{
						num[l] = 0;
					}
				}
			}
		}
		for (int i = k; i <= n; i++)
		{
			s[num[i]]++;
		}
		k++;
	}
	for (int i = 1; i <= m; i++)
	{
		cout << s[i] << ' ';
	}
	return 0;	
} 
