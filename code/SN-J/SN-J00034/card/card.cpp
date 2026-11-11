#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 6; 
int n, m, a[N], q[N], k, o[N];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	} 
	for (int i = 1; i <= n; i++)
	{
		k = 0;
		memset(q, 0, sizeof(q));
		for (int j = i; j <= n; j++)
		{
			k++;
			for (int l = 1; l <= k; l++)
			{
				if (q[l] == a[j])
				{
					k = l; 
				}
			}
			q[k] = a[j];
		}
		for (int j = 1; j <= k; j++)
		{
			o[q[j]] ++;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		cout << o[i] << " ";
	}
	return 0;
}
