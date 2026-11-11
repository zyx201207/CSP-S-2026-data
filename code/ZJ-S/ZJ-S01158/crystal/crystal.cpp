#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500005],maxn=-1000000000005,minn=1000000000005,ans=-1,sum;
bool check(ll x){
	for(ll i=x;i<=n;i++){
		ll t=0;
		for(ll j=i-x+1;j<=i;j++){
			t+=a[i]-a[j];
		}
		if(t<=m){
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(ll i=2;i<=n;i++){
		a[i]-=a[1];
	}
	a[1]=0;
	ll mid;
	ll l=1,r=n;
	while(r-l>=2){
		mid=(r+l)/2;
		if(check(mid)){
			l=mid;
		}else{
			r=mid;
		}
	}
	ll cnt=0;
	for(ll i=1;i<=n;i++){
		cnt+=a[i];
	}
	if(cnt<=m)cout<<n;
	else cout<<l;
	return 0;
}
