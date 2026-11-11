#include <bits/stdc++.h>
using namespace std;
long long a[500010];
int n;
long long m;
bool check(int mid)
{
	long long sum=0,ss=0;
	for (int i=n;i>1;i--)
	{
		ss+=a[i];
		sum+=ss;
		if(n-mid+2<i) continue;
		if(sum<=m) return true;
		ss-=a[i+mid-2];
		sum-=1ll*(mid-1)*a[i+mid-2];
	}
	return false;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for (int i=n;i>=2;i--) a[i]=a[i]-a[i-1];
	a[1]=0;
	int l=1,r=n,ans=0;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%d",ans);
	return 0;
}
