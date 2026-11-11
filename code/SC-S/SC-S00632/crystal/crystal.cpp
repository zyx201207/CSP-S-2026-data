#include<bits/stdc++.h>
using namespace std;
int n,m,c,ans;
int a[500050];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int i,j;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(i=2;i<=n-1;i++)
	{
		for(j=i;j>=1;j--)
		{
			if(a[i+1]-a[i]<=m)
			{
				a[i]=a[i+1];
				c++;
				m=m-a[i+1]+a[i]; 
			}
		}
		sort(a+1,a+n+1);
		for(i=1;i<=n-1;i++)
		{
			if(a[i]==a[i+1])
			{
				c++;
			}
		}
		if(c>ans)
		{
			ans=c;
		}
	}
	cout<<ans;
	return 0;
}