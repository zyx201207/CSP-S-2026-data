#include <iostream>
#include <cstring>
#include <algorithm>

#define int long long 

using namespace std;

const int N = 2e6 + 10;

int c, T, n, d;
int lands[N];
int Min, cnt;

void dfs(int l, int r, int step, int sum) {
//	cout << step << ' ' << sum << ' ' << Min << endl;
	if (step == r) {
		if (sum == Min) cnt ++; 
		else if (sum < Min) {
			cnt = 1;
			Min = sum;
		}
	} else {
		for (int i = step + 1; lands[i] <= lands[step] + d && i < n; i ++) {
//			cout << step << ' ' << i << ' ' << Min << endl;
			dfs(l, r, i, sum + 1);
		}
	}
	
	return;
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	 
	cin >> c >> T;
	while (T --) {
		int ans = 0;
		Min = 0x3f3f3f3f3f3f3f3f;
		
		cin >> n >> d;
		for (int i = 0; i < n; i ++) cin >> lands[i];
		
		for (int i = 0; i < n; i ++) {
			for (int j = i + 1; j < n; j ++) {
				cnt = 0;
				dfs(i, j, i, 0);
//				cout << i << ' ' << j << ' ' << cnt << endl;
				if (cnt == 2) ans ++;
			}
		}
//		dfs(0, 3, 0, 0); 
		cout << ans << endl;
	}
	
	return 0;
}
