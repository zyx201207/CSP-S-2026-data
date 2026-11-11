#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,ans=-1e18;
ll maxn=-1e18,minn=1e18;
ll a[500010],b[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	ll r=1,l=1;
	while(r<=n){
		ll s=b[r]-b[l-1];
		if(m>=(r-l+1)*a[r]-s){
			ans=max(ans,r-l+1);
			r++;
		}else{
			l++;
		}
	}
	cout<<ans;
	return 0;
}