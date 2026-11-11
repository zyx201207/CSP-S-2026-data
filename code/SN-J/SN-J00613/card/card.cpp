#include<bits/stdc++.h>
using namespace std ;
int main()
{
	freopen("card.in" , "r" , stdin) ;
	freopen("card.out" , "w" , stdout) ;
	int n , m ;
	cin >> n >> m ;
	int a[n + 5] ;
	int ans[n + 5] = {0} ;
	for (int i = 1 ; i<= n ; i++)
	{
		cin >> a[i] ;
	}
	int card[n + 5] = {0} , total[n + 5] = {0} ;
	for (int i = 1 ; i <= n ; i++)
	{
		for (int j = i ; j <= n ; j++)
		{
			if(total[a[i]] == 0)
			{
				card[j - i + 1] = a[i] ;
				total[a[i]] = 1 ;
			}
			else
			{
				int same = 0 ;
				total[a[i]] = 0 ;
				for (int k = 0 ; k <= n ; k++)
				{
					if(card[k] == a[i])
					{
						card[k] = a[i] ;
						same = k ;
						break ;
					}
				}
				for (int k = same ; k <= n ; k++)
				{
					card[k] = 0 ;
				}
			}
		}
		for (int j = 1 ; j <= n ; j++)
		{
			for (int k = 0 ; k <= n ; k++)
			{
				if(card[k] == j)
					ans[j] += 1 ;
			}
		}
	}
	for (int i = 1 ; i <= m ; i++)
	{
		cout << ans[i] << " " ;
	}
	return 0 ;
}
