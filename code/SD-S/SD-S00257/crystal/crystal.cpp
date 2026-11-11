#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+10;
ll n,m,a[N],s[N],ans=0,maxn=-1e18,minn=1e18;
inline bool check(ll x){
	ll cha=0;
	for(ll i=1;i<=n;i++){
		if(a[i]<x) cha+=(x-a[i]);
	}
	return cha<=m;
}
inline ll solve(ll x,ll idx){
	ll res=0,can=m;
	for(ll i=idx-1;i>=1;i--){
		if(x-a[i]>can) break;
		ll need=x-a[i];
		can-=need;
		res++;
	}
	return res+1;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	bool f1=true,f2=true;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		minn=min(minn,a[i]);
		if(a[i]!=i) f1=false;
		if((a[i]-a[i-1]!=a[i-1]-a[i-2])&&i>=3) f2=false;
	}
	if(f1==true){
		ans=-1;
		for(ll i=1;i<=n;i++){
			if(((i+1)*i)/2>m){
				ans=i;
				break;
			}
		}
		if(ans==-1) ans=n;
		cout<<ans<<'\n';
		return 0;
	}
	if(f2==true){
		ll cha=(ll)abs(a[2]-a[1]);
		ans=-1e18;
		for(ll i=1;i<=n;i++){
			if(((i+1)*i)*cha/2>m){
				ans=i;
				break;
			}
		}
		if(ans==-1e18) ans=n;
		cout<<ans;
		return 0;
	} 
	sort(a+1,a+1+n);
	if(n<=5000){
		for(ll i=1;i<=n;i++) ans=max(ans,solve(a[i],i));
		cout<<ans;
		return 0;
	}
	else{
		ll l=minn,r=maxn;
		while(l<r){
			ll mid=(l+r+1) >> 1;
			if(check(mid)) l=mid;
			else r=mid-1;
		}
		for(ll i=1;i<=n;i++){
			if(a[i]<=l) ans++;
		}
		cout<<ans;
	}
	return 0;
}
