#include <bits/stdc++.h>
using namespace std;
long long a[500010] , ans = 1 , dp[500010] , t[500010] , maxn = -1 , x;
int main()
{
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);	
	int n , k;
	cin >> n >> k;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		maxn = max(maxn , a[i]); 
	}
	if(k == 1)
	{
		cout << maxn;
		return 0;
	}
	
	for(int i = 0; i < k; i++)
	{
		int maxt = 0;
		for(int j = 0; j < n; j++) 
		{
			if(a[j] >= maxt)
			{
				maxt = a[j];
				x = j;
			}
		}
		a[x] = -1;
		if(i == 0) ans = maxt;
		else ans &= maxt;
	}
	cout << ans;
	return 0;
}
