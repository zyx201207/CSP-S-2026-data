#include <bits/stdc++.h>
using namespace std;
long long a[500005];
long long dist[500005];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	long long n, m;
	cin >> n >> m;
	long long cnt1 = 0;
	long long dengcha = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == i)
			cnt1++;
	}
	long long cha = a[2] - a[1];
	for (int i = 2; i < n; i++) {
		if (a[i + 1] - a[i] == cha) {
			dengcha++;
		}
	}
	if (cnt1 == n) {
		long long nmax = a[n];
		for (int i = 1; i < n; i++) {
			dist[i] = nmax - i;
		}
		long long cnt = 0;
		long long sum = 0;
		for (int i = n - 1; i >= 1; i--) {
			sum = sum + dist[i];
			cnt++;
			if (sum > m) {
				cnt--;
				break;
			}
		}
		cout << cnt;
		return 0;
	} else if (dengcha == (n - 2)) {
		memset(dist, 0, sizeof(dist));
		long long newcha = a[n] - a[n - 1];
		long long cnt = 0;
		long long sum = 0;
		for (int i = 1; i <= n; i++) {
			cnt++;
			if ((newcha + newcha * i)*i / 2 > m) {
				cnt--;
				break;
			}
		}
		cout << cnt << endl;
		return 0;
	}
	sort(a + 1, a + n + 1);
	long long cnt = LLONG_MIN;
	for (int tar = 2; tar <= n; tar++) {
		long long nowcnt = 0;
		long long sum = 0;
		for (int j = tar - 1; j >= 1; j--) {
			sum = sum + a[tar] - a[j];
			nowcnt++;
			if (sum > m) {
				nowcnt--;
				cnt = max(cnt, nowcnt);
				break;
			}
		}
		cnt = max(cnt, nowcnt);
	}
	cout << cnt + 1;
	return 0;
}
