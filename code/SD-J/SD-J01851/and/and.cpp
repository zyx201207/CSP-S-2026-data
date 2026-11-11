#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long a[N];
int main() {
	freopen ("and.in" , "r" , stdin);
	freopen ("and.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n , m;
	cin >> n >> m;
	int ans = 0;
	bool flag = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (flag = 1) {
			ans = a[i];
			flag = 0;
		}
		ans = ans & a[i];
	}
	if (n == m) {
		cout << ans << endl;
		return 0;
	}
	sort(a + 1 , a + n + 1 , greater<long long>());
	cout << a[m];
	return 0;
}
