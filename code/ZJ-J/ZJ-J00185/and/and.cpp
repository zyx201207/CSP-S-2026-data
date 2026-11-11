#include <iostream>
#include <climits>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
ll n, m;
int a[N];
int ans = 0;
bool vis[N];
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 30; i >= 0; i--) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (vis[j]) continue;
			if (a[j] & (1 << i)) cnt++;
		}
		if(cnt < m) continue;
		ans |= (1 << i);
		for(int j = 1; j <= n; j++) {
			if (vis[j]) continue;
			if (a[j] & (1 << i)) continue;
			vis[j] = 1;
		}
	}
	cout << ans;
	return 0;
}


