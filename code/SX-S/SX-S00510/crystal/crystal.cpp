#include <bits/stdc++.h>
using namespace std;


int main() {
	freopen("crystal.in", r, stdin);
	freopen("crystal.out", w, stdout);
	int n;
	long long m;
	vector<int> a;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int b;
		cin >> b;
		a.push_back(b);
	}
	sort(a.begin(), a.end());
	int i = n / 2;
	int l = i - 1, r = i + 1;
	long long used = 0;
	while (true) {
		if (a[i] - a[l] <= a[r] - a[i] && l >= 0) {
			if (used + a[i] - a[l] > m)
				break;
			used += a[i] - a[l];
			--l;
		} else if (a[i] - a[l] >= a[r] - a[i] && r < n) {
			if (used + a[r] - a[i] > m)
				break;
			used += a[r] - a[i];
			++r;
		} else
			break;
	}
	cout  << r - l - 1;
	return 0;
}
