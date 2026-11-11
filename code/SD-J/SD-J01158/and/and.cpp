#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=200007;
ll n,m,ans=-1;
ll a[N];
void dfs(ll i,ll x,ll s) {
	if(x==m) {
		ans=max(ans,s);
		return;
	}
	if(i==n+1) return;
	if((n-i+1)<(m-x)) return;
	dfs(i+1,x+1,(s&a[i]));
	dfs(i+1,x,s);
}
signed main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=1;i<=(n-m);i++) dfs(i+1,1,a[i]);
	cout<<ans<<endl;
	return 0;
} 
