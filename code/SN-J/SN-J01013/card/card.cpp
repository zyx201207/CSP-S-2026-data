#include <bits/stdc++.h>
using namespace std;
int n , m ,a[1000005],z[1000005],cnt , k;
int main()
{
	
	freopen("card.in" , "r",stdin);
	freopen("card.out" , "w",stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n; i ++)
	{
		cin >> a[i];
	}
	for(int i = 1; i <= n; i ++)
	{
		int k = a[i];
		for(int j = 1 ; j <= n; j ++)
		{
			z[j] = a[i];
			if(z[j] == k)
			{
				for(int l = 1 ; l <= n; l ++)
				{
					if(a[l] == k)
					{
						for(int u =l ; u <= n ; u++)
						{
							a[u] = 0;
						}
					}
				}
				z[j+1] == k;
			}
			else
			{
				z[k] = k;
			}
		}
		for(int i = 1 ; i<= n; i++)
		{
			if(a[i] == i)
				cnt++;
		}
	}
	cout << cnt;
	return 0;
}
