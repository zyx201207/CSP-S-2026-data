#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m, ans = 0;
	cin >> n >> m;
	int num[n + 1];
	for(int i = 0; i < n; i ++) {
		cin >> num[i];
	}
	if(n == m) {
		ans = num[0];
		for(int i = 1; i < n; i ++) {
			ans = ans & num[i];
		}
		cout << ans;
		return 0;
	}
	else if(m == 1) {
		for(int i = 0; i < n; i ++) {
			if(num[i] > ans) ans = num[i];
		}
		cout << ans;
		return 0;
	}
	else if(m == 2) {
		for(int i = 0; i < n - 1; i ++) {
			for(int j = i + 1; j < n; j ++) {
				ans = max(ans, num[i] & num[j]);
			}
		}
		cout << ans;
		return 0;
	}
	else if(m == n - 1) {
		int tmp = 0;
		for(int i = 1; i < n; i ++) {
			for(int j = 1; j < n; j ++) {
				tmp = num[0];
				if(j != i) {
					tmp = tmp & num[j];
				}
			}
			ans = max(ans, tmp);
		}
		tmp = num[1];
		for(int i = 2; i < n; i ++) {
			tmp = tmp & num[i];
		}
		ans = max(ans, tmp);
		cout << ans;
		return 0;
	}
	else {
		cout << 2026;
		return 0;
	}
}




































