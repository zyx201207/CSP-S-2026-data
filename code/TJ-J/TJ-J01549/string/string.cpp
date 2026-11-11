#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	long long cnt9 = 0;
	vector <char> a;
	vector<long long> b;
	for (int _ = 0; _ < n; _++) {
		long long i;
		char j;
		cin >> i >> j;
		cnt9 += i;
		b.push_back(i);
		a.push_back(j);
	}
	if (cnt9 % 2 == 0) {
		long long mid = cnt9 / 2;
		long long cnt2 = 0, i0;
		for (int i = 0; i < n; i++) {
			cnt2 += b[i];
			if (cnt2 >= mid) {
				long long cnt3 = cnt2 - b[i];
				char o = a[i];
				i0 = i;
				b[i] = mid - cnt3;
				b.insert(b.begin() + i + 1, cnt2 - mid);
				a.insert(a.begin() + i + 1, o);
				break;
			}
		}
		int i1 = i0, i2 = i0 + 1;
		int cnt = 0;
		while (i1 >= 0 && i2 <= n) {
			char left = a[i1], right = a[i2];
			long long l = b[i1], r = b[i2];
			if (left == right) {
				if (l > r) {
					b[i1] -= r;
					i2++;
				} else if (r > l) {
					b[i2] -= l;
					i1--;
				} else {
					i1--;
					i2++;
				}
			} else {
				if (l > r) {
					b[i1] -= r;
					i2++;
					cnt += r;
				} else if (r > l) {
					b[i2] -= l;
					i1--;
					cnt += l;
				} else {
					i1--;
					i2++;
					cnt += r;
				}
			}
		}
		cout << cnt << endl;
	} else {
		long long mid = cnt9 / 2 + 1;
		long long cnt2 = 0, i0;
		for (int i = 0; i < n; i++) {
			cnt2 += b[i];
			if (cnt2 >= mid) {
				long long cnt3 = cnt2 - b[i];
				char o = a[i];
				i0 = i;
				b[i] = mid - cnt3 - 1;
				b.insert(b.begin() + i + 1, cnt2 - mid);
				a.insert(a.begin() + i + 1, o);
				break;
			}
		}
		int i1 = i0, i2 = i0 + 1;
		long long cnt = 0;
		while (i1 >= 0 && i2 <= n) {
			char left = a[i1], right = a[i2];
			long long l = b[i1], r = b[i2];
			if (left == right) {
				if (l > r) {
					b[i1] -= r;
					i2++;
				} else if (r > l) {
					b[i2] -= l;
					i1--;
				} else {
					i1--;
					i2++;
				}
			} else {
				if (l > r) {
					b[i1] -= r;
					i2++;
					cnt += r;
				} else if (r > l) {
					b[i2] -= l;
					i1--;
					cnt += l;
				} else {
					i1--;
					i2++;
					cnt += r;
				}
			}
		}
		cout << cnt << endl;
	}
}