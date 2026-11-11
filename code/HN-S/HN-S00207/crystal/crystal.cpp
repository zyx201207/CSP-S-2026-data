#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=5e5+5;
ll n,m,mx,ans,a[maxn],num[maxn];

ll check(ll x)
{
	for(int i=1;i<=n;i++) num[i]=0;
	mx=m; ll cnt=0;
	for(int i=1;i<=x;i++)
	{
		num[i]=abs(a[x]-a[i]);
	}
	for(int i=x;i>=1;i--)
	{
		if(num[i]<=mx)
		{
			mx-=num[i];
			cnt++;
		}
	}
	return cnt;
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	
	ll l=1,r=n;
	while(l<=r)
	{
		ll mid=(l+r)/2;
		ll now=check(mid);
		if(ans<now)
		{
			l=mid+1;
			ans=now;
		}
		else r=mid-1;
	}
	cout<<ans;
	
	return 0;
}
//Oct31==Dec25?
