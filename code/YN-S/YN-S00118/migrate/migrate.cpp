#include <bits/stdc++.h>
using namespace std;
long long x[2000010];
long long sum[2000010];
long long fp[2000010];
int lm[2000010];
int km[2000010];
int c, t, n;
long long d;
long long ans;


int finding(int i) {
	if (sum[i + 1] - sum[i] > d)
		return i;
	int num = 0;
	int l = i, r = n - 1;
	while (l <= r) {
		//cout << "l=" << l << "   r=" << r << '\n';
		int mid = (l + r) / 2;
		//cout << "mid=" << mid << '\n';
		if (sum[mid] - sum[i] > d) {
			r = mid - 1;
			//cout << "no" << "\n";
		} else {
			num = mid;
			l = mid + 1;
			//cout << "yes" << "\n";
		}
	}
	if (!num)
		return n - 1;
	else
		return num;
}

int sm(int x, int y) {
	int m = 0;
	int p = x;
	while (p < y) {
		//cout << p;
		if (p != fp[p]) {
			lm[m] = fp[p] - p;
			p = fp[p];
			km[m] = p;
		} else
			return -1;
		m++;
	}
	return m;
}

int main() {
	//freopen("migrate.in", "r", stdin);
	//freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 0; i < n; i++) {
			cin >> x[i];
			sum[i] = x[i] - x[0];
			//cout << sum[i] << ' ';
		}
		//cout << '\n';
		for (int i = 0; i < n; i++) {
			int res = 0;
			fp[i] = finding(i);
			//cout << fp[i] << " ";
		}
		for (int i = 0; i < n; i++) {
			for (int j = i + 3; j < n; j++) {
				int m = sm(i, j);
				//cout << m << " ";
				/*for (int k = 0; k < m; k++) {
					cout << km[k] << " ";
				}*/
				if (m == -1)
					break;
				if (j == i + 3) {
					if (lm[0] == 1)
						continue;
					if (fp[i + 1] == fp[j])
						ans++;
				}
			}
			//cout << '\n';
		}
	}
	cout << ans;
}