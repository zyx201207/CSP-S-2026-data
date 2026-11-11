#include <bits/stdc++.h>
using namespace std;
constexpr int N=2000005;
using ll=long long;
int n;ll d;
ll x[N];
int main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);    
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int c,t;cin>>c>>t;
    while(t--){
    	cin>>n>>d;
//    	cout<<n<<":";
    	for(int i=1;i<=n;++i){
    		cin>>x[i];
		}
		ll f=abs(x[2]-x[1]);
		ll mf=abs(x[n]-x[1]);
//		cout<<f<<"/"<<d<<"  ";
		ll ans=0;
		if(f*2LL>d||d>mf){
			ans=0;
		}
		else if(f*3LL>d){
			ans=n-3;
		}
		else if(f*4LL>d){
			ans=n-5;
		}
		else if(f*173330LL>d){
			ans=n-173331;
		}
		cout<<ans<<'\n';
	}
	return 0;
} 

