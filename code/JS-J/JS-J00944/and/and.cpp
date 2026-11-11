#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long int n,m;
	cin>>n>>m;
	vector<int> num(n+1);
	vector<int> maxn(n+1,-999);
	for(int i  = 1;i<=n;i++)
	{
		cin>>num[i];
		if(i == 1)
			maxn[i] = num[i];
		else
			maxn[i] = max(maxn[i-1],num[i]);
	}
	vector<int> dp(m+1);
	for(int i = 1;i<=n;i++)
	{
		for(int j = m;j>=0;j--)
		{
			if(j == 0)
				dp[j] = 0;
			else if(j == 1)
				dp[j] = maxn[i];
			else if(j > i)
				dp[j] = 0;
			else
				dp[j] = max(dp[j],dp[j-1] & num[i]);
		}
	}
	cout<<dp[m];
}
