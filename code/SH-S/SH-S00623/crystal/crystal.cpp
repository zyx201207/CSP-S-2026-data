#include<bits/stdc++.h>
#define pll pair<ll,ll>
#define mkp make_pair
#define fi first
#define se second
using namespace std;
typedef long long ll;
const ll N=5e5+9;
const ll INF=1e18;
ll n,m,a[N],s[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	ll ans=0;
	for(ll i=1,j=0;i<=n;i++){
		while((i-j)*a[i]-(s[i]-s[j])>m) j++;
		ans=max(ans,i-j);
	}
	cout<<ans<<'\n';
	return 0;
}
