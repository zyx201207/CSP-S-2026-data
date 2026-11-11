#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pir;
const int maxn = 2e6 + 5;
ll a[maxn];
ll n, m;

void solve() {
	cin >> n >> m;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
	}
	/*
	考虑数位贪心策略：
	从高位往底位贪心
	在从高位往底位枚举的时候，只要遇到当前的1的数量>=m，那么答案从这些当中产生
	复杂度：O(N)
	*/
	vector<int>flag(n + 1, true);
	for (int j = 30; j >= 0; j--) {
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (flag[i] && (a[i] & (1 << j))) {
				cnt ++;
			}
		}
		if (cnt >= m) {
			for (int i = 1; i <= n; i++) {
				if (!(a[i] & (1 << j))) {
					flag[i] = 0;
				}
			}
		}
	}

	int k = 1;

	for (int i = 1; i <= n; i++) {
		if (flag[i]) {
			k = a[i];
			break;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (flag[i])
			k &= a[i];
	}
	cout << k << '\n';
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	solve();
	return 0;
}