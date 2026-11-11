#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long  n, a, sum = 0;
	string q;
	char b;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a >> b;

		for (int j = 0; j < a; j++) {
			q += b;
		}
	}
	for (int i = 0; i < q.size() / 2; i++) {
		int left = 0, right = q.size() - 1;
		if (q[left] != q[right])
			sum++;
		left++;
		right--;
	}
	cout << sum;
	return 0;
}
