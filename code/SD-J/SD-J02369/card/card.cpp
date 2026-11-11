#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
const int N = 5e5 + 3;
int n, m, a[N], sum[N];
bool f[N];
vector<int> vec;

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	bool ff = true;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i - 1] > a[i]) ff = false;
	}
	if (ff) {
		for (int i = 1; i <= n; i++) sum[a[i]] = sum[a[i - 1]] + 1;
		goto qu;
	}
	for (int i = 1; i <= n; i++) {
		vec.clear();
		for (int j = 1; j <= m; j++) f[j] = false;
		for (int j = i; j <= n; j++) {
			if (f[a[j]] == false) {
				f[a[j]] = true;
			} else {
				f[a[j]] = false;
				while (vec.back() != a[j]) {
					f[vec.back()] = false;
					vec.pop_back();
				}
				vec.pop_back();
			}
			vec.push_back(a[j]);
			f[a[j]] = true;
		}
		for (int l = 0; l < (int)(vec.size()); l++) sum[vec[l]]++;
	}
	qu : ;
	for (int i = 1; i <= m; i++) cout << sum[i] << " ";
	
	return 0;
}
