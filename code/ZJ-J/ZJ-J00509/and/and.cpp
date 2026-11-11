#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
int n, m, a[200005], ans, vis[200005];

void dfs(int cur, int cnt) {
	if (cur > n || cnt == m) {
		if (cnt != m) return;
		int t = (1 << 30) - 1;
		bool flag = false;
		for (int i = 1; i <= n; i++) {
			if (vis[i]) {
				t &= a[i];
				flag = true;
			}
		}
		if (flag) ans = max(ans, t);
		return;
	}
	
	vis[cur] = true;
	dfs(cur + 1, cnt + 1);
	
	vis[cur] = false;
	dfs(cur + 1, cnt);
}

bool spj1() {
	for (int i = 1; i <= n; i++) {
		if (a[i] != i - 1) return false;
	}
	return true;
}

bool spj2() {
	for (int i = 1; i <= n; i++) {
		int cur = a[i];
		while (cur) {
			if (cur % 2 != 1) return false;
			cur /= 2;
		}
	}
	return true;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	if (m == 1) {
		int mx = 0;
		for (int i = 1; i <= n; i++) {
			mx = max(mx, a[i]);
		}
		cout << mx << '\n';
		return 0;
	} else if (m == 2) {
		int mx = 0;
		for (int i = 1; i < n; i++) {
			for (int j = i + 1; j <= n; j++) {
				mx = max(mx, (a[i] & a[j]));
			}
		}
		cout << mx << '\n';
		return 0;
	} else if (m == n) {
		int mx = a[1];
		for (int i = 2; i <= n; i++) {
			mx &= a[i];
		}
		cout << mx << '\n';
		return 0;
	} else if (spj1()){
		int t = a[n];
		
		cout << t << '\n';
	} else if (n <= 20) {
		dfs(0, -1);
		cout << ans << '\n';
	} else if (spj2()) {
		sort(a + 1, a + n + 1);
		int t = a[n];
		for (int i = 1; i < m; i++) {
			t &= a[n - i];
		}
		cout << t << '\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}