#include<bits/stdc++.h>
using namespace std;
int a[500005];
long long dj[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,ans;
	long long m;
	scanf("%d",&n);
	scanf("%lld",&m);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			dj[i]+=1LL*(a[i]-a[j]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(dj[i]<=m)
		{
			ans=i;
		}
		else
		{
			break;
		}
	}
	printf("%d",ans);
	return 0;
}
