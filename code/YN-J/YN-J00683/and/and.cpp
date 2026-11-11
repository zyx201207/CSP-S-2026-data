#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m, a[N], book[N];
vector<int>e[35];
int res, sum;
vector<int>num;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1, t; i <= n; i++) {
		cin >> t;
		a[i] = t;
		for (int j = 0; t; j++, t /= 2) {
			if (t & 1)
				e[j].push_back(i);
		}
//		num.push_back(i);
		book[i] = 1;
	}
	for (int i = 30; i >= 0; i--) {
//		cout << i << '\n';
		vector<int>ne;
		for (auto j : e[i]) {
//			cout << j << ' ';
			if (book[j] == 0)
				continue;
			ne.push_back(j);
		}
//		cout << '\n';
		if (ne.size() < m) {
			continue;
		}
		res += (1 << i);
		for (int j = 1; j <= n; j++)
			book[j] = 0;
		for (auto j : ne) {
//			cout << j << ' ';
			book[j] = 1;
		}
//		cout << endl;
//		swap(ne, num);
	}
	cout << res;
	return 0;
}