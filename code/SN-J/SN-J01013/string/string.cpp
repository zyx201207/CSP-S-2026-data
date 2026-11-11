#include <bits/stdc++.h>
using namespace std;
int n ,cnt = 0;
int a[200005] ;
string c[200005];
int s[5000005];
int main()
{
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	
	for(int i = 0 ; i <= n;i++ )
	{
		cin >> a[i] >> c[i];
	}
	for(int i = 1 ; i <= n ; i++)
	{
		int o = a[i];
		if(a[i] == o )
			cnt ++;
			
	}
	if(cnt == n)
	{
		cout <<  0;
		return 0;
	}
	
	for(int i = 0 ; i <= n ; i ++)
	{
		for(int j = 0 ; j <= a[i] ; j++ )
		{
			for(int z = 0 ; z <= a[i] ; z++)
			{
				s[z] = int('c[j]');
			}
		}
	}
	for(int i = n; i >= 0;i--)
		cout << s[i];
	return 0;
}
