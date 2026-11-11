#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N=500005;
ll n,m,a[N],s[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	s[0]=0;
	for(ll i=1;i<=n;++i){
		s[i]=s[i-1]+a[i];
	}
	ll ans=1;
	for(ll r=1,l=0;r<=n;++r){
		while(l<=r&&a[r]*(r-l)-(s[r]-s[l])>m)l++;
		ans=max(ans,r-l);
	}
	cout<<ans<<"\n";
	return 0;
}
