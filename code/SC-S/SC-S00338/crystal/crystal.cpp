#include<bits/stdc++.h>
#define ll long long
#define maxn 600006
using namespace std;
ll a[maxn],sum[maxn];
ll n,m;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,greater<ll>());
	for(ll i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	ll mxans=0;
	for(ll i=n;i>=1;i--){
		ll l=i,r=n;
		while(l<r){
			ll mid=(l+r+1)>>1;
			if((mid-(i-1))*a[i]-(sum[mid]-sum[i-1])<=m){
				l=mid;
			}
			else{
				r=mid-1;
			}
		}
		mxans=max(mxans,l-i+1);
	}
	cout<<mxans<<"\n";
	return 0;
}