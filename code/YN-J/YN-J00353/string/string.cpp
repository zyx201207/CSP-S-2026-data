#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 1;
long long s, l, maxl = -1; //³¤¶È
double h;
char maxr, r;

char a[MAXN];
int n;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	int last = 1;
	for (long long i = 1; i <= n; i++) {
		cin >> l >> r;
		for (int j = last; j <= l; j++) {
			a[j] = r;
		}
		if (l > maxl) {
			maxr = r;
			maxl = l;
		}
		last = l + 1;
		s += l;
	}
	h = double(s + 1) / 2.0;
	//cout << h << l;
	long long ans = 0;
	for (long long i = 1; i <= h; i++) {
		if ((a[i] == a[s + 1 - i] && i * 1.0 == h - 0.5) || (i == h)) {
			//cout << i << endl;
			break;
		}
		if (a[i] == maxr) {
			//cout << "value1:" << a[i] << endl;
			if (a[s + 1 - i] == maxr) {
				continue;
				//cout << "value:" << a[s + 1 - i] << endl;
			} else {
				ans++;
				//cout << "at1:" << ans << endl;
			}
		} else {
			ans += 2;
			//cout << "at2:" << ans << endl;
		}

	}
	cout << ans;
	return 0;
}