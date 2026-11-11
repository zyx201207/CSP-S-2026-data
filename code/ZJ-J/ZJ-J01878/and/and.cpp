#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
long long n,m,a[200010],y=0,x=0,t=0,k;
cin>>n>>m;
for(int i=1;i<=n;i++)
{
	cin>>a[i];
	x=max(x,a[i]);
}

if(m==n)
{
	t=a[1];
	for(int i=2;i<=n;i++)
	{
		t=t&a[i];
	}
	cout<<t;
}
else if(m==2)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			y=max(y,a[j]&a[i]);
		}
	}
	cout<<y;
	return 0;
}
else if(m==1)
{
	cout<<x;
	return 0;
}

else
{
	sort(a+1,a+1+n);
	for(int i=n;i>=n-m;i--)
	{
		a[i-1]=a[i]&a[i-1];
	}
	cout<<a[m];
}
		return 0;
}
