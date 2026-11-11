#include <iostream>
using namespace std;
long long a[1000010];
long long dp[1000010];
int main()
{
	freopen("and.in","r",stdin);
	
	freopen("and.out","w",stdout);
	
	long long n;
	cin>>n;
	long long m;
	cin>>m;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
	}
	//ÀàËÆÓÚ01±³°ü dp[j] = max(dp[j],dp[j-m]&a[i]) 
	for(int i = 1;i<=n;i++)
	{
		for(int j =m;j>=1;j--)
		{
			dp[j]=max(dp[j],dp[j-m]&a[i]);
		}
	}
	cout<<dp[n];
	return 0;
} 
