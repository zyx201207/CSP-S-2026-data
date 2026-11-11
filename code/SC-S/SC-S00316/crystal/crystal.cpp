#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+10;
ll n,m;
ll a[N],f[N];
bool check(ll x){
	for(ll i=1;i+x-1<=n;i++){
		ll nd=a[i+x-1]*x-(f[i+x-1]-f[i-1]);
		if(nd<=m) return 1;
	}
	return 0;
}
int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++) f[i]=f[i-1]+a[i];
	ll l=0,r=n,mid;
	while(l<r){
		mid=(l+r+1)>>1;
		if(check(mid)){
			l=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<l;
	return 0;
}