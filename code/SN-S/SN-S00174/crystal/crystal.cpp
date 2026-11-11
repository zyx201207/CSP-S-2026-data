#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn=5e5+10;
const ll inf=1e18+10;
ll n,m;
ll a[maxn];
ll sum[maxn];
ll s[maxn];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	ll ans=-inf;
	for(ll i=1;i<=n;i++){
		for(ll j=i;j<=n;j++){
			if(a[j]*(j-i+1)-(sum[j]-sum[i-1])<=m){
				ans=max(ans,j-i+1);
			}
		}
	}
	cout<<ans;
	return 0;
}
