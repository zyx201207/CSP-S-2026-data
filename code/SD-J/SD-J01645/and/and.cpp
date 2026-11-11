#include<bits/stdc++.h> 
using namespace std;
long long A[200040],dp[200040];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,j,i,m;
	cin >> n >> m;
	for( i = 1 ; i <= n ; i++ )
	{
		cin >> A[i];
	}
	for( i = 1 ; i <= n ; i++ )
	{
		for( j = n ; j >= i ; j-- )
		{
			dp[i] = max( dp[i - 1] , dp[i - 1+ A[i]] ) ;
		}
	}
	cout << dp[n];
	return 0;
}
