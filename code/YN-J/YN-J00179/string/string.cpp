#include <bits/stdc++.h>
using namespace std;
char a[100005];

int main() {
	freopen("string3.in", "r", stdin);
	freopen("string3.out", "w", stdout);

	int n, v, sum = 1, num = 0;
	char x;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> v;
		cin >> x;
		for (int j = sum; j <= sum - 1 + v; j++) {
			a[j] += x;
		}
		sum += v;
	}
	sum -= 2;
	for (int i = 1; i <= sum / 2; i++) {
		if (a[i] != a[sum - i + 1]) {
			num += 1;
		}
	}
	cout << num;
	return 0;
}