#include<cstdio>
#include<algorithm> 
const int MAXN = 2000010;
int c, T;
int n;
long long d, x[MAXN];
int dp[MAXN];
long long cnt[MAXN];
long long sum[MAXN];
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &T);
	for(int _ = 1; _ <= T; ++ _)
	{
		scanf("%d%lld", &n, &d);
		for(int i = 1; i <= n; ++ i) scanf("%lld", &x[i]);
		long long ans = 0;
		for(int i = 1; i <= n; ++ i)
		{
			sum[i - 1] = 0;
			for(int j = i, l = i, r = i; j <= n; ++ j)
			{
				if(j == i) dp[j] = 0, cnt[j] = 1, sum[j] = 1;
				else dp[j] = 0x3f3f3f3f, cnt[j] = 0;
				while(l < j && x[j] - x[l] > d) l ++;
				while(r + 1 < j && (dp[r] == dp[r + 1] || l > r)) r ++;
				if(l == j) continue;
				if(r == j) continue;
				if(l > r) continue;
				dp[j] = dp[l] + 1;
				if(dp[j] < 0x3f3f3f3f) cnt[j] += sum[r] - sum[l - 1];
				sum[j] = sum[j - 1] + cnt[j];
				ans += cnt[j] == 2;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
