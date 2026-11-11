#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,T;
int n,d,a[5005];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> T;
	while (T--)
	{
		int ans = 0;
		cin >> n >> d;
		for (int i = 0;i < n;i++)
		{
			cin >> a[i];
		}
		for (int p = 0;p < n - 2;p++)
		{
			bool b[n];
			int sum[n];
			memset(b,0,sizeof(b));
			b[a[p] - 1] = true;
			vector<int> dp[n];
			dp[0].push_back(a[p]);
			//i->level,j->dp[level][value],k->a[value]
			for (int i = 0;i < n;i++)
			{
				memset(sum,0,sizeof(sum));
				for (int j = 0;j < dp[i].size();j++)
				{
					for (int k = i + j + 1;k < n;k++)
					{
						if (a[k] - dp[i][j] <= d)
						{
							dp[i + 1].push_back(a[k]); 
							sum[k]++;
						}
					}
				}
				for (int j = 0;j < n;j++) 
				{
					//cout << sum[j] << ' '; 
					if (sum[j])
					{	
						if (!b[j] && sum[j] == 2)
						{
							ans++;
						}
						b[j] = true;
					}
				}
				//cout << "\n"; 
			}
			//cout << "\n";
		}
		cout << ans << "\n";
	}
}
