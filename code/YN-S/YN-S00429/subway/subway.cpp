#include <bits/stdc++.h>
using namespace std;
long long int w[100010];
long long int mp[1000][1000];
long long a[100010];
int vis[1000][1000];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= 2 * k; j++) {
			cin >> a[j];
		}
		for (int j = 1; j <= 2 * k; j += 2) {
			mp[i][a[j]] = a[j + 1];
		}
	}
	while (q--) {
		long long sum = 0;
		int start, end;
		cin >> start >> end;
		sum += w[start] + w[end];
		int start1, end1;
		bool flag = false;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (j == start && mp[i][j] != 0) {
					start1 = i;
				}
				if (j == end && mp[i][j] != 0) {
					end1 = i;
				}
			}
			if (start1 == end1) {
				flag = true;
			}
			if (flag)
				break;
		}
		sum += mp[start1][start] + mp[end1][end];
		if (flag) {
			cout << sum;
			continue;
		}
		if (start1 - end1 > 0 && start - end < 0) {
			int l = start1, r = start;
			while (l != end1 && r != end) {
				if (l > end1 && mp[l][r] != 0 && mp[l - 1][r] != 0) {
					sum += mp[l][r] + mp[l - 1][r];
					l--;
					continue;
				}
				r++;
			}
		} else if (start1 - end1 < 0 && start - end < 0) {
			int l = start1, r = start;
			while (l != end1 && r != end) {
				if (l < end1 && mp[l][r] != 0 && mp[l + 1][r] != 0) {
					sum += mp[l][r] + mp[l + 1][r];
					l++;
					continue;
				}
				r++;
			}
		} else if (start1 > end1 && start > end) {
			int l = start1, r = start;
			while (l != end1 && r != end) {
				if (l > end1 && mp[l][r] != 0 && mp[l - 1][r] != 0) {
					sum += mp[l][r] + mp[l - 1][r];
					l--;
					continue;
				}
				r--;
			}
		} else if (start1 < end1 && start > end) {
			int l = start1, r = start;
			while (l != end1 && r != end) {
				if (l < end1 && mp[l][r] != 0 && mp[l + 1][r] != 0) {
					sum += mp[l][r] + mp[l + 1][r];
					l++;
					continue;
				}
				r--;
			}
		}
		cout << sum << endl;
	}
	return 0;
}