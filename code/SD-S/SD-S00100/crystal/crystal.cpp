#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n,m,a[500005],cnt[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1; i<=n; ++i) cin>>a[i];
	if(n>5000){
		cnt[1]=0;
		for(ll i=2; i<=n; ++i) cnt[i]=cnt[i-1]+(i-1)*(a[i]-a[i-1]);
		ll ans=0;
		for(ll i=1; i<=n; ++i) if(cnt[i]<=m) ans=i;
		cout<<ans;
	}
	else{
		ll ans=0;
		for(ll i=1; i<=n; ++i){
			for(ll j=1; j<=n; ++j) cnt[j]=0;
			for(ll j=i+1; j<=n; ++j) cnt[j]=cnt[j-1]+(j-1)*(a[j]-a[j-1]);
			ll p=0;
			for(ll j=i; j<=n; ++j) if(cnt[j]<=m) p=j-i+1;
			ans=max(ans,p);
		}
		cout<<ans;
	} 
	return 0;
}
