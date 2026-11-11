#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sum[500005];
int ans,f=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",a+i);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		int maxt=0,j;
		for(j=f;j<=i;j++)
	    if((i-j+1)*a[i]-(sum[i]-sum[j-1])<m)
	    {
	    	if((i-j+2)*a[i]-(sum[i]-sum[j-2])==m && j>=2)
	    	{maxt=i-j+2;break;}
	    	else 
	    	{maxt=i-j+1;break;}
		}
		f=j;
	    ans=max(ans,maxt);
	}
	printf("%d",ans);
	return 0;
}
