#include<bits/stdc++.h>
#define int long long
const int N = 5e5 + 5;
using namespace std;
int n, m, a[N], flag, ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (i > 2 && a[i] - a[i - 1] != a[i - 1] - a[i - 2]) {
			flag = 1;
		}
	}
	if (!flag) {
		int x = a[2] - a[1];
		int p = x, p1 = x, cnt = 1;
		while ((p + p1) * cnt / 2 <= m) {
			p1 += x;
			cnt++;
		}
		cout << cnt;
		return 0;
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		int sum = 0, cnt = 1;
		for (int j = i - 1; j >= 1; j--) {
			if (sum + a[i] - a[j] > m) {
				break;
			}
			sum += a[i] - a[j];
			cnt++;
		}
		ans = max(ans, cnt);
	}
	cout << ans;
	return 0;
}

