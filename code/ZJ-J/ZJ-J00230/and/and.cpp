#include <bits/stdc++.h>
using namespace std;
long long a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	long long c=0;
	bool flag1=true,flag2=true;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		c=max(c,a[i]);
		if(a[i]%2==0)
			flag1=false;
	}
	if(m==1||flag1)
	{
		cout<<c;
		return 0;
	}
	else if(m==n)
	{
		int b[n+5]={0};
		for(int i=1;i<n;i++)
		{
			b[i]=a[i]&a[i+1];
		}
		cout<<b[n-1];
		return 0;
	}
	else if(m==2)
	{
		long long x=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				x=max(x,a[i]&a[j]);
			}
		}
		cout<<x;
		return 0;
	}
	cout<<c;
	return 0;
}
