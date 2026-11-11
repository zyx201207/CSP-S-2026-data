#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long n,a[200005],pfx[200005][30],sum[200005],x,ans;
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i],sum[i]=sum[i-1]+a[i];
		for(int j=1;j<=26;j++)pfx[i][j]=pfx[i-1][j]+(c[i]-96==j)*a[i];
	}
	int i;
	for(i=1;i<=n&&x+a[i]<=sum[n]/2;i++)
	{
		//x+1~x+a[i]
		//sum[n]-x-a[i]+1~sum[n]-x
		int l=lower_bound(sum+1,sum+n+1,sum[n]-x-a[i]+1)-sum;
		int r=lower_bound(sum+1,sum+n+1,sum[n]-x)-sum;
		if(l==r)
		{
			ans+=(c[l]!=c[i])*a[i];
			x+=a[i];
			continue;
		}
		ans+=a[i];
		if(r-l>1)ans-=pfx[r-1][c[i]]-pfx[l][c[i]];
		if(c[l]==c[i])ans-=sum[l]-sum[n]+x+a[i];
		if(c[r]==c[i])ans-=sum[n]-x-sum[r-1];
		x+=a[i];
	}
	if(x+1<=sum[n]/2)
	{
		int l=lower_bound(sum+1,sum+n+1,x+a[i]+1)-sum;
		int r=lower_bound(sum+1,sum+n+1,sum[n]-x)-sum;
		if(l==r)ans+=(c[l]!=c[i])*(sum[n]-x*2-a[i]);
		if(l<r)
		{
			ans+=sum[n]-x*2-a[i];
			if(r-l>1)ans-=pfx[r-1][c[i]]-pfx[l][c[i]];
			if(c[l]==c[i])ans-=sum[l]-x-a[i];
			if(c[r]==c[i])ans-=sum[n]-x-sum[r-1];
		}
	}
	cout<<ans;
	return 0;
} 
