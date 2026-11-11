#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;
int n, m, a[N];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	vector<int>res;
	for (int i = 1; i <= n; i++) {
		vector<int>desktop;
		for (int j = i; j <= n; j++) {
			auto it = find(desktop.begin(), desktop.end(), a[j]);
			if (it != desktop.end())
				desktop.erase(it, desktop.end());
			desktop.push_back(a[j]);
		}
		for (int t : desktop)
			res.push_back(t);
	}
	for (int i = 1; i <= m; i++)
		cout << count(res.begin(), res.end(), i) << ' ';
	return 0;
}