#include <bits/stdc++.h>
using namespace std;
int n , a[200000005] ,maxn = -114514, m, z[200000005];
int main()
{
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> a[i];
	}
//zhao dao di 'm' da de
for(int v = 1; v <= m ; v++)
{

	for(int i = 1 ; i <= n ; i ++)
	{
		maxn = -114514;
		maxn = max(a[i] , maxn);
		
		
	}
	for(int i = 1; i <=m ; i++ )
	{
	
		if(a[i] == maxn)
		{
			a[i] = 0;
		
			
		}
		
	}
	
	
}

	cout << maxn;
	return 0;
}
