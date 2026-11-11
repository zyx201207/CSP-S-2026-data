#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n;
	cin >> n;
	long long lenth = -1;

	int list_a[200001] = {};
	string list_c = "";


	for (long long i = 0; i < n; i++) {
		cin >> list_a[i] >> list_c[i];
	}

	lenth = n;
	long long times = 0;
	long long open = 0;
	long long stop = lenth;
	for (long long k = 0; open < stop; k++) {
		if (list_a[open] == list_a[stop]) {
			if (!(list_c[open] == list_c[stop])) {
				times += list_a[open];
			}
			open++;
			stop--;
		} else {
			if (list_a[open] < list_a[stop]) {
				list_a[stop] -= list_a[open];
				if (list_c[open] == list_c[stop]) {
					open++;
				} else {
					times += list_a[open];
					open++;
				}
			} else {
				list_a[open] -= list_a[stop];
				if (list_c[open] == list_c[stop]) {
					stop--;
				} else {
					times += list_a[stop];
					stop--;
				}
			}
		}
	}
	cout << times;
	return 0;
}