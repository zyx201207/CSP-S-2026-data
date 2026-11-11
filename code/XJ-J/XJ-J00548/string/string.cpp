#include <bits/stdc++.h>
using namespace std ;
long long a ;
char s[200005] ;
char v ;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n , k=0 ;
	cin >> n ;
	for(int i=1;i<=n;i++)
	{
		cin >> a;
		cin >> v ;
		for(int j=1;j<=a;j++)
		{
			s[k]=v ;
			k++;
		}
	}
	
	long long l=0,r=k-1 , cnt=0;
	for(int i=0;i<k;i++)
	{
		if(s[l]==s[r])
		{
			l++;
			r--;
		}
		else
		{
			cnt++;
			l++;
			r--;
		}
		if(r<=l)
			break ;
	}
	cout << cnt ;
	
	return 0 ;
}