#include <iostream>
#include <algorithm>
using namespace std;
typedef long long Int;

const Int N = 500005;
Int n, m, a[N];
Int l, r, mid, k;

bool check(Int ans) {
	k = 0;
	for (Int i = 1; i <= ans; i++) k += a[ans] - a[i];
	
	if (k <= m) return 1;
	for (Int i = ans+1; i <= n; i++) {
		if (k <= m) return 1;
		k = k - (a[i-1]-a[i-ans]) + (ans-1)*(a[i]-a[i-1]);
	}
	return 0;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for (Int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1, a+n+1);
	
	l = 1; r = n;
	while (l < r) {
		mid = (l+r+1)/2;
		if (check(mid)) l = mid;
		else r = mid-1;
	}
	
	cout << l << endl;
	
	return 0;
}

// promise not dead loop
// O(nlogn)
