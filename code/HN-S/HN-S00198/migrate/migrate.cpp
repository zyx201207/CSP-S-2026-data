#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6+10;
ll a[N];

void solve() {
	ll n,d;
	cin>>n>>d;
	for(int i=1 ; i<=n; i++) {
		cin>>a[i];
	}
	ll k;
	if(a[3]-a[2] ==a[2]-a[1]) {
		k = labs(a[3]-a[2]);
		if(n<4) {
			cout<<0<<"\n";
			return ;
		}
		if(d == 2*k) {
			cout<<n-3<<"\n";
			return ;
		} else {
			cout<<0<<"\n";
			return ;
		}
	}
	if(n<4) {
		cout<<0<<"\n";
		return ;
	}

}

int main() {
	freopen("migrate.in", "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--) {
		solve();
	}
	return 0;
}

