#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n,m;
ll a[500010];
ll ans;
ll fsum[500010],bsum[500010],sum[500010],rsum[500010];

ll calc(ll l,ll r){
	ll res=0;
	res=(bsum[l]-bsum[r+1]-(rsum[r+1])*(r-l+1));
	return res;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){
		fsum[i]=fsum[i-1]+(a[i]-a[1]);
		sum[i]=sum[i-1]+a[i];
	}
	fsum[0]=0;
	for(ll i=n;i>=1;i--){
		bsum[i]=bsum[i+1]+(a[n]-a[i]);
	}
	for(ll i=2;i<=n;i++){
		rsum[i]=(bsum[i-1]-bsum[i]);
	}
	ll l=1,r=1;
	ll res=1;
	while(l<=r&&r<=n){
		if(calc(l,r+1)>m){
			r++;
			while(calc(l,r)>m&&l<r){
				l++;
			}
		}
		else{
			r++;
		}
		res=max(r-l+1,res);
	}
	ans=res;
	cout<<ans;
	return 0;
}
