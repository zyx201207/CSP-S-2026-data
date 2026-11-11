/*
一个无序数组
进行m次加一操作，m可为0
求最多众数时众数个数
m与a[i]数据开long long
*/

#include <bits/stdc++.h>
using namespace std;
//#define int long long

int n;
long long m;
long long p;
long long a[500010];
long long b[500010];
int cnt[500010], ans;
int l;
//priority_queue<long long, vector<long long>, greater<long long>> pq;

int main() {

	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
//		pq.push(p);
	}
	if (n == 1) {
		cout << 1;
		return 0;
	}
	sort(a + 1, a + n + 1);
//	while (!pq.empty()) {
//		cout << pq.top() << " ";
//		pq.pop();
//	}
	l = 1;
	for (int r = 2; r <= n ; r++) {
		b[r - 1] = a[r] - a[r - 1]; // b[i-1]为a[i]与a[i-1]之差 i为：i与i-1的差（攀升）
		m -= (r - l) * b[r - 1];
		if (m >= 0) {
			cnt[r] = r - l + 1;
		} else {
			while (m < 0) {
				m += (a[r] - a[l]);
				l++;
				cnt[r]--;
			}
		}
		ans = max(ans, cnt[r]);
	}
	cout << ans;

	return 0;
}
