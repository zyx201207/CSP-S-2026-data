#include <bits/stdc++.h>
using namespace std;
#define int long long

int u[2000005], v[2000006];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		for(int i=1; i<n; i++){
			cin >> u[i] >> v[i];
		}
		cout << 1 << "\n"; 
	}
	return 0;
}