#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	ll n,m,ans=1; cin>>n>>m;
	vector<ll> a(n+1),f(n+1),cnt(n+1);
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a.begin()+1,a.end());
	cnt[1]=0;
	for(ll i=2;i<=n;i++){
		f[i-1]=a[i]-a[i-1];
		cnt[i]=cnt[i-1]+(i-1)*f[i-1];
		if(cnt[i]>m) break;
		ans++;
	}
	cout<<ans<<"\n";
	/*
	cout<<"\n";
	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	cout<<"\n";
	for(int i=1;i<=n;i++) cout<<f[i]<<" ";
	cout<<"\n";
	for(int i=1;i<=n;i++) cout<<cnt[i]<<" ";
	*/
	return 0;
}