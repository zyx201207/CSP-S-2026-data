#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long int n, m, a[N], sum, i;
int main () {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	for (i = 1; i < n; i ++) {
		sum += i;
	}
	if (m == 0) {
		cout << 1;
		return 0;
	}
	if (m >= sum) {
		cout << n;
		return 0;
	}
	i = n - 1;
	while (i != 0) {
		if (m >= sum - i) {
			cout << i;
			return 0;
		}
		i --;
	}
	return 0;
}
