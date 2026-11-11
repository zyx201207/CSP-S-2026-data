#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t;
ll a[2000010];
void f(){
	ll n,d;
	cin>>n>>d;
	ll ans=0;
	for(ll i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<n;i++){
		if(a[i+1]-a[i]>d)continue;
		ll j=i+1;
		while(j<=n&&a[j]-a[j-1]<=d){
			if((a[j]-a[i])/d&&(a[j]-a[i])%d==d-1)ans++;
			j++;
		}
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(ll ti=0;ti<t;ti++){
		f();
	}
	return 0;
} 
