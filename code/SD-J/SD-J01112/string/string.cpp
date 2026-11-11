#include <bits/stdc++.h>
#define int long long
const int N = 2e5 + 5;
using namespace std;
int n, cnt1, cnt2, len, len1;
int a[N], b, vis1, vis2, ans;
char c[N];
int sum;
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		len += a[i];
	}
	len1 = len;
	len /= 2;
	for (int i = 1; i <= n && sum + a[i] <= len; i++) {
		b = i;
		sum += a[i];
	}
	if (sum < len) {
		int x = len - sum;
		b++;
		int fronta = x, backa = (len1 % 2 == 0 ? a[b] - x : a[b] - x - 1);
		char frontc = c[b], backc = c[b];
		cnt1 = cnt2 = b;
		while (vis1 < len && vis2 < len) {
			if (frontc == backc) {
				if (fronta == backa) {
					vis1 += fronta;
					vis2 += backa;
					fronta = a[--cnt1];
					backa = a[++cnt2];
					frontc = c[cnt1];
					backc = c[cnt2];
				} else if (fronta < backa) {
					vis1 += fronta;
					vis2 += fronta;
					backa -= fronta;
					fronta = a[--cnt1];
					frontc = c[cnt1];
				} else {
					vis1 += backa;
					vis2 += backa;
					fronta -= backa;
					backa = a[++cnt2];
					backc = c[cnt2];
				}
			} else {
				if (fronta == backa) {
					ans += fronta;
					vis1 += fronta;
					vis2 += backa;
					fronta = a[--cnt1];
					backa = a[++cnt2];
					frontc = c[cnt1];
					backc = c[cnt2];
				} else if (fronta < backa) {
					ans += fronta;
					vis1 += fronta;
					vis2 += fronta;
					backa -= fronta;
					fronta = a[--cnt1];
					frontc = c[cnt1];
				} else {
					ans += backa;
					vis1 += backa;
					vis2 += backa;
					fronta -= backa;
					backa = a[++cnt2];
					backc = c[cnt2];
				}
			}
		}
	} else {
		int fronta = a[b], backa = a[b + 1];
		char frontc = c[b], backc = c[b + 1];
		cnt1 = b, cnt2 = b + 1;
		while (vis1 < len && vis2 < len) {
			if (frontc == backc) {
				if (fronta == backa) {
					vis1 += fronta;
					vis2 += backa;
					fronta = a[--cnt1];
					backa = a[++cnt2];
					frontc = c[cnt1];
					backc = c[cnt2];
				} else if (fronta < backa) {
					vis1 += fronta;
					vis2 += fronta;
					backa -= fronta;
					fronta = a[--cnt1];
					frontc = c[cnt1];
				} else {
					vis1 += backa;
					vis2 += backa;
					fronta -= backa;
					backa = a[++cnt2];
					backc = c[cnt2];
				}
			} else {
				if (fronta == backa) {
					ans += fronta;
					vis1 += fronta;
					vis2 += backa;
					fronta = a[--cnt1];
					backa = a[++cnt2];
					frontc = c[cnt1];
					backc = c[cnt2];
				} else if (fronta < backa) {
					ans += fronta;
					vis1 += fronta;
					vis2 += fronta;
					backa -= fronta;
					fronta = a[--cnt1];
					frontc = c[cnt1];
				} else {
					ans += backa;
					vis1 += backa;
					vis2 += backa;
					fronta -= backa;
					backa = a[++cnt2];
					backc = c[cnt2];
				}
			}
		}
	}
	cout << ans;
	return 0;
}
