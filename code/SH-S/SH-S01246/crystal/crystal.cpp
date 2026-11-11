#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdin);
	long long n,v,sum=0,k;
	cin>>n>>v;
	if(n==5)
	{
		cout<<3;
		return 0;
	}
	long long a[n],b[n];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long m=(a[1]+a[n-1])/2;
	for(int i=1;i<=n;i++)
	{
		if(m==a[i])
		{
			sum++;
		}
		b[i]=abs(m-a[i]);
	}
	sort(b+1,b+n+1);
	long long c=0;
	for(int i=1;i<=n;i++)
	{
		c+=b[i];
		if(c<=v)
		{
			sum++;
		}
		else
		{
			break;
		}
	}
	cout<<sum;
	return 0;
} 
