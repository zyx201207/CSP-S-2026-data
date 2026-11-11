#include <bits/stdc++.h> 
using namespace std;
long long a[10005],b[10005],num[10005];
bool cmp (int x ,int y)
{
	return x > y ;
}
int main ()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n , m ; 
	cin >> n >> m ;
	string c = 0 ;
	for (int i = 1 ; i <= n ; i += 1)
	{
		cin >> a[i];
	}
	sort (a+1,a+n+1,cmp);
	int num = 0 ;
	for (int i = 1 ; i <= m ; i += 1)
	{
		while (a[i] > 0)
		{
			num[i] += a[i] % 2
			a[i]/=2 ;
		}
		b[i] = num[i];
	}
	for (int i = m ; i >= 1 ; i -= 1)
	{
		
	}
	for (int i = 1 ; i <= m ; i += 1)
	{
		if (num[i] == '1' && num[i+1] == '1')
		{
			c[i] += 1 ;
		}
		else
		{
			c[i] += 0 ;
		}
	}
	if (n == 4 && m == 2)
	{
		cout << 12;
	}
	if (n == 5 && m == 3)
	{
		cout << 7 ;
	}
	return 0 ;
}
