#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int long long m, n;
	cin >> n >> m;
	vector<int long long> a(n);
	vector<int long long> s(n);
	for (int k = 0; k < n; k++) {
		cin >> a[n];
	}
	for (int i = 0; i < n; i++) {
		s[i] = a[i + 1] and a[i];
	}
	int j = max(s[int i]);
	cout << j;
	return 0;
}