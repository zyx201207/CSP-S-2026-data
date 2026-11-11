#include <bits/stdc++.h>
using namespace std;
long long n, m, a, num, cnt[100000000],ant;
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a;
		cnt[i] = a;
	}
	if (m == 2)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				ant = (cnt[i] & cnt[j]);
				if (num < ant) num = ant;
				
			}
		}
	}
	else if (m == 3)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				for (int k = j; j <= n; j++)
				{
					ant = (cnt[i] & cnt[j]);
					if (num < ant) num = ant;
				}
					
				
			}
		}
	}
	else if (m == 4)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				for (int k = j; j <= n; j++)
				{
					for (int l = k + 1; l <= n; l++)
					ant = (cnt[i] & cnt[j] & cnt[k] & cnt[l]);
					if (num < ant) num = ant;
				}
					
				
			}
		}
	}
	cout << num;
	return 0;
}