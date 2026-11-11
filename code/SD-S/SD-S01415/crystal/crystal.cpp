#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
ll a[N],sum[N],n,m;
bool check(ll len)
{
	for(int i=len;i<=n;i++)
	{
		ll need=a[i]*len,sj=sum[i]-sum[i-len-1];
		ll cj=need-sj;
		if(cj<=m)return true;
	}
	return false;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	ll l=1,r=n;
	while(l<=r)
	{
		ll mid=l+r>>1;
		if(check(mid))l=mid+1;
		else r=mid-1;
	}
	cout<<l-1;
	return 0;
}
