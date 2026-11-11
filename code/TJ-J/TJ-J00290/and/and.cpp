#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 5;
int n, m, a[N], ans = 0b1111111111111111111111111111111;
bool f[N];
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", a + i);
		f[i] = 1;
	}
	for (int i = 30; i >= 0; i--)
	{
		int cnt = 0;
		for (int j = 1; j <= n; j++)
		{
			if (!f[j]) continue;
			//printf("%d ", a[j]);
			if (a[j] & (1 << i))
			{
				cnt++;
			}
		}
		//printf("\n");
		//printf("cnt:%d\n", cnt);
		if (cnt >= m)
		{
			//printf("deleted:");
			for (int j = 1; j <= n; j++)
			{
				if (!f[j]) continue;
				if (!(a[j] & (1 << i)))
				{
					//printf("%d ", a[j]);
					f[j] = 0;
				}
			}
			//printf("\n");
			if (cnt == m)
				break;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (!f[i]) continue;
		ans = ans & a[i];
	}
	printf("%d", ans);
	return 0;
}