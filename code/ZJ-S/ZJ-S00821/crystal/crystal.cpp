#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[500010];
ll check(ll x){
	ll sum=0;
	ll cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i]>x)break;
		sum+=(x-a[i]);
		cnt++;
	}
	if(sum<=m)return cnt;
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	ll l,r;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1){
			l=a[1],r=a[1];
		}else{
			l=min(a[i],l);
			r=max(a[i],r);
		}
	}
	sort(a+1,a+1+n);
	ll ans=1;
	while(l<=r){
		ll mid=(l+r)/2;
		ll k=check(mid);
		if(k!=0){
			ans=k;
			l=mid+1;
		}else r=mid-1;
	}
	cout<<ans;
	return 0;
}