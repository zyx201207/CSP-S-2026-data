#include<bits/stdc++.h>
#define now_time ((int)(((double)clock()/CLOCKS_PER_SEC)*1000))
#define all_memory ((&St-&Ed)/1024.0/1024.0)

using namespace std;
using ll=long long;

namespace Usd{bool St;}

constexpr ll N=5e5;

ll n,m,a[N+5];

bool check(ll k){
	ll sm=0;
	for(ll i=1;i<=n;++i){
		sm+=a[i];
		if(i>=k&&k*a[i]-sm<=m)  return 1;
		if(i>k) sm-=a[i-k];
	}
	return 0;
}

namespace Usd{bool Ed;void out(){cerr<<"   time: "<<now_time<<"ms\n memory: "<<all_memory<<"MiB\n";}}
//14:30  --  14:55
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+n+1);
	ll l=1,r=n;
	while(l<r){
		ll mid=(l+r+1)>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l<<"\n";
	return 0;
}
