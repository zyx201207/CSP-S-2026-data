#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1000;
int n;
long long sum, hf, len, ans;
long long a[N], b[N], c[N];
char sa[N], sb[N], sc[N];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cin >> sa[i];
		len += a[i];
	}
	hf = (len + 1) / 2;
	int xb = 0;
	for (int i = 1; i <= n; i++) {
		xb++;
		sum += a[i];
		if (sum > hf) {
			b[xb] = hf - sum + a[i];
			sb[xb] = sa[i];
			break;
		} else {
			b[xb] = a[i];
			sb[xb] = sa[i];
		}
	}
	int xc = 0;
	xc++;
	c[xc] = sum - hf;
	sc[xc] = sb[xb];
	for (int i = xb + 1; i <= n; i++) {
		xc++;
		c[xc] = a[i];
		sc[xc] = sa[i];
	}
	for (int i = 1, j = xc; i <= xb, j >= 1;) {
		if (b[i] > c[j]) {
			if (sb[i] == sc[j]) {
				b[i] -= c[j];
				j--;
			} else {
				ans += c[j];
				b[i] -= c[j];
				j--;
			}
		} else if (b[i] < c[j]) {
			if (sb[i] == sc[j]) {
				c[j] -= b[i];
				i++;
			} else {
				ans += b[i];
				c[j] -= b[i];
				i++;
			}
		} else if (b[i] == c[j]) {
			if (sb[i] == sc[j]) {
				i++;
				j--;
			} else {
				ans += b[i];
				i++;
				j--;
			}
		}
	}
	cout << ans;
	return 0;
}
