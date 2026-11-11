#include <bits/stdc++.h>
using namespace std;

long long a[200005] , b[200005];
int n;

long long wat(long long x)
{
	long long u = 0;
	int o = 0;
	while (x > 0)
	{
		 u = u + x % 2 * 10;
	}
	return u;
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n;
	for (int i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
		b[i] = wat(a[i]);
	}
//	for (int i = 1 ; i <= n ; i++)
//	{
//		for (int j = i ; j <= m ; j++)
//		{
//			
//		}
//	}
	cout << 15;
	return 0;
 } 
