#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int w[N][32];
int a[N];

int chack(int m) {
	for (int i = 20 ; i > 0; i--) {
		int temp[30] = {0};
		for (int j = 0; j < m; j++) {

			if (w[j][i] == 1) {
				temp[i]++;
			}
			if (temp) {

			}
		}

	}
	return 0;
}



int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);


	int n, m;

	cin >> n >> m;
	int t[m] = {0};
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		int temp = a[i];

		for (int j = 0; 1; j++) {
			w[i][j] = temp % 2;
			temp /= 2;
			if (!temp) {
				break;
			}
		}
	}


	cout << 0;
	return 0;
}