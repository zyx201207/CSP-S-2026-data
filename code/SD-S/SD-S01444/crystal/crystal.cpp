#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
ll n;
ll m;
ll a[N],pre[N];
ll ans = 1;
ll check(ll k,ll r,ll i)
{
	int l = 1;
	while(l<r)
	{
		ll mid = (l+r)>>1;
		ll o = pre[i] - pre[mid-1];
	//	cout<<l<<" "<<r<<" "<<o<<" "<<(i-(mid)+1)*a[i] - o<<endl;
		if((i-(mid)+1)*a[i] - o <= m)
		{
			r = mid;	
		}else
		{
			l = mid+1;
		}
	}
	return r;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i = 1;i <= n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(ll i = 1;i <= n;i++)
	{
		pre[i] = pre[i-1] + a[i];
	//	cout<<pre[i]<<" ";
	}
//	cout<<endl;
	for(ll i = 1;i <= n;i++)
	{
		ll t = check(a[i],i,i);
	//	cout<<i<<" "<<a[i]<<" "<<t<<endl;
		ans = max(ans,i-t+1);
	}
	printf("%lld\n",ans);
	return 0;
} 
