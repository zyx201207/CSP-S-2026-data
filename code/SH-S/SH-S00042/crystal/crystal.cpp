#include<bits/stdc++.h>
using ll=long long;
using namespace std; 
const int N=5e5+10;

ll n,m;
ll a[N];
ll b[N];
ll l,r;
ll ans;

int main(){
	ios::sync_with_stdio(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	r=1;
	while(r<=n){
		ll sum=b[r]-b[l];
		ll crystal_amount=r-l;
		ll x=crystal_amount*a[r];
		ll need=x-sum;
		if(need>m){
			l++;
		}else{
			r++;
			ans=max(crystal_amount,ans);
		}
	}
	cout<<ans<<'\n';
	return 0;
}

