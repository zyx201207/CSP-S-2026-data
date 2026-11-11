#include <bits/stdc++.h>
using namespace std;
int n,m;
const int N = 2e5 + 5;
int a[N];
int s[N][40];
int len[N];
bool cmp(int x,int y) {
	return x > y;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n == m) {
		int ans = a[1];
		for (int i = 2; i <= n; i++) {
			ans &= a[i];
		}
		cout << ans << '\n';
	}
	else if (m == 2) {
		int ans = 0;
		for (int i = 2; i <= n; i++) {
			int sum = a[i];
			for (int j = 2; j <= n && j != i; j++) {
				sum &= a[j];
				ans = max(ans,sum);
			}
		}
		cout << ans << '\n';
	}
	else if (m == 1) {
		sort(a + 1, a + n + 1);
		cout << a[n] << '\n';
	}
	else {
		int ans[40] = {0};
		sort(a + 1, a + n + 1, cmp);
		for (int i = 1; i <= n; i++) {
			vector<int> t;
			int x = a[i];
			while (x != 0) {
				int y = x % 2;
				x /= 2;
				t.push_back(y);
				len[i]++;
			}
			for (int j = 0; j < t.size(); j++) {
				s[i][t.size() - j - 1] = t[j];
			}
		}
		int l = 0;
		for (int i = 1; i <= n; i++) {
			l = max(l,len[i]);
		}
	//	cout << l << '\n';
		for (int i = l - 1; i >= 0; i--) {
			int b[N] = {0};
			for (int j = 1; j <= n; j++) {
				b[j] = s[j][i];
			}
			sort(b + 1, b + n + 1, cmp);
			for (int j = 1; j <= m; j++) {
				if (b[j] != 1) {
					ans[l-i+1] = 0;
					break;
				}
				if (b[j] == 1) {
					continue;
				}
			}
			ans[l-i+1] = 1;
		}
		int k = 0;
		int zui = 0;
		for (int i = l - 1; i >= 0; i--) {
			cout << ans[i];
		}
	//	cout << zui << '\n';
	}
	return 0;
}

