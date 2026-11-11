#include <bits/stdc++.h>
#define endl '\n'
#define ull unsigned long long
using namespace std;

const int N = 5e5 + 10, M = 3e5 +10;

ull n, m;
ull a[N], ans[M];
ull st[N], id[M], tot = 1;

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	
	cin >> n>> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	
	for (int i = 1; i <= n; i++)
	{
		tot = 1;
		memset(id, -1, sizeof id);
		
		for (int j = i; j <= n; j++)
		{
			if (id[a[j]] != -1)
			{
				for (int m = id[a[j]] + 1; m < tot; m++)
				{
					id[st[m]] = -1;
				}
				tot = id[a[j]];
				tot++;
				continue;
			}

			id[a[j]] = tot;
			st[tot] = a[j];
			tot++;
		}
		for (int j = 1; j < tot; j++)
		{
			ans[st[j]]++;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		cout << ans[i] <<" ";
	}
	
	return 0;
}
