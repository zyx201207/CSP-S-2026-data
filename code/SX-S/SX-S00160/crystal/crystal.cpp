#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 10;
int a[N], b[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m, mx = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			if (a[i] >= a[j])
				b[j] = a[i] - a[j];
			else
				b[j] = N;
		}
		sort(b + 1, b + n + 1);
		int sum = 0, mm = m;
		for (int j = 1; j <= n; j ++) {
			if (mm - b[j] >= 0) {
				mm -= b[j];
				sum ++;
			} else
				break;
		}
		if (sum > mx)
			mx = sum;
		if (mx == n)
			break;
	}
	cout << mx;
	fclose(stdin);
	fclose(stdout);

	return 0;
}
