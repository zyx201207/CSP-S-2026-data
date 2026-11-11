#include <bits/stdc++.h>
using namespace std;

int findx(int x, vector<int> &arr) {
	int len = arr.size();
	for (int i = 0; i < len; i++)
		if (arr[i] == x)
			return i;
}

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	vector<int> cnt(m + 1, 0);
	vector<int> cnt1(m + 1, 0);
	vector<int> dt(n, 0);
	int dtop = 0;
	for (int g = 0; g < n; g++) {
		for (int i = g; i < n; i++) {
			if (cnt[a[i]] == 0) {
				dt[dtop] = a[i];
				dtop++;
				cnt[a[i]]++;
			} else {
				int k = findx(a[i], dt);
				dtop = k;
				for (int j = k; j < n; j++) {
					cnt[dt[j]]--;
					dt[j] = 0;
				}
				dt[dtop] = a[i];
				cnt[a[i]]++;
				dtop++;
			}
		}
		for (int i = 1; i <= m; i++) {
			if (cnt[i] != 0)
				cnt1[i]++;
		}
		for (int i = 0; i <= m; i++)
			cnt[i] = 0;
		for (int i = 0; i < n; i++)
			dt[i] = 0;
		dtop = 0;
	}
	for (int i = 1; i <= m; i++)
		cout << cnt1[i] << " ";

	return 0;
}
