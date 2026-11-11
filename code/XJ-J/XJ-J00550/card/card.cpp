#include <bits/stdc++.h>
using namespace std;
long long n, m, card[500005], vis[300005], ans[300005], r[300005];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin>>n>>m;
	for (long long i=1; i<=n; i++)
	{
		cin>>card[i];
	}
	for (int i=1; i<=n; i++)
	{
		vis[i] = i;
	}

	for (int i=1; i<=n; i++)
	{
		ans[card[i]] += vis[i];
	}
	for (int i=n; i>=1; i--)
	{
		int flag = 0;
		for (int j=1; j<i; j++)
		{
			if (card[j] == card[i])
			{
				flag = 1;
			}
			if (flag)
			{
				ans[j]--;
			}
		}
	}
	for (int i=1; i<=m; i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}