#include <iostream>
#include <vector>
using namespace std;

struct Node {
	int s = 0;
	char c;
};

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	Node a[n + 5];
	for (int i = 1; i <= n; i++) {
		cin >> a[i].s >> a[i].c;
	}
	Node h, t;
	long long sum = 0;
	int i = 1, j = n;
	while (i <= j) {
		if (h.s == 0 && t.s == 0) {
			if (a[i].c != a[j].c) {
				if (a[i].s > a[j].s) {
					sum += a[j].s;
					h.s = a[i].s - a[j].s;
					h.c = a[i].c;
				} else if (a[i].s < a[j].s) {
					sum += a[i].s;
					t.s = a[j].s - a[i].s;
					t.c = a[j].c;
				} else {
					sum += a[i].s;
				}
			} else {
				if (a[i].s > a[j].s) {
					h.s = a[i].s - a[j].s;
					h.c = a[i].c;
				} else if (a[i].s < a[j].s) {
					t.s = a[j].s - a[i].s;
					t.c = a[j].c;
				}
			}
			i++, j--;
		} else if (h.s == 0) {
			if (a[i].c != t.c) {
				if (a[i].s > t.s) {
					sum += t.s;
					h.s = a[i].s - t.s;
					h.c = a[i].c;
					t.s = 0;
				} else if (a[i].s < t.s) {
					sum += a[i].s;
					t.s -= a[i].s;
				} else {
					sum += a[i].s;
					t.s = 0;
				}
			} else {
				if (a[i].s > t.s) {
					h.s = a[i].s - t.s;
					h.c = a[i].c;
					t.s = 0;
				} else {
					t.s -= a[i].s;
				}
			}
			i++;
		} else {
			if (a[j].c != h.c) {
				if (a[j].s > h.s) {
					sum += h.s;
					t.s = a[j].s - h.s;
					t.c = a[j].c;
					h.s = 0;
				} else if (a[j].s < h.s) {
					sum += a[j].s;
					h.s -= a[j].s;
				} else {
					sum += a[j].s;
					h.s = 0;
				}
			} else {
				if (a[j].s > h.s) {
					t.s = a[j].s - h.s;
					t.c = a[j].c;
					h.s = 0;
				} else {
					h.s -= a[j].s;
				}
			}
			j--;
		}
	}
	cout << sum;
	return 0;
}
