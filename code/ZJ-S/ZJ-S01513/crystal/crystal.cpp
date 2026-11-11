#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=5e5+7;
ll n,m,ans=-1;
ll a[N],qz[N];
bool ck(ll x,ll nl)
{
	bool ok=0;
	for(int i=x;i<=n;i++)
	{
		ll sum=x*a[i];
		ll Sum=qz[i]-qz[i-x+1]+a[i-x+1];
		ll SUM=abs(Sum-sum);
		if(SUM<=nl)
		{
			ok=1;
			ans=max(ans,x);
		}
	}
	return ok;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		qz[i]=qz[i-1]+a[i];
	}
	ll l=0,r=n;
	while(l<=r)
	{
		ll mid=(l+r+1)/2;
		if(ck(mid,m)==1)
		{
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<ans;
}
