#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500005],z,qz[500005],ans;
ll find(ll l,ll r,ll x){
	while(l+1<r){
		ll mid=l+r>>1;
		if(qz[x]-qz[mid]<=m){
			r=mid;
		}else{
			l=mid;
		}
	}
	return x-r+1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		z+=a[i];
	}
	sort(a+1,a+1+n);
	a[0]=a[1];
	qz[1]=0;
	qz[0]=999999999999;
	qz[n+1]=999999999999;
	for(ll i=2;i<=n;i++){
		qz[i]=qz[i-1]+a[i]-a[i-1];
		ll jl=find(0,i+1,i);
		if(jl>ans){
			ans=jl;
		}
	}
	cout<<ans;
	return 0;
} 
