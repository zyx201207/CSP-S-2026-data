#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define cll const long long
#define rep(i,a,b) for(ll i=(a);i<=(b);++i)
#define Rep(i,a,b) for(ll i=(b);i>=(a);--i)
#define Set(x,y) memset(x,y,sizeof(x))
#define Cpy(x,y) memcpy(x,y,sizeof(x))
#define all(x) x.begin(),x.end()
#define ld long double
using namespace std;
cll N=500009;
ll n,a[N],m,s[N]; 
ll cost(ll l,ll r){
	return a[r]*(r-l+1)-(s[r]-s[l-1]);
}
void solve(){
	cin>>n>>m;
	rep(i,1,n)cin>>a[i]; sort(a+1,a+1+n);
	rep(i,1,n)s[i]=s[i-1]+a[i];
	ll res=1;
	rep(j,1,n){
		ll l=1,r=j,ans=1;
		while(l<=r){
			ll mid=(l+r)/2;
			if(cost(mid,j)<=m)ans=mid,r=mid-1;
			else l=mid+1;
		}
//		cerr<<ans<<" "<<cost(ans,j)<<endl;
		res=max(res,j-ans+1);
	}
	cout<<res<<"\n";
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int T=1;// cin>>T;
	while(T--)solve();
	return 0;
}
