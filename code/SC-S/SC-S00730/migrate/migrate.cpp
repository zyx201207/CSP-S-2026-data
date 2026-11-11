#include <bits/stdc++.h>
using namespace std;
using i32 = int;
using i64 = long long;
#define READ_FILE 1
const i32 N = 2e6+5;
i32 c,t;
i64 x[N];

i32 main() {
#if READ_FILE
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
#endif
	cin >> c >> t;
	while(t --) {
		i32 n;
		i64 d;
		cin >> n >> d;
		bool sj1_equal_diff = 1;
		i32 sj1_diff = -1;
		for(i32 i=1;i<=n;i++) {
			cin >> x[i];
			if(i == 2) sj1_diff = x[i] - x[i-1];
			else sj1_equal_diff = sj1_equal_diff && x[i] - x[i-1] == sj1_diff;
		}
		
		// sj1
		if(sj1_equal_diff) {
			if(n >= 3) cout << n-2 << '\n';
			else cout << 0 << '\n';
		} else {
			// i dont know...
			cout << 0 << '\n';
		}
	}
	return 0;
}