#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
int a[500005], ans = 0;
int maxx = LONG_LONG_MIN;
int minn = LONG_LONG_MAX;

//bool check(int x) {


signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		maxx = max(maxx, a[i]), minn = min(minn, a[i]);
	}
	sort(a + 1, a + n + 1);
	for (int i = minn; i <= maxx; i++) {
		int c = 0, id = 1, sum = 0;
		for (int j = 2; j <= n; j++) {
			if (abs(a[id] - i) > abs(a[j] - i)) {
				id = j;
			}
		}
		int l = id - 1, r = id;
//		cout << "！！！！！！！！！！！！！！！！\n";
//		cout << "i:" << i << " " << id << endl;
//		int ts = INT_MIN, t2 = INT_MAX;
		while (l >= 1 and abs(a[l] - i) + c <= m) {
			if (abs(a[l] - i) + c <= m) {
				c += abs(a[l] - i);
//				if (i == -3)
//					cout << c << endl;
				l++;
				sum++;
			}
		}
		ans = max(sum, ans);


	}
	cout << ans;
	return 0;
}
