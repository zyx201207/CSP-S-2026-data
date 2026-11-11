#include<bits/stdc++.h>
using namespace std;
int n,a[300000],ans=-1,m;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a,a+n);
	if(m==1)cout<<a[n];
	else if(m==2)
	{	
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				ans=max(ans,(a[i]&a[j]));
			}
		}
	}
	else if(m==3)
	{	
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{		
				for(int k=j+1;k<=n;k++)
				{
					ans=max(ans,(a[i]&a[j]&a[k]));
				}
			}
		}
	}
	else if(m==n)
	{
		ans=a[1];
		for(int i=2;i<=n;i++)ans=ans&a[i];
	}
	cout<<ans;
	return 0;
}

