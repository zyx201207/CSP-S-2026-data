#include<bits/stdc++.h> 
using namespace std;
long long A[500010],dp[500010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long i,n,j,z,k;
	for( i = 1 ; i <= n ; i++ )
	{
		cin >> A[i];
	}
	for( i = 2 ; i <= n ; i++ )
	{
		k = 0;
		for( j = 1 ; j < i ; j++ )
		{
			if( A[i] == A[j] )
			{
				
			}
		}
	}
	
	return 0;
}
