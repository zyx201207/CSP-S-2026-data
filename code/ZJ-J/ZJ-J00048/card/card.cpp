#include <bits/stdc++.h>
using namespace std;
int n, m, cnt = 0, a[500010], stk[500010], used[300010], ans[300010];

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
	memset(used, 0, sizeof(used));
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			if (used[a[j]])
			{
				int flag = 0;
				while (flag < used[a[j]])
				{
					int x = stk[cnt];
					cnt--;
					used[x]--;
					if (x == a[j]) flag++;
				}
			}
			stk[++cnt] = a[j];
			used[a[j]]++;
		}
		for (int i = 1; i <= cnt; i++) ans[stk[i]]++;
		memset(used, 0, sizeof(used));
		cnt = 0;
	}
	for (int i = 1; i <= m; i++) printf("%d ", ans[i]);
	return 0;
}