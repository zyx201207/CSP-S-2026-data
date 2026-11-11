#include <bits/stdc++.h>
using namespace std;
int a[500005],n;
long long m;
int ce(int x,int p)
{
	int as=1;
	int i=p-1;
	while(i>=1)
	{
		if(x-a[i]<=m)
		{
			m-=(x-a[i]);
			as++;
		}
		else
		{
			break;
		}
		i--;
	}
	for(int j = p;j<=n;j++)
	{
		if(a[j]==x)
		{
			as++;
		}
		else
		{
			break;
		}
	}
	return as;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans=1;
	for(int i = 1;i<=n;i++)
	{
		ans=max(ans,ce(a[i],i));
	}
	cout<<ans;
	return 0;
}