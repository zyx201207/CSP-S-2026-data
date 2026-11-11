#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6 + 5;
ll C, T, n, d, a[N], dp[N], cnt[N], res[N], now, ans;
deque<ll> q;
void solve1()
{
	ll tmp = d / (a[2] - a[1]);
	if(d == 0 || d == 1)
	{
		printf("0\n");
		return;
	}
	printf("%lld\n", max(0ll, n - (tmp * 2 - 1)));
}
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	scanf("%lld%lld", &C, &T);
	while(T--)
	{
		ans = 0;
		scanf("%lld%lld", &n, &d);
		for(int i = 1; i <= n; i++)
		{
			scanf("%lld", &a[i]);
		}
		if(C == 11 || C == 12)
		{
			solve1();
			continue;
		}
		for(int i = 1; i <= n; i++)
		{
			now = i;
			dp[i] = cnt[i] = res[i] = 1;
			while(!q.empty())
			{
				q.pop_back();
			}
			q.push_back(i);
			for(int j = i + 1; j <= n; j++)
			{
				while(!q.empty() && a[j] - a[q.front()] > d)
				{
					q.pop_front();
				}
				if(q.empty())
				{
					dp[j] = 0;
					break;
				}
				dp[j] = dp[q.front()] + 1;
				cnt[j] = 0;
				for(int k = q.front(); k <= q.back(); k++)
				{
					if(dp[k] != dp[q.front()])
					{
						break;
					}
					cnt[j] += cnt[k];
				}
				while(!q.empty() && dp[q.back()] > dp[j])
				{
					q.pop_back();
				}
				q.push_back(j);
				if(cnt[j] == 2)
				{
					ans++;
				}
			}
//			ll l = i, r = i;
//			for(int j = i + 1; j <= n; j++)
//			{
//				while(l < j && dp[l] != dp[j] - 1)
//				{
//					l++, r++;
//				}
//				while(r < j && dp[r] == dp[j] - 1)
//				{
//					r++;
//				}
//				r--;
//				cnt[j] = res[r] - res[l - 1];
//				res[j] = res[j - 1] + cnt[j];
//				if(cnt[j] == 2)
//				{
//					ans++;
//				}
//			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
