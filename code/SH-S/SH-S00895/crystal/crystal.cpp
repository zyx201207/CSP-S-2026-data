#include<bits/stdc++.h> 
using namespace std;
#define ll long long
#define N 500001
ll n,m,a[N],mid,s,ans,sum[N];
ll e(ll lx,ll l,ll r)
{
	if(l >= r) return r;
	mid = (l+r+1)/2;
	s = a[mid]*(mid-lx)-(sum[mid-1]-sum[lx-1]);
	if(s <= m) l = mid;
	else r = mid - 1;
	return e(lx,l,r);
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i = 1 ; i <= n ; i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i = 1 ; i <= n ; i++) sum[i] = sum[i-1]+a[i];
	for(int i = 1 ; i <= n ; i++)
	{
		ans = max(ans,e(i,i,n)-i+1);
		if(n-i+1 <= ans) break;
	}
	printf("%lld\n",ans);
	return 0;
}
