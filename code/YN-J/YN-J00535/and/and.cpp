#include <bits/stdc++.h>
using namespace std;

int and_s(int a, int b) {
	if (a > b)
		return b;
	if (a <= b)
		return a;
}

int main() {

	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int list_i[200001] = {};
	int lenth = 0;
	for (int i = 1; i <= n; i++) {
		cin >> list_i[i];
		lenth++;
	}
	int max_and = 0;
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (max_and < (and_s(list_i[i], list_i[j]))) {
				max_and = (and_s(list_i[i], list_i[j]));
			}
		}
	}
	cout << max_and;

	return 0;
}