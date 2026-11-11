//梁伯温 西安辅轮中学 SN-S00349
#include <bits/stdc++.h>
#define inf 0x3f3f3f3ff3f3f3fLL
using namespace std;
const int maxn = 5e5 + 5;

int n;
long long m;
int a[maxn];
int u = 0, v = 0;
bool sf = true;
long long sum;

void solve() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m;
	
	for (int j = 1; j <= n; j ++) {
		cin >> a[j];
		sum += a[j];
		if (j == 2){
			u = a[j] - a[j - 1];
		}
		if (j > 2) {
			v = a[j] - a[j - 1];
			if (v != u) sf = false;
		}
	}
	long long ave = sum / 5;
	sort(a + 1, a + 1 + n);
	
	if (sf == true) {
		for (int j = 1; j <= n; j ++) {
			long long sum = n * (n - 1) / 2 * u;
			if (sum > m) {
				cout << j - 1 << endl;
				return;
			}
			if (sum == m) {
				cout << j << endl;
				return;
			}
		}
		cout << "0" << endl;
		return;
	}
	
	
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out ", "w", stdout);
	int T = 1;
	while (T--) {
		solve();
	}
	return 0;
}
