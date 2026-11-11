#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxN = 5e5;

ll n, m;      //n为水晶总数，m为操作总次数
ll num[maxN + 5];   //能量值ai
ll ans;    //答案

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	cin >> n >> m;

	if (n == 1) {
		cout << 1;
		return 0;
	}

	for (ll i = 1; i <= n; i++) { //输入水晶能
		cin >> num[i];
	}

	sort(num + 1, num + 1 + n);

	int st = 0;

	for (ll i = 2; i <= n; i++) { //遍历，让num 1 到 2~n 的水晶相等
		ll nm = m;

		for (ll j = 1; j <= i; j++) {
			ll cnt = num[i] - num[j];
			nm -= cnt;

			if (nm < 0) {
				st = 1;
				break;
			}
		}

		if (st == 1) {
			ans = i - 1;
			break;
		}

		for (int j = i; j <= i; j++) {
			if (num[j] == num[i]) {
				ans = j;
				i  = j;
			} else {
				break;
			}
		}
	}

	cout << ans;

	return 0;
}