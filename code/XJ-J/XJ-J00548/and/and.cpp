#include <bits/stdc++.h>
using namespace std ;
long long a[200005] , b[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n , m  ;
	cin >> n >> m ;
	long long cnt=0;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		b[i]=a[i];
		for(int j=i;j<=n;j++)
		{
			cnt = max( cnt ,(b[j] & a[i]));
		}
	}
	cout << cnt ;
	return 0 ;
}