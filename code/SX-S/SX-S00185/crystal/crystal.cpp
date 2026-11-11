#include <bits/stdc++.h>
using namespace std;
long long a[500005];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
//难道又要蒟蒻了吗......
	long long sum = 0,  ans = 0, anss = 0;
	long long n, m;
	long long mm = m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	long long maxx = a[n], minx = a[1];
	for (int i = minx; i <= maxx; i++) {
		mm = m;
		ans = 0;
		for (int j = n; j >= 1; j--) {
			long long cha = i - a[j];
			if (a[j] <= i && mm >= cha) {
				mm -= cha;
				ans++;
			}
		}
		anss = max(anss, ans);
	}
	cout << anss;
	return 0;
}
