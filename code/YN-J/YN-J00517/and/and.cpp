#include <bits/stdc++.h>
using namespace std;

//pow(2,31)=21...
int n, m;
int a[200005][3];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i][1];
		a[i][2] = a[i][1];
	}
	int mn = 0; //结果的最小值
	for (int j = 30; j >= 0; j--) {
		int sum = 0; //数量
		for (int i = 1; i <= n; i++) {
			if (a[i][1] >= pow(2, j) && a[i][2] > mn) {
				a[i][1] -= pow(2, j);
				sum++;
			}
		}
		if (sum >= m) {
			mn += pow(2, j);
		}
	}
	cout << mn;
	return 0;
}