#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
long long a[N];

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m, sum = 0, ans = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if(n<1e9) sort(a + 1, a + n + 1);
	for (int i = 1; i < n; i++) {
		sum = sum  + (a[i + 1] - a[i]) * i;
		if (sum > m) {
			ans = i;
			break;
		}
	}
	if (ans == 0)
		ans = n;
	cout << ans;
	return 0;
}
