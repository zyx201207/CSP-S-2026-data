#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[1000006],sum;
ll qz[1000005];
bool check(ll pos){
	/*for(ll l=1;l<=n;l++){
		ll r=l+pos-1;
		if(r>n) break;
		ll res=qz[r]-qz[l-1];
		ll ned=pos*a[r];
		if(ned-res<=m) return 1;
	}*/
	ll l=1,r=pos,res=0;
	for(ll i=l;i<=r;i++){
		res+=a[r]-a[i];
	}
	if(res<=m) return 1;
	while(r<n){
		l++;r++; 
		res-=a[r-1]-a[l-1];
		res+=(pos-1)*(a[r]-a[r-1]);
		if(res<=m) return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
 	cin>>n>>m;
 	sum=m;
 	for(ll i=1;i<=n;i++){
 		cin>>a[i];
 		qz[i]=qz[i-1]+a[i];
 		sum+=a[i];
	}
	sort(a+1,a+n+1);
	ll l=1,r=n,mid,ans=0;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
