#include <bits/stdc++.h>
using namespace std;
string A;

bool h(string x, int y, int z) { //x是数组 y是长度 z是长度的一半
	int zhi = 1;
	for (int i = 0; i < y; i++) {
		if (i == z + 1) {
			break;
		}
		if (x[i] == x[y - i]) {
			continue;
		} else {
			zhi = 0;
			break;
		}
	}
	return zhi;
}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long int n, a, id = 0, idx = 0;
	char c, idc;
	cin >> n;
	while (n--) {
		cin >> a >> c;
		for (int i = 1; i <= a; i++) {
			A[id] = c;
			id++;
		}
		if (n > idx) {
			idx = n;
			idc = c;
		}
	}
	long long int sum = A.size();
	long long int ans;
	long long int summ = 0;
	if (sum % 2 == 0) {
		ans = sum / 2;
	} else {
		ans = sum / 2 + 1;
	}
	while (0 != 1) {
		int step = h(A, sum, ans);
		if (step == 1) {
			break;
		}
	}
	cout << summ;
	return 0;
}