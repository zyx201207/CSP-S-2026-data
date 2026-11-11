#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long d[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	bool tp_A=true;
	bool tp_B=true;
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=i) tp_A=false;
	}
	if(tp_A==true)
	{
		long long zm=m;
		long long cnt=0;
		for(int i=n;i>0;i--)
		{
			d[i]=a[n]-a[i];
		}
		for(int i=n;i>0;i--)
		{
			if(zm>=d[i]) zm-=d[i],cnt++;
			else break;
		}
		cout<<cnt;
		return 0;
	}
	
	
	sort(a+1,a+n+1);
	
	for(int i=3;i<=n;i++)
	{
		if(a[i]-a[i-1]!=a[2]-a[1]) tp_B=false;
	}
	if(tp_B==true)
	{
		long long zm=m;
		long long cnt=0;
		for(int i=n;i>0;i--)
		{
			d[i]=a[n]-a[i];
		}
		for(int i=n;i>0;i--)
		{
			if(zm>=d[i]) zm-=d[i],cnt++;
			else break;
		}
		cout<<cnt;
		return 0;
	}
	
	long long maxi=0;
	for(int i=1;i<=n;i++)
	{
		long long zm=m;
		long long cnt=0;
		for(int j=1;j<=i;j++)
		{
			d[j]=a[i]-a[j];
		}
		for(int j=i;j>0;j--)
		{
			if(zm>=d[j]) zm-=d[j],cnt++;
			else break;
		}
		maxi=max(maxi,cnt);
	}
	cout<<maxi;
	return 0;
}
