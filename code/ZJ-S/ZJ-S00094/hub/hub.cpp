#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t, n, k, u, v;
	cin >> c >> t;
	for (int i = 1; i <= t; i++){
		cin >> n >> k;
		for (int j = 1; j <= n - 1;j ++){
			cin >> u >> v;
		}cout << (k + 1) / 2 << endl;
	}return 0;
}
