#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e6+9;
ll n,c,t,d;
ll x[N];
ll dis[N],sum[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while (t--){
		ll n,d;
		cin>>n>>d;
		ll ans = 0;
		for (ll i = 1;i <= n;i++) cin>>x[i];
		
		for (ll l = 1;l <= n;l++){
			//cout<<"&&&&&&&&&&&&"<<l<<endl;
			for (ll i = l+1;i <= n;i++) dis[i] = 1e18;
			for (ll i = l;i <= n;i++) sum[i] = 0;
			dis[l] = 0;
			for (ll r = l+1;r <= n;r++){
				for (ll i = r-1;i >= l;i--){
					//cout<<i<<' '<<r<<"$$"<<endl;
					if (abs(x[r] - x[i]) <= d){
						if (dis[r] == dis[i] + 1) sum[r]++;
						if (dis[i] + 1 < dis[r]){
							dis[r] = dis[i] + 1;
							sum[r] = 1;
						}
						
						//cout<<i<<' '<<r<<' '<<dis[r]<<' '<<sum[r]<<endl;
						
					}else break;
				}
			}
			for (ll r = l;r <= n;r++){
				if (sum[r] == 2){
					
					//cout<<l<<' '<<r<<endl;
					
					ans++;
				}
			}
			
			//cout<<"#######"<<endl;
		}
		
		cout<<ans<<endl;
	}
	return 0;
}
/*
0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989


*/
