#include <iostream>
#include <map>
#define LL long long
using namespace std;
const int N = 2e5 + 5;

int n, ans;
LL a, sum[N];
map<LL, char> mp;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a; char c;
		cin >> a >> c;
		sum[i] += sum[i - 1] + a;
		mp[sum[i]] = c;
	}
	
	for (int i = 1, j = n; i <= j; i++, j--) {
		LL l, r;
		
		for (int k = 1; k <= n; k++) {
			if (sum [k - 1] <= i && i <= sum[k]) {
				l = sum[k];
				break;
			}
		}
		for (int k = n; k >= 1; k--) {
			if (sum[k] >= j && j >= sum[k - 1]) {
				r = sum[k];
				break;
			}
		}
		
		if (mp[l] != mp[r]) ans++;
	}
	
	cout << ans;
	
	return 0;
}
