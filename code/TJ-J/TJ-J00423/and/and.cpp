#include<iostream>
using namespace std;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout) ;
	int n,m,a[200005],ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			ans=max(ans,a[i]);
		}
		cout<<ans;
	}
	else if(m==n)
	{
		ans=a[1];
		for(int i=2;i<=n;i++)
		{
			ans=ans&a[i];
		} 
		cout<<ans;
	}
	else if(m==2)
	{
		for(int i=1;i<=n-1;i++)
			for(int j=i+1;j<=n;j++) 
				ans=max(ans,a[i]&a[j]);
		cout<<ans;
	}
	else if(m==n-1)
	{
		int b;
		for(int i=2;i<=n-1;i++)
		{
			b=a[1];
			for(int j=2;j<i;j++)
				b=b&a[j];
			for(int j=i+1;j<=n;j++)
				b=b&a[j];
		}
		ans=max(ans,b);
		int a1=a[2],a2=a[1];
		for(int i=2;i<=n;i++)
			a1=a1&a[i];
		for(int i=2;i<=n-1;i++)
			a2=a2&a[i];
		ans=max(ans,max(a1,a2));
		cout<<ans;
	}
	else
	{
		cout<<a[n];
	}
	return 0;
 } 
