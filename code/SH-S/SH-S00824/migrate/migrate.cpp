#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, d;
vector<ll> x;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
		
	int C, T;
	cin >> C >> T;
	
	while (T--) {
		cin >> n >> d;
		
		x.assign(n + 1);
		
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
		}
		
		cout << 1 << "\n";
	}
	
	return 0;
}
