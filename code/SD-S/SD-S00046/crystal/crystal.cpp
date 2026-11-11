#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ldb=long double;
using db=double;
using i128=__int128;
using uint=unsigned int;
using ull=unsigned long long;
const ll N=5e5+10;
ll n,m;
ll a[N];
ll sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll ans=1;
	ll j=1;
	for(ll i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		while(j<=i&&a[i]*(i-j+1)-(sum[i]-sum[j-1])>m){
			j++;
		}
		ans=max(ans,i-j+1);
	}
	cout<<ans<<'\n';
	return 0;
}

