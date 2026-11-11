#include <bits/stdc++.h>
using namespace std;
int n, m, ma;
int arr[200005], s[200005];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	int t = m - 2;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	if (m == 2) {
		for (int i = 1; i <= n; i++) {
			for (int l = i + 1; l <= n; l++) {
				ma = max(ma, (arr[i] & arr[l]));
			}
		}
	} else if (m == 1) {
		for (int i = 1; i <= n; i++) {
			ma = max(ma, arr[i]);
		}
	} else {
		int i1, i2;
		for (int i = 1; i <= n; i++) {
			for (int l = i + 1; l <= n; l++) {
				if ((arr[i]&arr[l]) > ma) {
					i1 = i;
					i2 = l;
				}
				ma = max(ma, (arr[i] & arr[l]));
			}
		}
		s[i1]++;
		s[i2]++;
		while (t) {
			int ma1 = ma;
			ma = 0;
			for (int i = 1; i <= n; i++) {
				if (s[i] == 0) {
					if (ma & arr[i] > ma) {
						i1 = i;
					}
					ma = max(ma, ma1 & arr[i]);
				}
			}
			s[i1]++;
			t--;
		}
	}
	cout << ma;
	return 0;
}


