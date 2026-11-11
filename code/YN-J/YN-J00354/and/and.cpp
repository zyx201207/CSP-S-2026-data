#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("and5.in", "r", stdin);
	freopen("and5.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<int> a(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int total = a[a.size() - m];
	for (int i = a.size() - m + 1; i < a.size(); i++) {
		cout << total << endl;
		cout << a[i] << endl;
		total &= a[i];
	}
	cout << total << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}