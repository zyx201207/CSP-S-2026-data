#include <bits/stdc++.h>

#define pb push_back
#define fst first
#define sec second

using namespace std;

using ll = long long;
using ull =unsigned long long;
using i128 = __int128;
using p_q =priority_queue<int>;

namespace sharweek{

const int N = 5e6+50;

ll a[N];
ll s[N];
ll n;
ll m;
ll nds;
ll lp,rp;

bool check(ll k,ll t){
	/*ll l=a[t]-k,r=a[t]+k;
	lp=lower_bound(a+1,a+1+n,l)-a,rp=upper_bound(a+1,a+1+n,r)-a-1;
	lp=max(1ll,lp),rp=min(n,rp);
	nds=(t-lp+1)*a[t]-(s[t]-s[lp-1])+(s[rp]-s[t])-(rp-t+1)*a[t];
	return nds<=m;*/
	
	nds=(t-k+1)*a[t]-(s[t]-s[k-1]);
	return nds<=m;
}

void mian(){
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	ll ans=-1;
	for(ll i=1;i<=n;i++){
		ll l=1,r=i;
		while(l<r){
			ll mid=(l+r)>>1;
			if(check(mid,i)){
				r=mid;
			} else{
				l=mid+1;
			}
		}
		check(r,i);
		ll nans=i-r+1;
		//if(nans==n) cout<<i<<endl;
		/*if(nds<m){
			ll nxc=0;ll nxn=0;
			if(lp>1&&rp<n){
				if(a[i]-a[lp-1]<a[rp+1]-a[i]){
					nxc=a[i]-a[lp-1];
					nxn=lp-(lower_bound(a+1,a+n+1,a[lp-1])-a);
				} else if(a[i]-a[lp-1]>a[rp+1]-a[i]){
					nxc=a[rp+1]-a[i];
					nxn=upper_bound(a+1,a+n+1,a[rp+1])-a-1 - rp;
				} else{
					nxc=a[i]-a[lp-1];
					nxn=lp-(lower_bound(a+1,a+n+1,a[lp-1])-a);
					nxn+=upper_bound(a+1,a+n+1,a[rp+1])-a-1 - rp;
				}
				
			}
			else if(rp<n){
				nxc=a[rp+1]-a[i];
				nxn=upper_bound(a+1,a+n+1,a[rp+1])-a-1 - rp;
			}
			else if(lp>1){
				nxc=a[i]-a[lp-1];
				nxn=lp-(lower_bound(a+1,a+n+1,a[lp-1])-a);
			}
			
			if(lp>1||rp<n){
				nans+=(m-nds)/nxc;
			}
		}*/
		
		ans=max(ans,nans);
	}
	cout<<ans<<endl;
}

}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	ll _=1;
	//cin>>_;
	while(_-->0){
		sharweek::mian();
	}
	
	return 0;
} 

//完蛋了，不会 T1 
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

ducuotile/ll
*/
