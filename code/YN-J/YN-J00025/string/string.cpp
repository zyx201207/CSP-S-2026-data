#include <bits/stdc++.h>
using namespace std;
const int N = 1e8 + 10;
long long int n, a, arr[N], sum = 0;
char c, crr[N];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> c;
		arr[i] = a;
		crr[i] = c;
	}
	int flag = 0;
	char f = crr[0];
	for (int i = 1; i < n; i++) {
		if (crr[i] != f)
			flag++;
	}
	if (flag == 0) {
		cout << 0;
		return 0;
	} else {
		for (int i = 0, j = n; j > i || j == i; i++, j--) {
			if (arr[i] == arr[j]) {
				if (crr[i] != crr[j]) {
					sum += arr[i];
				}
			} else {
				if (arr[i] > arr[j]) {
					sum += arr[j];
					int o = arr[i] - arr[j];
					while (o = 0) {
						if (arr[j - 1] == o) {
							sum += o;
							o = 0;
						} else {
							if (o > arr[j - 1]) {
								sum += arr[j - 1];
								o -= arr[j - 1];
							} else {
								sum += o;
								arr[j - 1] -= o;
							}
						}
					}
				} else
					sum += arr[i];

			}
		}
	}
	cout << sum / 2;
	return 0;
}