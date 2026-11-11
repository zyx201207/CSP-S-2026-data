#include<bits/stdc++.h>
using namespace std;
typedef  long long ll;
int main() {
    freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c,t;
	cin>>c>>t;
	for(ll i=1;i<=t;i++){
		ll n,d;
		cin>>n>>d;
		ll s[n+1];
		for(int j=1;j<=n;j++){
			cin>>s[j];
		}
		ll p=s[2]-s[1];
		ll cnt=d/p;
		if(cnt==1||n<=2||n<=cnt){
			cout<<0<<endl;
		}else{
			ll k=2*cnt-1;
		cout<<n-k<<endl;
		}	
	}
	return 0;
}
