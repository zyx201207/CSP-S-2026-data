#include <bits/stdc++.h>
#define int long long
#define maxn 500010
#define maxm 300010
using namespace std;
int n, m;
int a[maxn];
int cnt[maxm];
int vis[maxm];
bool flag;
signed main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
	{
		cin >> a[i];
		if (a[i] < a[i-1])
			flag = 1;
	}	
	if (flag)
		for (int p = 1; p <= n; p ++)
		{
			for (int i = 1; i <= m; i ++)
				vis[i] = 0;
			for (int i = p; i <= n; i ++)
			{
				if (vis[a[i]])
				{
					for (int j = vis[a[i]]; j < i; j ++)
						vis[a[j]] = 0;
				}
				vis[a[i]] = i;
			}
			for (int i = 1; i <= m; i ++)
				if (vis[i])
				{
					cnt[i]++;
				}
		}
	else
	{
		for (int i = n; i >= 1; i --)
		{
			if (vis[a[i]])
			{
				for (int j = vis[a[i]] - 1; j > i; j --)
					vis[a[j]] = 0;
			}
			vis[a[i]] = i;
			for (int j = 1; j <= m; j ++)
			{
				if (vis[j])
				{
					cnt[j] ++;
				}
//				cout << j << "**** ***" << vis[j] << ' ' << cnt[j] << '\n';
			}
		}
	}
	for (int i = 1; i <= m; i ++)
		cout << cnt[i] << ' ';
	cout << '\n';
	return 0;
}
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1
*/
