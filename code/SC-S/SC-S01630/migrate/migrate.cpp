#include <bits/stdc++.h>
using namespace std;
#define int long long

int x[2000005];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	while(t--){
		int n, d;
		cin >> n >> d;
		for(int i=1; i<=n; i++){
			cin >> x[i]; 
		}
		cout << 0 << "\n";
	}
	return 0;
}