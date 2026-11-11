#include <bits/stdc++.h>
using namespace std;
int n, ans;
vector<char> vec;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	while (n--) {
		int k;
		char c;
		cin >> k >> c;
		while (k--) {
			vec.push_back(c);
		}
	}

	vector<char>a, b;
	for (auto &x : vec) {
		a.push_back(x);
	}
	cout << '\n';
	for (int i = vec.size() - 1; i >= 0 ; --i) {
		b.push_back(vec[i]);
	}
	cout << '\n';

	for (int i = 0 ; i <= vec.size() - 1 ; ++i) {
		if (a[i] != b[i]) {
			b[i] = a[i];
			ans++;
		} else {
			break;
		}

	}
	cout << ans;
	return 0;
}
