#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[2000010];
struct node
{
	int st,cnt;
};
node dp[2000010];
#define int int
int main()
{
#define int long long
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >>t;
	while(t--)
	{
		int n,d,ans = 0;
		cin >> n >> d;
		for (int i = 1;i <= n;i++)
			cin >> a[i];
		for (int s = 1;s <= n;s++)
		{
			for (int i = 1;i <= n;i++)
				dp[i].st = 1e9,dp[i].cnt = 0;
			dp[s].st = 0,dp[s].cnt = 1;
			for (int i = s;i <= n;i++)
				for (int j = i - 1;j >= s && a[i] - a[j] <= d;j--)
					if(dp[i].st > dp[j].st + 1)
						dp[i].cnt = dp[j].cnt,dp[i].st = dp[j].st + 1;
					else if (dp[i].st == dp[j].st + 1)
						dp[i].cnt += dp[j].cnt;
			for (int i = s;i <= n;i++)
				if(dp[i].cnt == 2) 
					ans++;
//				cout << dp[i].cnt << " \n"[i == n];
		}
		cout << ans << endl;
	}
	return 0;
 } 
