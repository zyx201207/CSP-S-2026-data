#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	ll m;
	cin>>n>>m;
	vector<ll> a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a.begin()+1,a.end());
	vector<ll> s(n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i,p=0;
		auto check=[&](int mid)->bool
		{
			ll sum=s[i]-s[mid-1];
			ll delta=(ll)(i-mid+1)*a[i]-sum;
			if(delta<=m)return 1;
			return 0;
		};
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(check(mid))p=mid,r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,i-p+1);
	}
	cout<<ans<<'\n';
	return 0;
}