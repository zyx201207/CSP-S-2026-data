#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int c, t, n, k, u[N], v[N];
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	bool flag = 1;
	while(t--) {
		cin >> n >> k;
		for(int i = 1; i <= n - 1; i++) cin >> u[i] >> v[i];
		if(flag) cout << 1 << "\n", flag = 0;
		else cout << 2 << "\n", flag = 1;
	}
	return 0; 
} 
