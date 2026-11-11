#include <bits/stdc++.h>
#define ll long long
#define pll pair<long long,long long>
using namespace std;
const int N = 2e6+5;
vector<ll> g[N];
ll a[N],ans;

void D(){
	ll T;
	cin >> T;
	while(T--){
		int n,d;
		cin >> n >> d;
		ans = 0;
		for(ll i = 1;i<=n;i++){
			cin >> a[i];
		}for(ll i = 1;i<=n;i++){
			for(ll j = i+2;j<=n;j++){
				if(abs(a[i]-a[j]) <= d) ans++;
			}
		}cout << ans/2 << endl;
	}
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c;
	cin >> c;
	if(c >= 1 and c <= 10){
		D();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
