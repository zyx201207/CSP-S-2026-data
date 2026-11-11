#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll maxn=2e6+100,inf=1e18;
ll c,t;
ll n,d;
ll x[maxn],vx[maxn],mx[maxn];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i=1;i<=n;i++){
			cin >> x[i];
		}
		ll ans=0;
		for(int i=1;i<=n-3;i++){
			if((x[i+1]-x[i])<=d&&(x[i+2]-x[i])<=d&&(x[i+3]-x[i])>d&&(x[i+3]-x[i+2])<=d&&(x[i+3]-x[i+1]<=d)){
				ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
