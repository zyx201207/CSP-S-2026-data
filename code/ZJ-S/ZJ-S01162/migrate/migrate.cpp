#include<bits/stdc++.h>
#define ll long long
#define ull long long unsigned
using namespace std;
const int N = 2e6+6;
int c, t, n;
ull d;
ll a[N];

int work() {
	cin >> n >> d;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	if(n <= 1) {
		cout << "0\n";
		return 0;
	}
	ull delta = a[2] - a[1];
	if(2*delta <= d && d < 3*delta) {
		cout << n - 3 << '\n';
	}
	cout << "0\n";
	return 0;
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while(t--) {
		work();
	}
	return 0;
}
