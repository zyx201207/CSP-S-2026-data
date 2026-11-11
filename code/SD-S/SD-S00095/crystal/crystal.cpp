#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll n,m;
ll a[N],b[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	ll ans=0;
	ll d=a[2]-a[1];
	for(ll i=1;i<=n;i++){
		if(i<n&&d!=a[i+1]-a[i]) d=-1;
		b[i]=b[i-1]+a[i];
	}
	if(d!=-1){
		ans=m/d;
		for(ll i=n-1;i>=1;i--){
			if(i*(i+1)<=ans*2){
				ans=i;
				break;
			}
		}
		cout<<ans;
		return 0;
	}
	for(ll i=n;i>=1;i--){
		for(ll j=1;j+i-1<=n;j++){
			ll u=i*a[j+i-1]-(b[j+i-1]-b[j-1]);
			if(u==m||(u<m&&i<n)){
				ans=i;
				break;
			}
		}
		if(ans) break;
	}
	cout<<ans;
	return 0;
}

