#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
struct K
{
	int a;
	char b;
}dp[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> dp[i].a >> dp[i].b;
	}
	int l = 1,r = n;
	long long ans = 0;
	while(l < r)
	{
		if(dp[l].b == dp[r].b && dp[l].a >= dp[r].a)
		{
			dp[l].a -= dp[r].a;
			r--;
			if(dp[l].a == 0)
			{
				l++;
			}
		}
		else if(dp[l].b == dp[r].b && dp[l].a < dp[r].a)
		{
			dp[r].a -= dp[l].a;
			l++;
		}
		else if(dp[l].b != dp[r].b && dp[l].a >= dp[r].a)
		{
			dp[l].a -= dp[r].a;
			ans += dp[r].a;
			r--;
			if(dp[l].a == 0)
			{
				l++;
			}
		}
		else if(dp[l].b != dp[r].b && dp[l].a < dp[r].a)
		{
			ans += dp[l].a;
			dp[r].a -= dp[l].a;
			l++;
		}
		//cout << l << " " << r<< endl;
	}
	cout << ans;
	return 0;
}
