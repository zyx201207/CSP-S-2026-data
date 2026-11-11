#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,a[500005],d[500005],ans,lim;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,less<ll>());
	for(ll i=1;i<=n;i++)d[i]=a[i]-a[i-1];
	ll l=1,r=1;
	for(;r<=n&&l<=r;r++)
	{
    	lim+=d[r]*(r-l);
    	while(l<=r&&lim>m)
    	{
    		lim-=a[r]-a[l];
    		l++;
		}
		ans=max(r-l+1,ans);
	}
	cout<<ans;
    return 0;
}