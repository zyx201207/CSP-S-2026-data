#include<bits/stdc++.h>
using namespace std;
long long a[500010];
long long d[500010];
int n;
long long m;
int ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		d[i]=a[i]-a[i-1];
	}
	bool ok=false;
	for(int i=n;i>1;i--)
	{
		if(ok)
		{
			break;
		}
		int j=i-1;
		long long sum=0,nowd=0;
		while(sum<=m)
		{
			nowd+=d[j+1];
			sum+=nowd;
			if(j==1&&sum<=m)
			{
				ans=max(ans,i);
				ok=true;
				break;
			}
			j--;
		}
		ans=max(ans,i-j-1);
	}
	printf("%d",ans);
	return 0;
 } 