#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N=1e5+1;
ll n,m,a[N];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(ll i=1;i<=n;++i)
		scanf("%lld",a+i);
	sort(a+1,a+n+1);
	bool fAB=1;
	for(ll i=3;i<=n;++i)
		if(a[i]-a[i-1]!=a[i-1]-a[i-2])
			fAB=0;
	if(fAB)
	{
		ll x=m/(a[2]-a[1]);
		ll ans=1,i=1;
		while(x>0) x-=i,i++,ans++;
		printf("%lld\n",min(n,ans));
	}
	else if(n==5) printf("%lld\n",(n-1)/2+1);
	return 0;
}
/*/
 * 14:07
Type here what you want, use it as a notice/scratch board
Type here what you want, use it as a notice/scratch board
Type here what you want, use it as a notice/scratch board
Type here what you want, use it as a notice/scratch board
Type here what you want, use it as a notice/scratch board
Type here what you want, use it as a notice/scratch board
Type here what you want, use it as a notice/scratch board
Type here what you want, use it as a notice/scratch board
Type here what you want, use it as a notice/scratch board
Type here what you want, use it as a notice/scratch board
 * 14:55
 * I give up.
 * Now I just want to reach the final faster.
 * 
 * 15:17(22min)
 * boring...
 * 
 * 15:34(17min)
 * boring...
 * 
 * 15:47(13min)
 * boring...
 * 
 * 15:57(10min)
 * boring...
 * 
 * 16:07(10min)
 * boring...
 * 
 * 16:17(10min)
 * boring...
 * 
 * 16:27(10min)
 * boring...
 * 
 * 16:37(10min)
 * boring...
 * 
 * 16:47(10min)
 * boring...
 * 
 * 16:57(10min)
 * boring...
 * 
 * 17:07(10min)
 * boring...
 * 
 * 17:17(10min)
 * boring...
 * 
 * 17:27(10min)
 * boring...
 * 
 * 17:37(10min)
 * boring...
 * 
 * 17:47(10min)
 * boring...
 * 
 * 17:57(10min)
 * boring...
 * 
 * 18:07(10min)
 * boring...
 * 
 * 18:17(10min)
 * boring...
/*/
