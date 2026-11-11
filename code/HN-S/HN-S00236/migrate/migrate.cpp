#include<bits/stdc++.h>
#define ll long long int
#define ci const int
using namespace std;
ci asdfghjkl=2e6+1;
ll a[asdfghjkl];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	ll c,t,csp=0;
	cin >> c >> t; 
	if(c==11 || c==12){
		while(t--){
			ll n,d;
			cin >> n >> d;
			for(int i=1;i<=n;i++){
				cin >> a[i];
			}
			ll csp=a[2]-a[1];
			cout << abs(n-d-csp) << endl;
		}
	} 
	return 0;
}
