#include<bits/stdc++.h> 
using namespace std;
int h( string s )
{
	int c,i;
	string a;
	for( i = 0 ; i <= s.size() - 1 ; i++ )
	{
		c = c * 10;
	}
	for( i = s.size() - 1 ; i >= 0 ; i-- )
	{
		a = a + s[i];
	}
	if( a == s )
	{
		return 1;
	}else return 0;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	long long n,c,w=0,j,i,l;
	char x;
	cin >> n;
	for( i = 1 ; i <= n ; i++ )
	{
		cin >> c >> x ;
		for( j = 1 ; j <= c ; j++ )
		{
			s = s + x;
		}
	}
	l = s.size() - 1 ;
	if( h(s) == 1 )
	{
		cout << 0;
	}else 
	{
		if( l % 2 == 0 )
		{
			for( i = 0 ; i <= l / 2 - 1 ; i++ )
			{
				for( j = l ; j >= l / 2 + 1 ; j-- )
				{
					if( s[i] != s[j] )
					{
						w++;
					}
				}
			}
		}
		else if( l % 2 != 0 )
		{
			for( i = 0 ; i <= l / 2 ; i++ )
			{
				for( j = l ; j >= ( l + 1 ) / 2 ; j-- )
				{
					if( s[i] != s[j] )
					{
						w++;
					}
				}
			}
		}
	}
	cout << w;
	return 0;
}

