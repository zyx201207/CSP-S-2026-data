#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
ll a[500005],m,n,l,r;
ll checkl(ll mid){
	ll ansl=0;
	for(int i=l;i<mid;i++){
		ansl+=a[mid]-a[i];
	}
	return ansl;
}
ll checkr(ll mid){
	ll ansr=0;
	for(int i=mid+1;i<r;i++){
		ansr+=a[r]-a[i];
	}
	return ansr;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
	    cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll l=1,r=n,maxn=-1e18;
	while(l<=r && r<=n && l>=1){
		ll mid=(l+r)/2;
		if(checkl(mid)<=m){
			maxn=max(maxn,mid-l+1);
			r++;
		}else{
			r--;
		}
		if(checkr(mid)<=m){
			maxn=max(maxn,r-+1);
			l--;
		}else{
			l++;
		}
	}
	if(a[r]==a[r+1] || a[r-1]==a[r])  maxn++;
	cout<<maxn;
    return 0;
}
