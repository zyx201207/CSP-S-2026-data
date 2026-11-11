#include<bits/stdc++.h>
using namespace std;
long long a[5005];
int main() 
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==n)
	{
		long long ans=a[1];
		for(int i=1;i<=n;i++)ans&=a[i];
		cout<<ans;
	}
	else if(m==1)
	{
		long long ans=0;
		for(int i=1;i<=n;i++)ans=max(ans,a[i]);
		cout<<ans;
	}
	else if(m==2)
	{
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++) 
			{
				if(j!=i)
				{
					ans=max(ans,a[i]&a[j]);
				}
			}
		}
		cout<<ans;
	}
	else if(m==3)
	{
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				for(int k=1;k<=n;k++)
				{
					if((i!=j)&&(j!=k)&&(i!=k))ans=max(ans,(a[i]&a[j])&a[k]);
				}
			}
		}
		cout<<ans;
	}
	return 0;
}
