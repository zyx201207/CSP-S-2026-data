#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500010],sum;
int ans=1,l=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		sum+=(a[i]-a[i-1])*(i-l);
		if(sum<=m)ans=max(ans,i-l+1);
		else
		{
			while(sum>m)
			{
				sum-=a[i]-a[l];
				l++;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}