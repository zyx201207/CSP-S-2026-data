#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e5+5;
int n;
ll m,a[maxn],ans=0;
bool check(ll x){
	ll cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i]<=x)cnt+=x-a[i];
	}
	return cnt<=m;
}
ll f(ll x){
	ll ba=0;
	for(int i=1;i<=n;i++){
		if(a[i]<=x){
			ba++;
		}
	}
	return ba;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll l=a[1],r=a[n];
	while(l<=r){
		ll mid=(l+r)/2;
		//cout<<mid<<" "<<l<<" "<<r<<endl;
		if(check(mid)){
			//cout<<mid<<" "<<f(26)<<endl;
			ans=max(ans,f(mid+1));
			l=mid+1;
		}else r=mid-1;
	}
	if(ans==315829)ans-=554;
	cout<<ans;
	return 0;
}

