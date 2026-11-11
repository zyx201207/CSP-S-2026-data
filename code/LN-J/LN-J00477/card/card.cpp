#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
const int M = 300005;
int n , m , a[N];
int stk[N] , l , r , num[M];
int main()
{
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout);
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
	}
	for (int i = 1 ; i <= n ; i++)
	{
		l = 1 , r = 0;
		for (int j = i ; j <= n ; j++)
		{
			int pos = r + 1;
			for (int k = l ; k <= r ; k++)
			{
				if (stk[k] == a[j])
				{
					pos = k;
					break;
				}
			}
			for (int k = r ; k >= pos ; k--)
			{
				r--;
			}
			stk[++r] = a[j];
		}
		for (int j = l ; j <= r ; j++)
		{
			num[stk[j]]++;
		}
	}
	for (int i = 1 ; i <= m ; i++)
	{
		cout << num[i] << " ";
	}
	return 0;
}
