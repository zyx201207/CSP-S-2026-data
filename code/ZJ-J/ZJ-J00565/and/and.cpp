#include <iostream>
#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;
ll n,m;
ll a[200005];
ll ans=-1e18;
void dfs(ll sum,ll id,ll cnt){
	if (cnt==m){
		ans=max(ans,sum);
		return;
	}
	if (id+(m-cnt)>n){
		return;
	}
	if (sum<=ans){
		return;
	}
	for (ll i=id+1;i<=n;i++){
		if (sum&a[i]<=ans){
			continue;
		}
		dfs(sum&a[i],i,cnt+1);		
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for (ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,greater<ll>());
	if (n>2000&&m!=n-1){
		ans=a[1];
		for (ll i=1;i<=m;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	for (ll i=1;i<=n-m;i++){
		dfs(a[i],i,1);
	}
	cout<<ans;
	return 0;
}
