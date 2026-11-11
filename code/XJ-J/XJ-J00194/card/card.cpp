#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin)
	freopen("card.out","w",stdout)
	int n,m;
	cin >> n >> m;
	vector<int> a(n);
	for(int i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	vector<int> dp(n);
	int s = -1;
	for(int i = 0;i < n;i++)
	{
		s++;
		dp[s] = a[i];
		bool flag = 0;
		int j;
		for(j = 0;j <= i;j++)
		{
			if (dp[j] = a[i])
			{
				flag = 1;
			}
		}
		if(flag)
		{
			for(int k = j;k <= s;k++)
			{
				dp[k]=0;
			}
			dp[i-j] = a[i];
			s = i-j;
		}
		int ans = 0;
		for(int i = 0;i < n;i++)
		{
			if (dp[i] == a[i])
			{
				ans++;
			}
		}
		cout << ans << " ";
	}
	return 0;
 } 
