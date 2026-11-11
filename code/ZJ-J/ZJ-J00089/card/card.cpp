#include <bits/stdc++.h>
using namespace std;
int n, m, a[5005][3005], cnt[3005];
int main ()
{
	freopen ("card.in", "r",stdin);
	freopen ("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[1][i];
		cnt[a[1][i]]++;
		
	}
	
	for (int i = 2; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			cnt[a[1][j]]++;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			bool flag = 1;
			for (int k = j+1; k <= n; k++)
			{
				if (a[1][k] == a[1][j])
				{
					for (int l = j; l < k; l++)
					{
						cnt[a[1][l]]--;
					}
					j = k-1;
					break;
				}
			}
		}
	}
	
	for (int i = 1; i <= m; i++)
	{
		cout << cnt[i]<< " ";
	}
	return 0;
}
