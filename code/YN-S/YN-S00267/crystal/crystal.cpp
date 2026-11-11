#include <bits/stdc++.h>
using namespace std;
long n;
long m;
long average;
long minNumber;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	int arr[n];
	long min = 0;
	long sum = 0;

	for (int i = 0; i < n; i++) {

		cin >> arr[i];
		average += arr[i];
	}

	average /= n;

	if (arr[0] > average)
		min = arr[0] - average;
	else
		min = average - arr[0];

	for (int i = 0; i < n; i++) {

		if (arr[i] > average) {
			if (arr[i] - average < min) {
				min = arr[i] - average;
				minNumber = arr[i];

			}
		} else {
			min = average - arr[i];
			minNumber = arr[i];

		}
	}

	for (int i = 0; i < n; i++) {

		if (arr[i] < minNumber) {
			m -= minNumber - arr[i];
			arr[i] = arr[i] + (minNumber - arr[i]);

			if (m <= 0)
				break;
		}
	}

	for (int i = 0; i < n; i++) {

		if (arr[i] == minNumber)
			sum++;

	}

	cout << sum;
	return 0;
}