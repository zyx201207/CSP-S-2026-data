#include <bits/stdc++.h>
using namespace std ;

long long n,len,ans,pos1 ;
string s ;

int main()
{
	freopen("string.in","r",stdin) ;
	freopen("string.out","w",stdout) ;
	cin >> n ;
	for(int i = 1 ; i <= n ; i ++)
	{
		long long a ;
		char b ;
		cin >> a >> b ;
		len += a ;
		for(int j = 1 ; j <= a ; j ++)
		{
			s[pos1] = b ;pos1++ ;
		}
	}
	long long pos = len ;
	for(int i = 1 ; i < pos ; i ++)
	{
		pos = len - i + 1 ;
		if(s[i] != s[pos])
		{
			ans ++ ;
		}
	}
	cout << ans ;
/*
	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> a[i].a >> a[i].b ;
		len += a[i].a ;
	}
	pos = n ;
	ans = len ;
	int i = 1 ;
	while(i < pos)
	{
		if(a[i].b != a[pos].b)
		{
			if(a[i].a > a[pos].a)
			{
				pos -- ;
				a[i].a -= a[pos].a ;
			}
			else if(a[i].a < a[pos].a)
			{
				i++ ;
				a[pos].a -= a[i].a ;
			}
			else
			{
				i++,pos-- ;
			}
		}
		else
		{
			ans -= min(a[i].a,a[pos].a)*2 ;
			if(a[i].a > a[pos].a)
			{
				pos -- ;
				a[i].a -= a[pos].a ;
			}
			else if(a[i].a < a[pos].a)
			{
				i++ ;
				a[pos].a -= a[i].a ;
			}
			else
			{
				i++,pos-- ;
			}
		}
	}
	if(len % 2 != 0)
	{
		cout << ans - a[(len-1)/2+1].a ;
		return 0 ;
	}
	cout << ans ;
*/
}
