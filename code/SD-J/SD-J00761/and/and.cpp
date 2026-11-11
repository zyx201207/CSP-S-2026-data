#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll ans;
queue<ll> a1, a2;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
    ll n, m;
    scanf("%d%d", &n, &m);
    ll la;
    for (int i = 0; i < n; i++) {
    	scanf("%d", &la);
    	a1.push(la);
	}
	for (ll i = 1 << 29; i > 0; i >>= 1) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (a1.front() & i) {
				cnt++;
			}
			a2.push(a1.front());
			a1.pop();
		}
		if (cnt >= m) {
			ans = ans | i;
		}
		for (int j = 0; j < n; j++) {
			if (cnt < m || a2.front() & i) {
			a1.push(a2.front()); 
			}
			else n--;
			a2.pop();
		}
	}
    cout << ans;
	
	return 0;
} 
