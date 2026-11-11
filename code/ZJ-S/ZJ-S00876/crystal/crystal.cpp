#include<bits/stdc++.h>
using namespace std;
long long a[1000010],s[1000010],m;
int ans,n;
long long Abs(long long x)
{
	return x<0?-x:x;
}
int solve(int pos)
{
	int l=1,r=pos,ans=-1;
	while(l<=r)
	{
		int mid=(l+r)/2;
//		printf("[DEBUG]%lld:%d %lld\n",a[pos],mid,a[pos]*mid-(s[pos]-s[pos-mid]));
		if(a[pos]*mid-(s[pos]-s[pos-mid])<=m)
		{
			ans=mid;
			l=mid+1;
		}
		else
			r=mid-1;
	}
	return ans;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",a+i);
	stable_sort(a+1,a+1+n);
	for(int i=1;i<=n*2;i++)
		s[i]=s[i-1]+a[i];
	ans=solve(1);
	for(int i=2;i<=n;i++)
		ans=max(ans,solve(i));
	printf("%lld",ans);
	return 0;
}
// 2026 CSP-S 一鼓作气，四题暴力！