#include <bits/stdc++.h>
using namespace std;

struct shu {
	long long n;
	long long cha;
	int m;
};
shu a[5000005];

bool cmp(shu a, shu b) {
	return a.n < b.n;
}

int main() {
	long long sum = 0, ans = 0, dump = 0;
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].n;

	}
	sort(a + 1, a + n + 1, cmp);
	cout << a[1].n << endl << a[n].n << endl;
	for (int i = 1; i <= n; i++) {
		a[i].cha = a[i].n - a[i - 1].n;
		dump = 0;
		sum = 0;
		for (int j = i - 1; j > 0; j--) {
			sum += a[j + 1].cha;
			if (sum <= m)
				dump++;
			else
				break;
		}
		ans = max(ans, dump + 1);
	}
	cout << ans;
	return 0;
}