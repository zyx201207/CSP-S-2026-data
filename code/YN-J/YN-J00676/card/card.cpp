#include <iostream>
using namespace std;
int a[100005];

int m [3] = {1, 2, 3};

int main() {
	freopen("card.in", "r", stdin)
	freopen("card.out", "w", stdout)
	int n, sum = 0, k;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		if (k != a[i + 1]) {
			k = a[i + 2];
		}
		if (a[i] = m[3]) {
			sum++;
			if (a[i] == a[i + 1]) {
				sum++;
			}

		}
	}
	cout << sum;
}