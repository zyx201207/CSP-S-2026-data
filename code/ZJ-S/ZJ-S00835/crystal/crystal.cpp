#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
const int N=5e5+10,M=1e2+10,MOD=1e9+7;
ll n,m,a[N],pre[N];
bool check(ll mid,ll x){return (a[x]*mid-pre[x]+pre[x-mid])<=m;}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	ll ans=0;
	for(ll i=1;i<=n;i++){
		ll l=1,r=i,sum=0;
		while(l<=r){
			ll mid=l+r>>1;
			if(check(mid,i)) sum=mid,l=mid+1;
			else r=mid-1;
		}
		ans=max(ans,sum);
	}
	cout<<ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	IOS;
	int _=1;
//	cin>>_;
	while(_--) solve();
	return 0;
}
