#include <bits/stdc++.h>
using namespace std;
int n,m;
long long sum;
int a[200020];
int cmp(int c,int b)
{
	if(b > c)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i = 1;i <= m;i++)
	{
		if(i == 1)
		{
			sum = a[i];
		}
		else
		{
			sum = sum & a[i];
		}
	}
	cout << sum;
	return 0;
}
