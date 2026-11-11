#include <bits/stdc++.h>

#define int long long
#define endl '\n'

using namespace std;

struct str{
	int a;
	int s[50];
} a[200010];
int n, m;
string s[200010];

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int maxx = -1;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].a;
		int a1 = a[i].a;
		int k, sum = 1;
		for (k = 1; sum <= a1; k++) {
			sum *= 2;
		}
		k -= 1;
		maxx = max(maxx, k);
		for (int j = k; j >= 0; j--) {
			if (a1 >= sum) {
				a[i].s[40 - j] = 1;
				a1 -= sum;
			}
			sum /= 2;
		}
	}
	for (int i = 41 - maxx; i <= 40; i++) {
		if (n == m) {
			break;
		}
		for (int j = 1; j <= n; j++) {
			while (1) {
				if (j != 1 && a[j].s[i] > a[j - 1].s[i]) {
					swap(a[j], a[j - 1]);
					j--;
				}
				else {
					break;
				}
			}
		}
		int taotai;
		for (int j = n; j >= 1; j--) {
			if (a[j].s[i] >= 1) {
				taotai = n - j;
				break;
			}
		}
		if (taotai <= n - m) {
			n -= taotai;
		}
	}
	int ans = a[1].a;
	for (int i = 2; i <= n; i++) {
		ans &= a[i].a;
	}
	cout << ans;
	return 0;
}
