//SN-S00412 YangRuibin TYZ
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
int n;
ll m,a[N],sum[N];
bool check(int len)
{
	ll ans=2e18;
	for(int i=1,j=len;j<=n;i++,j++)
	{
		ans=min(ans,a[j]*(j-i+1)-sum[j]+sum[i-1]);
	}
	return ans<=m;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	int ans=0;
	for(int i=1<<19;i;i>>=1)
		if(check(ans+i))ans+=i;
	printf("%d",ans);
	return 0;
}

