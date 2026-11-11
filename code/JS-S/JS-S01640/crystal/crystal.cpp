#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500500];
long long l,sum;
long long ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++)
		scanf("%lld",a+i);
	sort(a+1,a+n+1);
	ans=1,sum=0,l=1;
	for(long long r=2;r<=n;r++)
	{
		sum+=(r-l)*(a[r]-a[r-1]);
		while(sum>m)
			sum-=a[r]-a[l],l++;
		ans=max(ans,r-l+1);
	}
	printf("%lld",ans);
	return 0;
}
