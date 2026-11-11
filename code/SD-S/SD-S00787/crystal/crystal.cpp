#include<bits/stdc++.h>
using namespace std;
int m,n,b,ans=1,rq;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int a[m+10],jl[m+10];
	for(int i=1;i<=m;i++)
	{
		jl[i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(a[j]<a[i])
			{
				rq=a[i];
				a[i]=a[j];
				a[j]=rq;
			}
		}
	}
	b=m;
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if(i!=j&&a[i]==a[j]&&jl[j]!=1)
			{
				ans=ans+1;
				jl[j]=1;
			}
			if(a[j]!=a[i])
			{
				for(int k=1;a[j]!=a[i]&&b!=0;b--)
				{
					a[j]=a[j]+1;
				}
				if(a[j]==a[i]&&jl[j]!=1)
				{
					ans=ans+1;
					jl[j]=1;
				}
				if(b==0)
				{
					break;
				}
			}
		}
	}
	if(ans!=0)
	{
		cout<<ans<<endl;
		return 0;
	}
	else
	{
		cout<<0<<endl;
		return 0;
	}
}
