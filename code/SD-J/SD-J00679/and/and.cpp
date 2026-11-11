#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int n, m;
int a[N];
int s[40];
int t[40];
bool vis[N];
int ans;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin >> n >> m;
	t[0] = 1;
	for (int i = 1; i < 30; ++i) {
		t[i] = t[i - 1] * 2;
	}
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		for (int j = 0; j < 30; ++j) {
			if (a[i] & t[j]) {
				s[j]++;
			}
		}
	}
	for (int i = 30 - 1; i >= 0; --i) {
		if (s[i] >= m) {
			ans += t[i];
			for (int j = 1; j <= n; ++j) {
				if (vis[j]) {
					continue;
				}
				if (!(a[j] & t[i])) {
					vis[j] = 1;
					for (int k = 0; k < 30; ++k) {
						if (a[j] & t[k]) {
							s[k]--;
						}
					}
				}
			}
		}
	}
	cout << ans << "\n";
	
	return 0;
}
