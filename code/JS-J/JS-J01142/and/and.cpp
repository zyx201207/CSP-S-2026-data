#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,a[200005],m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==m)
	{
		int ans=a[1];
		for(int i=2;i<=n;i++)
		{
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	else if(m==1)
	{
		sort(a+1,a+n+1);
		cout<<a[n];
	}
	else if(m==2)
	{
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				ans=max(a[i]&a[j],ans);
			}
		}
		cout<<ans;
	}
	else if(m==n-1)
	{
		int b[200005],d[200005],ans=0;
		b[1]=a[1];
		b[0]=1<<30;
		d[n+1]=1<<30;
		for(int i=2;i<=n;i++)
		{
			b[i]=b[i-1]&a[i];
		}
		d[n]=a[n];
		for(int i=n-1;i>=1;i--)
		{
			d[i]=d[i+1]&a[i];
		}
		for(int i=1;i<=n;i++)
		{
			ans=max(ans,b[i-1]&d[i+1]);
		}
		cout<<ans;
	}
	else
	{
		sort(a+1,a+n+1);
		cout<<a[n-m];
	}
	return 0;
}
