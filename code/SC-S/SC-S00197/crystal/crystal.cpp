#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long n, m;
	long a[500001];
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	long sum = 0;
	for(long i = 2; i <= n; i++) {
		sum += (a[i] - a[i - 1]) * (i - 1);
		if (sum > m){
			cout << i - 1;
			break;
		}
		//cout << sum;
	}
	return 0;
}