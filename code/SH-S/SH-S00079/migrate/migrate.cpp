#include<bits/stdc++.h>
using namespace std;
#define int long long
int x[2000006],dp[2][2000006];
signed main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	if(c == 11 || c == 12)
	{
		while(t--)
		{
			int n,d;
			cin >> n >> d;
			int k;
			for(int i = 0;i < n;i++)
			{
				cin >> x[i];
				if(x[i]-x[0] <= d)k = i;
			}
			if(k == 0 || k == 1)cout << 0 << endl;
			else cout << max(n-2*k+1,(long long)0) << endl;
		}
		return 0;
	}
	while(t--)
	{
		int n,d;
		cin >> n >> d;
		for(int i = 0;i < n;i++)
		{
			cin >> x[i];
		}
		int ans = 0;
		for(int i = 0;i < n;i++)
		{
			memset(dp,0,sizeof(dp));
			dp[1][i] = 1;
			for(int j = 0;j < n;j++)
			{
				memset(dp[j%2],0,sizeof(dp[j%2]));
				for(int k = 0;k < n;k++)
				{
					for(int l = 1;l+k < n;l++)
					{
						if(x[k+l]-x[k] > d)break;
						dp[j%2][k+l] += dp[j%2^1][k];
					}
					if(dp[j%2][k] == 2 && dp[j%2^1][k] == 0)ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
