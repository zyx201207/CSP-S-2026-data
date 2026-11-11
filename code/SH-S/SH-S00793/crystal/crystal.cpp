#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+10;
const ll inf=1e16;
ll n,m;
ll a[N];
ll sum[N];
ll ans=0;
ll fd(ll x){
	ll l=1,r=x;
	while(l!=r){
		ll mid=(l+r)>>1;
		if(a[x]*(x-mid+1)-sum[x]+sum[mid-1]<=m){
			r=mid;
		}else{
			l=mid+1;
		}
	}
	return x-l+1;
} 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(ll i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(ll i=1;i<=n;i++){
		ans=max(ans,fd(i)); 
	}
	cout << ans << endl;
	return 0;
}
