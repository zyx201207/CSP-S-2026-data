#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],qzh[500005];
bool ck(ll x){
	for(int i=x; i<=n; i++){
		if(a[i]*x-qzh[i]+qzh[i-x]<=m)return 1;
	}return 0;
}int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1; i<=n; i++)qzh[i]=qzh[i-1]+a[i];
	ll l=0,r=n,ans;
	while(l<=r){
		ll mid=(l+r)/2;
		if(ck(mid)){
			ans=mid;
			l=mid+1;
		}else r=mid-1;
	}cout<<ans;
	return 0;
}