#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
ll x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	//ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int c,T;cin>>c>>T;
	while(T--){
		ll n,d;cin>>n>>d;
		for(int i=1;i<=n;++i)cin>>x[N];
		ll ans=0;
		if(c==11||c==12){
			ll dis=x[2]-x[1];
			if(d/dis<2)ans=0;
			else {
				ll cnt=d/dis;
				ans=n/cnt;
			}
		}
		cout<<ans<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
