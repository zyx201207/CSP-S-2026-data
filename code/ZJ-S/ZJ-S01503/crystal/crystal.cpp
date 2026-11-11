#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],qian[500005];
int l=1,r,mid,num,ans;
int check(int x)
{
	l=1,r=x;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(a[x]*(x-mid)-qian[x-1]+qian[mid-1]<=m) r=mid-1,num=mid;
		else l=mid+1;
	}
	return x-num+1;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	r=n;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		qian[i]=qian[i-1]+a[i];
	}
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,check(i));
	}
	printf("%d",ans);
	return 0;
}
