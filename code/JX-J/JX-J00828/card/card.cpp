#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m, cnt = 0, a[500005] = {0}, mp[500005] = {0}, js[500005] = {0};
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		for(int j = 1; j <= cnt; j++)
		{
			if(mp[j] == a[i])
			{
				for(int k = j; k <= cnt; k++)
				{
					mp[k] = 0;
				}
			}
		}
		cnt++;
		mp[cnt] = a[i];
		for(int j = 1; j <= m; j++)
		{
			int f = 0;
			for(int k = 1; k <= cnt; k++)
			{
				if(mp[k] == j)
				{
					f = 1;
				}
			}
			if(f == 1)
			{
				js[j]++;
			}
		}
	}
	for(int i = 1; i <= m; i++)
	{
		cout << js[i] << " ";
	}
	return 0;
}
