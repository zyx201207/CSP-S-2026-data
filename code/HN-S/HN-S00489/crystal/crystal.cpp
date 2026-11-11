#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500001],c[500000];
int main()
{
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	
	sort(a+1,a+1+n);
	
	int maxx=0,fg=0;
	
	for(int i=1;i<n;i++)
	{
		c[i]=a[i+1]-a[i];
		if(maxx<=c[i])
		{
			maxx=c[i];
			fg=i;
		}
	}
	
	n=fg;
	int sum=1;
	for(int i=n-1;i>=1;i--)
	{
		if(m>=a[i+1]-a[i])
		{
			m=m-(a[i+1]-a[i]);
			sum++;
			a[i]=a[i+1];
		}
	}
	cout<<sum;
	return 0;
} 
