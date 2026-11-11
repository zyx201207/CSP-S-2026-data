#include <bits/stdc++.h>
using namespace std;
long long a[500010] , ans , dp[500010] , t[500010] , maxn = -1 , x;
int main()
{
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout);	
	int n , k;
	cin >> n >> k;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		if(i >= 1 && a[i] != a[i - 1]) x = 1;
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = i; j < n; j++)
		{
			dp[a[j]]++;
			
		}
	}
	for(int i = 0; i < n; i++)
	{
		cout << dp[a[i]] << ' ';
		if(x == 0) return 0;
	}
	return 0;
}
