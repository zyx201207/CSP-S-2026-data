#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=5e5+10;
ll a[M],b[M],n,m;
ll check(ll mid){
	ll s=0;
	for(ll i=mid;i<=n;i++){
		ll k=1;
		for(ll j=i-mid+2;j<=i;j++){
			s+=b[j]*k;
			k++;
		}
		if(s<=m)return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i]-a[i-1];
	}
	sort(a+1,a+n+1);
	ll l=1,r=n,ans=0;
	while(l<=r){
		ll mid=l+(r-l)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else r=mid-1;
	}
	cout<<ans;
	return 0;
}
