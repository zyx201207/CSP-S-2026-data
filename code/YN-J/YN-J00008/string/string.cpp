#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pir;
const int maxn = 5e5 + 10;

struct node {
	ll len;
	char c;
} a[maxn];

void solve() {
	int n;
	cin >> n;
	ll sum_len = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].len >> a[i].c;
		sum_len += a[i].len;
	}
	/*
	总体思路：
	将整个数组拆成两个部分，使用双指针，两个塔往上枚举
	*/
	if (sum_len & 1) {
		ll now_len = 0;
		for (int i = 1; i <= n; i++) {
			if (now_len + a[i].len > sum_len / 2) {
				a[i].len--;
				sum_len--;
				break;
			} else {
				now_len += a[i].len;
			}
		}
	}

	ll ans = 0;



	int l = 1, r = n;
	while (l <= r) {
		if (l != r) {
			if (a[l].len == a[r].len) {
				ans += (a[l].c == a[r].c ? 0 : a[l].len);
				l++, r--;
			} else if (a[l].len < a[r].len) {
				ans += (a[l].c == a[r].c ? 0 : a[l].len);
				a[r].len -= a[l++].len;
			} else {
				ans += (a[l].c == a[r].c ? 0 : a[r].len);
				a[l].len -= a[r--].len;
			}
		} else {
			break;
		}
	}

	cout << ans << '\n';

}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	solve();
	return 0;
}