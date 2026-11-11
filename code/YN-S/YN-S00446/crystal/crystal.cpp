#include <bits/stdc++.h>
#define int long long
using namespace std;
const int M = 1e6;
int arr[M], temp[M];
bool flag = 1, pos = 1;

bool cmp(int a, int b) {
	return a > b;
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	int cha = 0;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		if (flag == 1) {
			if (arr[i] != i) {
				flag = 0;
			}
		}
		if (i >= 2) {
			cha = arr[2] - arr[1];
			if (pos == 1) {
				if (arr[i] - arr[i - 1] != cha) {
					pos = 0;
				}
			}
		}
	}
	if (flag == 1) {
		int temp = 8 * m + 1;
		cout << (-1 + signed(sqrt(temp))) / 2 + 1;
	} else if (pos == 1) {
		int f = cha * cha;
		int ac = 8 * cha * m;
		int deta = f + ac;
		int num = 2 * cha;
		cout << (signed(sqrt(deta)) - cha) / num + 1;
	} else {
		int p = 1, cnt = 0, op = m, maxn = INT_MIN;
		if (n <= 500) {
			sort(arr + 1, arr + n + 1, cmp);
			for (int i = 1; i <= n; i++) {
				for (int j = i + 1; j <= n; j++) {
					temp[p] = (arr[i] - arr[j]);
					p++;
				}
//				for (int i = 1; i <= p; i++) {
//					cout << temp[i] << " ";
//
//				}
//				cout << "\n";

				for (int i = 1; i <= p; i++) {
					if (op - temp[i] < 0) {
						break;
					}
					op -= temp[i];
//					cout << op << " ";
					cnt++;
				}
				maxn = max(maxn, cnt + 1);
//				cout << cnt << "\n";
				p = 1, op = m, cnt = 0;
			}
			cout << maxn;
		}
	}
	return 0;
}
/*

5 8
-3 -1 2 2 7

5 5
2 4 6 8 10

8 9
3 6 9 12 15 18 21 24

4 16
4 8 12 16

8 9
1 2 3 4 5 6 7 8

6 6
-3 -1 100 101 102 103

5 8
-3 -1 2 2 7
*/