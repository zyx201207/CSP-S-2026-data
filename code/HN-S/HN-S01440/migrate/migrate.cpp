#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 5e5 + 10;
int T = 1;
ll c, n, m, d;
ll a[N];
void solve() {
	cin>> n >> d;
	vector<ll> a(n + 1);
	for(int i = 1; i <= n; i++) {
		cin>> a[i];
	}
	cout<< (n + 1) / d - 1 << '\n';
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	cin>> c >> T;
	while(T--) solve();
	return 0;
} 
