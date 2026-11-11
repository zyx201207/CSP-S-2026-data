#include<bits/stdc++.h>
using namespace std;
const int N = 2E6;
long long int n, m, a[N], sum, k = 1, maxn = -1;
int main () {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	sort (a + 1, a + 1 + n, greater<int>());
	if (m == 1) {
		cout << a[1];
		return 0;
	}
	sum = a[1];
	for (int i = 2; i <= n; i ++) {
		k ++;
		if (k <= m) {
			sum = a[i] & sum;
		}
		else {
			if (maxn < sum) {
				maxn = sum;
				sum = a[i - 1];
				i += 1;
				k = 1;
			}
		}
	}
	cout << maxn;
	return 0;
}
