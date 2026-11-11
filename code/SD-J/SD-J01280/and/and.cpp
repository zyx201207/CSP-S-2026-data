#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long a[200005];
int m,n,sum,x;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	sum = a[n];
	if (m == 1)
	{
		cout << sum;
		return 0;
	}
	x = n-1;
	for (int i = 1;i <= m-1;i++)
	{
		sum = sum&a[x];
		x--;
	}
	cout << sum;
	return 0;
}
