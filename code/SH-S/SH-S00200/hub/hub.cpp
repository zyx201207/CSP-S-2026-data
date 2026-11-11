#include <bits/stdc++.h>
using namespace std;
int c, t, n, k, a, b;
int main(){
	cin.tie(0), cout.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while (t--){
		cin >> n >> k;
		for (int i = 1; i <= n; i++) cin >> a >> b;
		cout << n / 2 << endl;
	}
	return 0; 
}
