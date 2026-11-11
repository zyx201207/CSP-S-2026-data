#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int n, m, ans = -1, d;
int a[N];
bool f = 1;
inline int read () {
	int s = 0, f = 1; char c = getchar ();
	while (! isdigit (c)) { if (c == '-') f = -1; c = getchar (); }
	while (isdigit (c)) { s = (s << 1) + (s << 3) + (c ^ 48); c = getchar (); }
	return s * f;
}
void solve () {
	if (n & 1 && (n / 2 + 1) * (n / 2) * d <= m) {
		cout << n << endl;
		return;
	} else if (n & 1 && (n / 2) * (n / 2) * d <= m) {
		cout << n << endl;
		return;
	}
	int cnt = 1;
	for (int i = 1; i <= n / 2; i++)
		if (m > 2 * i * d) {
			m -= 2 * i * d;
			cnt += 2;
		} else if (m > i * d) {
			m -= i * d;
			cnt++;
		} else break;
	cout << cnt << endl; 
}
signed main () {
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	n = read (); m = read ();
	int tmp = m;
	for (int i = 1; i <= n; i++) a[i] = read ();
	for (int i = 1; i <= n; i++)
		if (i <= 2) d = a[2] - a[1];
		else {
			if (a[i] - a[i - 1] != d) {
				f = 0;
				break;
			}
		}
	if (f) {
		solve ();
		return 0;
	}
	sort (a + 1, a + n + 1);
	for (int k = 1; k <= n; k++) {
		m = tmp;
		int cnt = 1;
		for (int i = k, j = k; ; )
			if (i <= 1 && j >= n) break;
			else if ((a[k] - a[i - 1] < a[j + 1] - a[k] || j >= n) && i > 1) {
				if (a[k] - a[i - 1] > m) break;
				i--; cnt++;
				m -= a[k] - a[i];
			} else if ((a[k] - a[i - 1] > a[j + 1] - a[k] || i <= 1) && j < n) {
				if (a[j + 1] - a[k] > m) break;
				j++; cnt++;
				m -= a[j] - a[k];
			} else if (a[k] - a[i - 1] == a[j + 1] - a[k]) {
				while (a[k] - a[i - 1] == a[j + 1] - a[k] && i > 1 && j < n && m >= (a[j + 1] - a[k]) * 2) {
					i--; j++; cnt += 2;
					m -= (a[k] - a[i]) * 2;
				}
				if (a[k] - a[i - 1] == a[j + 1] - a[k] && m >= a[k] - a[i - 1]) {
					i--; cnt++;
					m -= a[k] - a[i];
				}
			}
		if (cnt == n) {
			cout << cnt << endl;
			return 0;
		}
		ans = max (ans, cnt);
	}
	cout << ans << endl;
	return 0;
}
