#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,a[500005]={},c[500005]={};
	long long m;
	int b = 1,d=0;
	cin >> n >> m;
	for(int i = 1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1;i<=n;i++)
	{
		c[i]=a[i];
		c[i]+=c[i-1];
	}
	for(int i = n;i>=1;i--)
	{
		d = 0;
		while(i-b>=0&&a[i]*b-(c[i]-c[i-b])<=m)
		{
			b++;
			d=1;
		}
		if(d)
		{
			b--;
		}
	}
	cout<<b;
	
	
	return 0;
}
