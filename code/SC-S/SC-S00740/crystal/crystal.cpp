#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const ll mx=5e5+10;
ll n,m;
ll a[mx],sum[mx];
bool check(ll x){
	for(int i=x;i<=n;i++){
		if((x-1)*a[i]-sum[i-1]+sum[i-x]<=m) return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	ll l=1;
	ll r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)==1){
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<ans;
	return 0;
} 