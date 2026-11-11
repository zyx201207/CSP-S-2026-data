#include<bits/stdc++.h>

using namespace std;
int a[200010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(m==1)
	{
		int am=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]>am)
				am=a[i];
		}
		cout<<am;
	}
	if(m==n)
	{
		int ans=pow(2,30)-1;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];		
			ans=ans&a[i];	
		}
		cout<<ans;
	}
	if(m==n-1)
	{
		int ans,u=pow(2,30)-1;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];		
			u=u&a[i];	
		}
		ans=0;
		for(int i=1;i<=n;i++)
		{
			int ls=(u|a[i]);
			ans=max(ls,ans);
		}
		cout<<ans;
	}
	if(m==2)
	{
		int ans=0;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n-1;i++)
		{
			for(int j=i+1;j<=n;j++)
				ans=max(ans,a[i]&a[j]);
		}
		cout<<ans;
	}
	return 0;
}
