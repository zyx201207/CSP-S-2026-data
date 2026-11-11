#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 10;
int a[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c, t;
	cin >> c >> t;
	while (t--){
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; i++){
			cin >> a[i];
		}
		if (n <= 3 || m == 1){
			cout << 0 <<"\n";
			continue;
		}
		if (c == 11 || c == 12 ){
			int ca = abs(a[2] - a[1]);
			if (m < ca){
				cout << 0 <<"\n";
				continue;
			}
			int p = m / ca;
			int tmp = n;
			int ans = 0;
			
			for (int i = tmp - 1; i >= 1; i--){
				if (i <= p){
					break;
				}
				if (tmp - 1 == i){
					if (p * 2 > i && abs((i % p) - p) == 1){
						ans++;
					}
				}else {
					if (p * 2 > i && abs((i % p) - p) == 1){
						ans += (n - i);
					}
				}
			}
			cout << ans <<"\n";
		}else {
			cout << 0 << "\n";
		}
	}
	return 0;
}
/*
-std=c++14
*/
