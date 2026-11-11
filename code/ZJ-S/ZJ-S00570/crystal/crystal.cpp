#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+10;
ll n,m;
ll a[N],b[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	ll mx=0;
	for(ll i=1;i<=n;i++){
		ll l=0,r=i-1,ans=0;
		while(l<=r){
			ll mid=(l+r)>>1;
			if(mid*a[i]-(b[i-1]-b[i-mid-1])<=m){
				ans=mid;
				l=mid+1;
			}
			else r=mid-1;
		}
		mx=max(mx,ans+1);
	}
	cout<<mx;
	return 0;
}
