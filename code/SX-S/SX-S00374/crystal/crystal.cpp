#include <bits/stdc++.h>
using namespace std;
int n;
long long m, a[500005];
long long tot[500005];
int sum = 1, leave = 1;
int maxx = -1;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 2; i <= n; i++) {
		tot[i] = tot[i - 1] + (a[i] - a[i - 1]) * (i - 1);
		//cout << tot[i] << " ";
		if (tot[i] <= m) {
			sum++;
			maxx = max(maxx, sum);
		} else {
			maxx = max(maxx, sum);
			sum = 1;
			tot[i] = 0;
		}
	}
	//cout << endl;
	cout << maxx;
	return 0;
}