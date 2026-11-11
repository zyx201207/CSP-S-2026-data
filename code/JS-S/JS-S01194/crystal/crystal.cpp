#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=5e5+100;
ll n,m;
ll a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll sum=0,t=n;
	for(ll i=1;i<=n-1;i++){
		sum+=(a[i+1]-a[i])*i;
		if(sum>m){
			sum-=(a[i+1]-a[i])*i;
			t=i;
			break;
		}
	}
	ll ans=t;
	for(ll i=1,j=t+1;j<=n;j++){
		sum+=(a[j]-a[j-1])*(j-i);
		if(sum>m)
		for(;(sum-=(a[j]-a[i++]))>m;);
		ans=max(ans,j-i+1);
	}
	cout<<ans;
	return 0;
}
