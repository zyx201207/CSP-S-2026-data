#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 5e5 + 10;
int n, m;
int a[N], s[N];

int ans;

bool check(int x, int i) {
	return (x - i) * a[x] - (s[x - 1] - s[i - 1]) <= m;
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];	
		
	} 
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++ ) s[i] = s[i - 1] + a[i];
	//for (int i = 1; i <= n; i++ ) cout << s[i] << " ";
	for (int i = 1; i <= n; i++) {
//		for (int j = i + 1; j <= n; j++) {
//			int sum = (j - i) * a[j] - (s[j - 1] - s[i - 1]);
//			if (sum <= m) {
//				ans = max(ans, j - i + 1);
//			}
//			//printf("i : %d, j : %d, %d\n", i, j, sum);
//		}
		int l = i, r = n;
		while (l <= r) {
			int mid = l + r >> 1;
			if (check(mid, i)) {
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		ans = max(ans, l - i);
	}
	cout << ans << endl;
	return 0;
}
