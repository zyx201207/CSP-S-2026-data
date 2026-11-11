#include<bits/stdc++.h>
using namespace std;
#define int long long
inline long long fff(int l, int r, vector<int> &v, int d, int n) {
	int ans = 0;
	ans++;
	int anum = 0, bnum = 0;
	if (v[l + 1] - v[l - 1] > d && v[l] - v[l - 1] <= d) {
		for (int j = l - 1; j >= 0; j--) {
			if (v[l - 1] - v[j] <= d) {
				anum++;
			} else break;
		}
	}
	if (v[r + 1] - v[r - 1] > d && v[r + 1] - v[r] <= d) {
		for (int j = r + 1; j <= n; j++) {
			if (v[j] - v[r + 1] <= d) {
				bnum++;
			} else break;
		}
	}
	ans += (anum && bnum ? anum*bnum : anum + bnum);
	return ans;
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--) {
		int n, d;
		cin >> n >> d;
		if (n <= 3) {
			for (int i = 0, a; i < n; i++) cin >> a;
			cout << "0\n";
			continue;
		}
		vector<int> v;
		v.push_back(LLONG_MIN);
		for (int i = 0, a; i < n; i++) {
			cin >> a;
			v.push_back(a);
		}
		v.push_back(LLONG_MAX);
		long long ans = 0;
		for (int i = 1; i <= n - 3; i++) {
			if (v[i + 3] - v[i] > d && v[i + 2] - v[i] <= d && v[i + 3] - v[i + 1] <= d) {
				ans += fff(i, i + 3, v, d, n);
				for (int j = i + 4; j <= n; j++) {
					if (v[j] - v[i + 1] <= d) {
						ans += fff(i, j, v, d, n);
					} else break;
				}
				for (int j = i - 1; j >= 1; j--) {
					if (v[i + 2] - v[j] <= d) {
						ans += fff(j, i + 3, v, d, n);
					} else break;
				}
			}
		}
		cout << ans << '\n';
	}
}
/*
调不出来了
期望得分：8
期望总分：140
*/