#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
typedef long long ll;
ll a[N];
ll n,m;
ll sum[N];
bool check(ll x){
	for(int l=1;l+x-1<=n;l++){
		ll need=x*a[l+x-1]-(sum[l+x-1]-sum[l-1]);
		if(need<=m) return 1;
	}
	return 0;
}
ll find(){
	ll l=1,r=n;
	ll ans=0;
	while(l<=r){
		ll mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else r=mid-1;
	}
	return ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	cout<<find();
	


	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/

