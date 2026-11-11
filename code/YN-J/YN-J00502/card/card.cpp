#include <bits/stdc++.h>
using namespace std;
int num1[500100], num2[500100];
int sum[300100] ;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> num1[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			num2[j] = num1[j];
			int idx;
			bool flag = 0;
			for (int k = 1; k <= j; k++) {
				if (num2[k] == num2[j]) {
					idx = k;
					break;
				}
			}
			for (int k = idx + 1; k <= n; k++) {
				num2[k] = 0;
			}
			for (int k = 1; k <= n; k++) {
				int a = num2[k];
				sum[a] = sum[a] + 1;
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << sum[i] << " ";
	}
	return 0;
}
