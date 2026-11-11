#include <bits/stdc++.h>
using namespace std;
#define int long long

void fre() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
}
int n;
int a[(int)2e5 + 2];
char c[(int)2e5 + 2];
int wb[(int)2e5 + 2];
int t[(int)2e5 + 2];
int z;
int minn;

signed main() {
	fre();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		t[i] = z + 1;
		z += a[i];
		wb[i] = z;
	}
	for (int i = n; i >= 1; i--) {
		int l = 1, r = n, ans = -1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (wb[mid] >= z - wb[i] + 1) {
				ans = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		int ans1 = -1;
		l = 1, r = n;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (wb[mid] >= z - t[i] + 1) {
				ans1 = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		if (ans == ans1) {
			if (c[ans] != c[i]) {
				minn += a[i];
			}
		} else {
			for (int j = ans; j <= ans1; j++) {
				if (c[i] != c[j]) {
					minn += a[j];
					if (j == ans) {
						minn -= abs(t[j] - (z - wb[i])) + 1;
					} else if (j == ans1) {
						minn -= abs(wb[j]  - (z - t[i]));
					}
				}
			}
		}
//		cout << minn << " " << ans << " " << t[i] << " " << wb[i] << '\n';
		if (t[i] - 1 <= z / 2 + (z % 2)) {
			break;
		}
	}
	cout << minn;
	return 0;
}
/*
2
2 a
3 a

3
2 a
2 b
1 c

*/