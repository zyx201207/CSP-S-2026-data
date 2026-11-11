#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
ll d;
ll a[2000005];
void solve1() {
	cin >> n >> d;
	for(int i = 1;i <= n;++i) cin >> a[i];
	ll dd = a[2] - a[1];
	ll cnt = d / dd;
	if(cnt <= 1) {
		cout << "0\n";
	} else {
		cout << max(n - 2 * cnt + 1,0ll) << "\n";
	}
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int c,t;
	cin >> c >> t;
	while(t--) {
		solve1();
	}
	return 0;
}
