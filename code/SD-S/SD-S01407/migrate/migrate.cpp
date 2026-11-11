#include<bits/stdc++.h>
#define int long long
#define MX 2000000
using namespace std;
int c,T,n,d,a[MX + 10],ans;
pair<int,int> dp[MX + 10];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> T;
	while (T--)
	{
		cin >> n >> d;
		ans = 0;
		for (int i = 1;i <= n;i++) cin >> a[i];
		for (int i = 1;i <= n;i++)//枚举dp的起点
		{
			for (int j = 1;j <= i;j++) dp[j].first = dp[j].second = 0;
			dp[i] = {1,0};
			for (int j = i + 1;j <= n;j++)//枚举dp终点 
			{
				int r = j - 1,mn = 0x3f3f3f3f3f3f3f3f;
				dp[j] = {0,0};
				while(r >= i && a[j] - a[r] <= d)
				{
					mn = min(mn,dp[r].second);
					r--;
				}
				r = j - 1;
				while (r >= i && a[j] - a[r] <= d)
				{
					if (dp[r].second == mn) dp[j].first += dp[r].first;
					r--;
				}
				if (dp[j].first == 2) ans++;
				dp[r].second = mn + 1;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
