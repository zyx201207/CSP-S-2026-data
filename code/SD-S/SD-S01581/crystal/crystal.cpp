#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+5;
ll n,m,a[N],sm[N],as=1,x,p,mi=1e13;
ll ef(ll i){
	ll l=0,r=i,md;
	while(l<r){
		md=(l+r)/2;
		if(a[i]*(i-md+1)<=sm[i]-sm[md-1]+m){
			r=md;
		}
		else {
			l=md+1;
		}
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		mi=min(mi,a[i]);
	}
	sort(a+1,a+1+n);
	if(mi<0){
		for(ll i=1;i<=n;i++){
			a[i]-=mi;
		}
	}
	
	for(ll i=1;i<=n;i++){
		sm[i]=sm[i-1]+a[i];
	}
	for(ll i=1;i<=n;i++){
		p=ef(i);
		as=max(as,i-p+1);
	}
	cout<<as;
	return 0;
}

