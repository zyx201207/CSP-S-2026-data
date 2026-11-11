#include<bits/stdc++.h>
using namespace std;
#define int long long
int c, t, n, d, x[2000007], ans;
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i = 1; i <= n; i++)
			cin >> x[i];
		if(n <= 3){
			cout << "0\n";
			continue;
		}
		ans = 0;
		for(int l = 1; l <= n; l++)
		for(int r = l + 3; r <= n; r++){
			int len = 0;
			bool flag = 0;
			for(int i = l; i < r; len++){
				int nxt = upper_bound(x + i, x + r + 1, x[i] + d) - x - 1;
				if(i == nxt){
					flag = 1;
					break;
				}
			}
			if(flag)
				continue;
			ans++;
		}
		cout << ans << "\n";
	}
	return 0;
}
