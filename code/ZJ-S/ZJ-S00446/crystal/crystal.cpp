#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+5;
ll n,m,a[N],sum[N];
bool ch(ll x){
	for(ll i=1;i<=n-x+1;i++){
		if(a[i+x-1]*x-(sum[i+x-1]-sum[i-1])<=m) return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	ll L=1,R=n,mid,ans=1;
	while(L<=R){
		mid=L+R>>1;
		if(ch(mid)){
			L=mid+1;
			ans=mid;
		}else R=mid-1;
	}
	cout<<ans;
	return 0;
}
