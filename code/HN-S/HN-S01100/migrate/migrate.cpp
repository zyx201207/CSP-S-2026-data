#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;
int c, t;
vector<long long> a;

struct Node{
	long long len, cnt;
};

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t --)
	{
		long long n, d;
		cin >> n >> d;
		a = vector<long long>(n + 1);
		for(int i = 1; i <= n; i ++)
		{
			cin >> a[i];
		}
		Node dp[n+1][n+1];
		for(int i = 1;i <= n;i ++)
		{
			for(int j = 1;j <= n;j ++)
			{
				if(i == j)
				{
					dp[i][j].len = 0;
					dp[i][j].cnt = 0;
				}
				else
				{
					dp[i][j].len = LONG_LONG_MAX;
					dp[i][j].cnt = 1;
				}
			}
		}
		long long ans = 0;
		for(int i = 1; i <= n; i ++)
			for(int j = i + 1;j <= n;j ++)
			{
				
				if(a[j] - a[i] <= d)
				{
				
					dp[i][j].len = 1;
					dp[i][j].cnt = 1;
				}
				else
				{
					
					for(int k = j - 1;k >= i;k --)
						if(a[j] - a[k] <= d)
							if(dp[i][j].len > dp[i][k].len + 1)
							{
								dp[i][j].len = dp[i][k].len + 1;
								dp[i][j].cnt = dp[i][k].cnt;
							}
							else if(dp[i][j].len == dp[i][k].len + 1) dp[i][j].cnt ++;
				}
			}
		for(int i = 1;i <= n;i ++)
		{
			for(int j = 1;j <= n;j ++)
			{
//				cout << dp[i][j].cnt << ' ';  
				if(dp[i][j].cnt == 2)
				{
					ans ++;
				}
			}
//			cout << '\n';
		}
//		cout << dp[2][4].len << ' ';
		cout << ans << '\n'; 
	}
	return 0;
}
