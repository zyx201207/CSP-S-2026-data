#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;

long long n, m, sum, cnt, ans, tmp, a[N];

bool flag = true;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0); 
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		if (i == 2) {
			tmp = a[i] - a[i - 1];
		}
		if (i >= 3 && a[i] - a[i - 1] != tmp) {
			flag = false;
		}
	}
	if (flag == true) {
		for (int i = n - 1; i >= 1; i--) {
			if (sum + (a[n] - a[i]) <= m) {
				sum += (a[n] - a[i]), cnt++;
				ans = max(ans, cnt);
			} else {
				break;
			}
		}
		cout << ans;
		return 0;
	}
	for (int i = n; i >= 1; i--) {
		sum = 0, cnt = 1;
		for (int j = i - 1; j >= 1; j--) {
			if (sum + (a[i] - a[j]) <= m) {
				sum += (a[i] - a[j]), cnt++;
				ans = max(ans, cnt);
			} else {
				break;
			}
		}
	}
	cout << ans;
	return 0;
} 
