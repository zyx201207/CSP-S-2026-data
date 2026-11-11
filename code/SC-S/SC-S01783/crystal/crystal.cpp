#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=5e5+5;

ll a[N];
ll d[N];
ll b[N];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n;
	ll m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=n;i>=1;i--){
		ll j=n-i+1;
		d[j]=a[n]-a[i];
		d[j]+=d[j-1];
		b[j]=a[i];
	}
	for(ll i=1;i<=n;i++) a[i]=b[i];
	ll ans=1;
	ll id=1;
	for(ll i=1;i<=n;i++){
		while(id<=n&&d[id]-d[i-1]-(id-i+1)*(a[1]-a[i])<=m) id++;
		ans=max(ans,id-i);
	}
	cout<<ans;
	return 0;
}