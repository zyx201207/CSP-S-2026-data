#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

int s[300505], a[500005];
int sum[300505];

int main() {
	freopen("card.in", "w", stdin);
	freopen("card.out", "r", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	bool flag = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	for (int i = 1; i <= n; i++) {
		int size = 0, size1 = 0;
		for (int j = i; j <= n; j++) {
			size1 = size;
			for (int k = 1; k <= size1; k++) {
				if (flag)
					s[k] = 0;
				if (s[k] == a[j]) {
					flag = 1;
					size = k;
				}

			}
			if (!flag) {
				s[size1 + 1] = a[j];
				size += 1;
			}
			flag = 0;

		}

		for (int j = 1; j <= size; j++) {
			sum[s[j]]++;
			s[j] = 0;
		}
	}
	for (int i = 1; i <= m; i++)
		cout << sum[i] << " ";
	return 0;
}