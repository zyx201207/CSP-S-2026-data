#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen ("string.in", "w", stdin);
	freopen ("string.out", "r", stdout);
	int n;
	cin >> n;
	vector<string>a;
	while (n--) {
		long long l;
		string c;
		cin >> l;
		cin >> c;
		for (int i = 0; i < l; i++)
			a.push_back(c);
	}
	vector<string>b;
	long long ans = 0;
	for (int i = 0; i < a.size(); i++) {
		b.push_back(a[i]);
	}
	long long j = b.size() - 1;
	for (int i = 0; i < a.size(); i++) {
		if (b[j] != a[i])
			ans++;
		j--;
	}
	cout << ans / 2;
	return 0;
}