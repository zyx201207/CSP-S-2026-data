#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
long long x;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	if(m==1)
	{
		cout << a[n];
	}
	else if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				long long p=a[i]&a[j];
				if(p>x)
				{
					x=p;
				}
			}
		}
		cout << x;
	}
	else if(m==n)
	{
		x=a[1];
		for(int i=2;i<=n;i++)
		{
			x&=a[i];
		}
		cout << x;
	}
	else
	{
		cout << a[n-m+1];
	}
	return 0;
}
