#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define REP(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
typedef long long ll;

ll n,m,a[500009],sum[500009],ans=1;

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	FOR(i,1,n) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	FOR(i,1,n) sum[i]=sum[i-1]+a[i];
	ll j=0;
	FOR(i,1,n)
	{
		ll seg=sum[i]-sum[j],num=i-j;
		ll stad=num*a[i];
		ll diff=stad-seg;
		if(diff>m) j++,i--;
		else ans=max(ans,num);
	}
	printf("%lld\n",ans);
	return 0;
}

// 100pts!

// RP++
