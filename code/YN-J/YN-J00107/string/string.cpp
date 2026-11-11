#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	string a;
	int sl = 0;
	long long t;
	char t1;
	for (int i = 0; i < n; i++) {
		cin >> t >> t1;
		for (int j = 0; j < t; j++)
			a += t1;
	}
	int l = 0, r = a.size() - 1;
	while (l < r) {
		if (a[l] != a[r]) {
			sl++;
		}
		l++;
		r--;
	}
	cout << sl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}