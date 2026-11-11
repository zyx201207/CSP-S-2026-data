#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m, a[500005], ans[500005], la[500005], ne[500005];
signed main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if(la[a[i]] == 0)
		{
			la[a[i]] = i;
		}
		else
		{
			ne[la[a[i]]] = i;
			la[a[i]] = i;
		}
	}
	for(int i = 0;i < n;i++)
	{
		for(int j = 1+i;j <= n;j++)
		{
			if(ne[j] == 0)
			{
				ans[a[j]]++;
			}
			else
			{
				j = ne[j] - 1;
			}
		}
	}
	for(int i = 1;i <= m;i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}
