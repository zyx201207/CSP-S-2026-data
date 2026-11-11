#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int a[N], t[N];
int m, n;
int mid = 0, lack_pre[N], k = 1, lack_la[N], ti;
int sum1 = 0, sum2 = 0, sum = 0;
int pre = 0, la = 0;
int ans = 0;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		if (a[i] == a[i + 1])
			t[a[i]]++;
	}
	mid = n / 2;
	if (mid % n != 0)
		mid += 1;
	for (int i = 1; i <= n; i++)
		lack_pre[i] = 0, lack_la[i] = 0;
	for (int i = 1; i <= mid; i++) {
		lack_pre[i] += abs(a[mid] - a[mid - k]);
		lack_la[i] += abs(a[mid] - a[mid + k]);
		sum1 += lack_pre[i];
		sum2 += lack_la[i];
		k++;
		if (k >= mid)
			break;
	}
	for (int i = 1; i <= n; i++) {
		ti = max(ti, t[i + 1]);
	}

	for (int i = 1; i <= k; i++) {
		if (m >= sum1 + sum2) {
			pre = n;
			break;
		}
		if (m == sum1) {
			pre += k;
			break;
		} else if (m < sum1 && m >= lack_pre[i]) {
			pre++;
			m -= lack_pre[i];
		} else if (m > sum1) {
			sum = m - sum1;
			if (sum > lack_la[i]) {
				pre += k;
				pre++;
				sum -= lack_la[i];
			}
		}
		if (m == sum2) {
			la += k;
			break;
		} else if (m < sum2 && m >= lack_la[i]) {
			la++;
		} else if (m > sum1) {
			sum = m - sum1;
			if (sum > lack_pre[i]) {
				pre += k;
				pre++;
				sum -= lack_pre[i];
			}
		}
	}
	ans = max(pre, la) + ti;
	cout << ans << endl;
	return 0;
}
