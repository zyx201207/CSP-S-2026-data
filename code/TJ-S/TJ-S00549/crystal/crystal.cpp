#include <iostream>
using namespace std;
int n,m,a[100000001],i,l;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	 } 
	if(n == 1)
	{
		cout << 1;
		return 0;
	}
	 for(i = 1;i <= n;i++)
	 {
	 	for(int j = 2;j <= n;j++)
	 	{
	 		if(a[j] < a[j - 1])
	 		{
	 			int m = a[j];a[j] = a[j - 1];a[j - 1] = m;
			 }
		}
	}
	for(;m > 0;)
	{
		for(i = 1;;i++)
		{
			if(a[i] != a[i + 1])
			{
				break;
			}
		}
		int n = ( a[i + 1] - a[i] ) * i;
		m -= n;
		for(int nm = 1;nm <= i;nm++)
		{
			a[nm] = a[i + 1];
		}
	}
	for(i = 1;;i++)
	{
		if(a[i] != a[i + 1])
		{
			break;
		}
	}
	cout << i << endl;
	return 0;
} 
