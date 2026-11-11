#include <iostream>
#include <algorithm>
#include <cstring>

#define int long long

using namespace std;

const int N = 5e5 + 10;

int n, m;
int nums[N];
int to[N];
int ans = -0x3f3f3f3f3f3f3f3f;

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		cin >> nums[i];
	}
	
	sort(nums + 1, nums + 1 + n);
	
//	for (int i = 1; i <= n; i ++) cout << nums[i] << endl;
	
	int sum = 0;
	for (int i = n - 1; i >= 1; i --) {
		sum += nums[n] - nums[i]; 
	}
//	cout << sum << endl;
	for (int i = n; i >= 1; i --) {
		to[i] = sum;
		sum -= (i - 1) * (nums[i] - nums[i - 1]);
	}
	
//	cout << to[313325] - to[24920] << endl;
	
//	for (int i = 1; i <= n; i ++) cout << to[i] << endl;
	for (int i = 1; i <= n; i ++) {
		int l = 1, r = i;
		while (l < r) {
			int mid = (l + r) >> 1;
			if (to[i] - to[mid] - ((nums[i] - nums[mid]) * (mid - 1)) <= m) r = mid;
			else l = mid + 1;
		}
		
//		if (i - l + 1 > ans) cout << i << ' ' << l << ' ' << to[i] << endl;
//		cout << i << ' ' << l << ' ' << i - l + 1 << endl;
		ans = max(ans, i - l + 1);
	}
	cout << ans << endl;
	
	return 0;
}
/*
the quick brown fox jumps over a lazy dog.
I will ak CSP-S 2026.
*/
