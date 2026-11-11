#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=2e6+5;

ll a[N];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n;
		ll d;
		cin>>n>>d;
		if(n==1){
			cout<<0<<endl;
			continue;
		}
		for(int i=1;i<=n;i++) cin>>a[i];
		ll ddd=a[2]-a[1];
		ll ans=0;
		if(d<ddd) ans=0;
		else if(ddd<=d&&2*ddd>d) ans=0;
		else{
			ll x=d/ddd;
			if(x==2) ans=max(0,n-3);
			else ans=0;
		}
		cout<<ans<<endl;
	}
	return 0;
}