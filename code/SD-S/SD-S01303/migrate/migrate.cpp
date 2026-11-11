#include <bits/stdc++.h>
using namespace std;
const int N = 2e6+10;
int c, t, n;
long long d;
long long a[N];
long long dp[N][2], sum[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	if(c>=11&&c<=12)
	{
		while(t--)
		{
			cin >> n >> d;
			for(int i = 1; i <= n; i++) cin >> a[i];
			cout << max(0, n-2k+1) << endl;
		}
	}
	else
	while(t--)
	{
		cin >> n >> d;
		for(int i = 1; i <= n; i++) cin >> a[i];
		long long cnt = 0;
		for(int j = 1; j <= n; j++)
		{
			a[j-1] = -0x3f3f3f3f3f3f3f3f;
			dp[j][0] = 1, dp[j][1] = 0;
			sum[j] = 1;
			sum[j-1] = 0;
			bool f = 0;
			for(int i = j+1; i <= n; i++)
			{
				if(f)
				{
					dp[i][0] = -0x3f3f3f3f3f3f3f3f;
					dp[i][1] = -1;
					continue;
				}
				int l = j, r = i;
				while(l != r)
				{
					int mid = l + r >> 1;
					if(a[i]-a[mid] <= d) r = mid;
					else l = mid + 1;
				}
				if(l==i)
				{
					dp[i][0] = -0x3f3f3f3f3f3f3f3f;
					dp[i][1] = -1;
					f = 1;
					continue;
				}
				int l2 = l, r2 = i-1;
				while(l2 != r2)
				{
					int mid = l2 + r2 + 1 >> 1;
					if(dp[mid][1]==dp[l][1]) l2 = mid;
					else r2 = mid - 1;
				}
				dp[i][1] = dp[l][1]+1;
				dp[i][0] = sum[l2]-sum[l-1];
				sum[i] = sum[i-1]+dp[i][0];
			}
			for(int i = j+1; i <= n; i++) if(dp[i][0]==2) cnt++;	
		}
		cout << cnt << endl;
	}
	return 0;
}

