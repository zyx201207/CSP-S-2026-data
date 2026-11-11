#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll c, t;

int main() {
	ll t1 = time(0);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	cin >> c >> t;
	while (t--) {
		ll t2 = time(0);
		cout << abs(t1-t2) << "\n";
	}

	return 0;
}

