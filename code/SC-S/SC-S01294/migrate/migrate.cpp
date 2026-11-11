#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int M = 2e6 + 6;
ll a[M], d[M], D;
int c, T, n;
void solA() {
	ll cnt = D / d[2], fst = 2 * cnt - 1;
	if(D <= d[2]) cout << "0\n";
	else cout << max(0ll, n - fst) << "\n"; 
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> T;
	while(T--) {
		cin >> n >> D;
		for(int i = 1; i <= n; i++) d[i] = 0;
		for(int i = 1; i <= n; i++) cin >> a[i], d[i] = a[i] - a[i - 1];
		solA();
	}
	return 0;
}