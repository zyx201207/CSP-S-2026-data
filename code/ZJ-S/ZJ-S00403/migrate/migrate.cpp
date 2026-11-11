#include<bits/stdc++.h>
using namespace std;
#define int long long

inline int read()
{
	char c;
	int sum = 0, aa = 1;
	while(c < '0' || c > '9')
	{
		if (c == '-') aa = -1;
		c = (char)getchar();
	}
	while(c >= '0' && c <= '9') sum = sum * 10 + (int)(c - '0'), c = (char)getchar();
	return sum * aa;
}

int c, t, n, m, a[2000010], sum[5010], r[5010], cnt[5010];

signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	c = read(), t = read();
	while(t--)
	{
		n = read(), m = read();
		for (int i = 1; i <= n; i++) a[i] = read();
		if (c <= 10)
		{
			int ans = 0;
			for (int i = 1; i <= n; i++)
			{
				memset(cnt, 0, sizeof(cnt));
				int aa = i;
				sum[i] = 0, r[0] = i, cnt[i] = 1;
				for (int j = i + 1; j <= n; j++)
				{
					if (a[j] - a[j - 1] > m) break;
					while(a[j] - a[aa] > m) aa++;
					sum[j] = sum[aa] + 1, r[sum[j]] = j;
					cnt[j] = cnt[r[sum[j] - 1]] - cnt[aa - 1];
					if (cnt[j] == 2) ans++;
					cnt[j] += cnt[j - 1];
				}
			}
			printf("%lld\n", ans);
		}
		else if (c <= 12)
		{
			if (n == 1)
			{
				printf("0\n");
				continue;
			}
			int aa = m / (a[2] - a[1]);
			if (aa <= 1)
			{
				printf("0\n");
				continue;
			}
			aa = aa * 2 - 1;
			int ans = n - aa;
			printf("%lld\n", max(0ll, ans));
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}