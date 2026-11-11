#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,a[200005];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}
	if(m==n)
	{
		long long s;
		for(int i=1;i<=n;i++)
	    {
	    	s&=a[i];
	    }
	    cout<<s;
	    return 0;
	}
	if(m==n-1)
	{
		long long ss,anx=-1;
		for(int j=1;j<=n;j++)
		{
		for(int i=1;i<=n;i++)
	    {
	    	if(i!=j)
	    	ss&=a[i];
	    }
	    anx=max(ss,anx);
	}
	cout<<anx;
	return 0;
	}
	if(m==2)
	{
		long long sss,axn=-1;
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			sss=a[i]&a[j];
			axn=max(axn,sss);
		}
		cout<<axn;
		return 0;
	}
	if(n>20)
	{
		sort(a+1,a+n+1);
		cout<<a[n-1];
	}
	return 0;
 } 
