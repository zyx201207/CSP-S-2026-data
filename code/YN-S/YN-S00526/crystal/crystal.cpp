#include <bits/stdc++.h>
using namespace std;
long long m, n;
long long cr[500067];
long long sum = 0;
long long w;
long long wh;
long long num = 1;


void sort() {
	for (long long i = 0; i < n; i++) {
		long long mid;
		if (cr[i] < cr[i + 1]) {
			mid = cr[i];
			cr[i] = cr[i + 1];
			cr[i + 1] = mid;
		}
	}
}

void digui() {
	if (sum / num + w > cr[wh - 1]) {
		num += 1;
		digui();
	}
	if (sum / num + w == cr[wh - 1]) {
		num + 1;
	}
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	cin >> n >> m;
	for (long long i = 0; i < n; i++) {
		cin >> cr[i];
		sum += cr[i];
	}
	sort();
	w = sum / n;
	for (long long i = 0; i < n; i++) {
		if (cr[i] < w) {
			w = cr[i];
			wh = i;
			break;
		}
	}

	for (long long i = wh; i < n; i++) {
		sum = sum - w + cr[i];
		num += 1;
		if (sum < 0) {
			sum -=   w - cr[i];
		}
	}
	if (sum > 0 && sum / num > 0) {
		digui();
	}
	cout << num;

	return 0;
}