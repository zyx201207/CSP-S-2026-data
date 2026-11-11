#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	int a[150000]={};
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int ans=0;
	if (m==1)
	{
		for (int i=1;i<=n;i++)
		{
			ans=max(ans,a[i]);
		}
		cout<<ans;
	}
	else if (m==2)
	{
		for (int i=1;i<=n-1;i++)
		{
			for (int j=i+1;j<=n;j++)
			{
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
	}
	else
	{
		for (int i=1;i<=n;i++)
		{
			ans=max(ans,a[i]);
		}
		cout<<ans;
	}
	return 0;
}
