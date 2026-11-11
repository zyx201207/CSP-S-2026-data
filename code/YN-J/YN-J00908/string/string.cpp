#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<pair<long long, char>> a(n);
	vector<pair<long long, long long>> l(n);
	int len = 0;
	int js = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
		l[i].first = js;
		js += a[i].first - 1;
		l[i].second = js;
		len += a[i].first;
		js++;
	}
	len /= 2;
	js = 0;
	int R = 0, L = 0;
	for (int i = 0; i < n && js <= len; i++) {
		int k = 0;
		js += a[i].first;
		int h = 0;
		for (int j = n - 1; j >= 0 && h <= len; j++) {

			if (a[j].second == a[i].second) {
				if (l[i].first >= l[j].first && l[i].second <= l[j].second) {
					k += abs(l[i].first - l[i].second) + 1;
				} else if (l[i].first >= l[j].first && l[i].first <= l[j].second) {
					k += abs(l[i].first - l[j].second) + 1;
				} else if (l[i].second >= l[j].first && l[i].second <= l[j].second) {
					k += abs(l[j].first - l[i].second) + 1;
				}
			}
			h += a[j].first;
		}
		R += abs(l[i].first - l[i].second) + 1 - k;
	}
	js = 0;
	for (int i = n - 1; i >= 0 && js <= len; i--) {
		int k = 0;
		js += a[i].first;
		int h = 0;
		for (int j = 0; j < n && h <= len; j++) {

			if (a[j].second == a[i].second) {
				if (l[i].first >= l[j].first && l[i].second <= l[j].second) {
					k += abs(l[i].first - l[i].second) + 1;
				} else if (l[i].first >= l[j].first && l[i].first <= l[j].second) {
					k += abs(l[i].first - l[j].second) + 1;
				} else if (l[i].second >= l[j].first && l[i].second <= l[j].second) {
					k += abs(l[j].first - l[i].second) + 1;
				}
			}
			h += a[j].first;
		}
		L += abs(l[i].first - l[i].second) + 1 - k;
	}
	cout << min(R, L);
}