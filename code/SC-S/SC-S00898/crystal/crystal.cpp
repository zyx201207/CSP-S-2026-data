#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+5;
ll n,m,a[N],ans,sum[N];
bool check(ll x){
	for(ll i=x;i<=n;i++){
		if(a[i]*x-(sum[i]-sum[i-x])<=m)return 1;
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	ll l=1,r=n;
	while(l<=r){
		ll mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}