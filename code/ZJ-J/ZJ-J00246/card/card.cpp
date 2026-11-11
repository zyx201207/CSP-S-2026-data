#include<bits/stdc++.h>
using namespace std;
int n, m, a[500010], ans[500010], w[500010], d[500010], top;
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++)
	{
		top = 0;
		for(int j = 1; j <= m; j++)
		{
			w[j] = 0;
		}
		for(int j = i; j <= n; j++)
		{
			if(w[a[j]] == 0)
				w[a[j]] = ++top;
			else
			{
				for(int k = w[a[j]]; k <= top; k++)
				{
					w[a[k]] = 0;
				}
				w[a[j]] = ++top;
			}
		}
		for(int j = 1; j <= m; j++)
		{
			if(w[j] != 0)
			{
				ans[j]++;
			}
		}
	}
	for(int i = 1; i <= m; i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}