#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+2;
ll n,m,a[N],ans,cf;
bool check(ll x,ll p) {
	ll now=0;
	for(ll i=x;i<p;i++) {
		now+=a[p]-a[i];
		if(now>m) return 0;
	}
	if(now>m) return 0;
	return 1;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	bool bo=1;
	for(ll i=1;i<=n;i++) {
		cin>>a[i];
		if(i==1) continue;
		else if(i==2) cf=a[2]-a[1];
		else if(cf!=a[i]-a[i-1]) bo=0;
	}
	if(bo) {
		ll i;
		for(i=1;i<=n;i++) {
			if((ll)i*(i-1)/2>m) break;
//			cout<<i<<' '<<i*(i-1)/2<<'\n';
		}
		cout<<i-1;
		return 0;
	}
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++) {
		ll l=1,r=i;
		while(l+1<r) {
			ll mid=(l+r)/2;
			if(check(mid,i)) r=mid;
			else l=mid;
		}
		if(check(l,i)) l=l;
		else if(check(r,i)) l=r;
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
/*
4 7
1 5 9 13

4 100
1 2 3 4
*/
