#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m;
ll a[500010];
bool check(ll x){
	ll cnt=0,mx=0;
	ll mn=0x3f3f3f3f3f3f3f3f;
	for(ll i=1;i<=x;i++){
		mx=max(mx,a[i]);
	}
	for(ll i=1;i<=x;i++){
		cnt+=mx-a[i];
	}
	mn=min(mn,cnt); 
	//cout<<cnt<<" ";
	for(ll l=2;l<=n-x+1;l++){
		ll cur=mx;
		cnt-=mx-a[l-1];
		mx=max(mx,a[l+x-1]);
		cnt+=(x-1)*(mx-cur);
		mn=min(mn,cnt);
		//cout<<cnt<<" ";
	}
	return mn<=m;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll l=0,r=n,ans;
	while(l<=r){
		ll mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
} 
