/*

七宝中学厕所好tm臭 

*/

#include <iostream>
#include <algorithm> 

using namespace std;
using ll = long long;

const int N = 5e5 + 10;

int n, ans;
ll m, a[N], s[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + a[i];	
		int l = 1, r = i, res = 0;
		while (l <= r) {
			int mid = l + r >> 1;
			if ((i - mid) * a[i] - (s[i - 1] - s[mid - 1]) <= m)
				res = mid, r = mid - 1;
			else l = mid + 1;
		}
		ans = max(ans, i - res + 1);
	}
	cout << ans << "\n";
	return 0;
} 
