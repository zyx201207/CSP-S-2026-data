#include <bits/stdc++.h>
using namespace std;
int at[200005], as[5];
int f = 0, f2 = 1;
int mini = INT_MAX;
int n, m;
int maxa = 0;
int lg[25];

void bfs(int cnt, int wz, int sumt) {
	if (cnt == m) {
		maxa = max(maxa, sumt);
		return;
	}
	if (wz > 20) {
		return;
	}
	bfs(cnt + 1, wz + 1, sumt & at[wz]);
	bfs(cnt, wz + 1, sumt);
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	if (m == 1) {
		int sum = 0;
		int a;
		for (int i = 0; i < n; i++) {
			cin >> a;
			sum = max(sum, a);
		}
		cout << sum;
	} else if (m == n) {
		int sum;
		cin >> sum;
		int a;
		for (int i = 1; i < n; i++) {
			cin >> a;
			sum = (sum & a);
		}
		cout << sum;
	} else {
		for (int i = 0; i < n; i++) {
			cin >> at[i];
			if (at[i] > 4) {
				f2 = 0;
				as[at[i]]++;
				if (as[4] >= m) {
					cout << 4;
				} else if (as[3] >= m) {
					cout << 3;
				} else if (as[3] + as[2] >= m) {
					cout << 2;
				} else if (as[1] >= m) {
					cout << 1;
				} else {
					cout << 0;
				}
			}
			int r = 1;
			int c = at[i] & (at[i] + 1);
			if (f != 0 || c != 0) {
				f = 1;
			}
		}
		if (f == 0) {
			sort(at, at + n);
			cout << at[n - m];
		} else if (f2 != 0) {

		} else if (n <= 20) {
			bfs(0, 0, 2097151);
			cout << maxa;
		} else if (m == 2) {
			for (int i = 0; i < n; i++) {
				for (int j = i + 1; j < n; j++) {
					maxa = max(maxa, at[i] & at[j]);
				}
			}
			cout << maxa;
		} else {
			cout << 0;
		}

	}
	return 0;
}
