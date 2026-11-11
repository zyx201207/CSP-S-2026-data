#include <bits/stdc++.h>
#define int long long
using namespace std;
const int M = 2e5 + 5;
int sum[M];

struct Node {
	string name;
	int num;
} a[M];

struct Nod {
	string name;
	int num;
} arr[M];


signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	if (n == 1) {
		for (int i = 1; i <= n; i++)
			cin >> a[i].num >> a[i].name;
		cout << 0;
		return 0;
	} else if (n == 2) {
		for (int i = 1; i <= n; i++)
			cin >> a[i].num >> a[i].name;
		if (a[1].name != a[2].name) {
			cout << min(a[1].num, a[2].num);
		} else {
			cout << 0;
		}
		return 0;
	}
	int m = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].num >> a[i].name;
		sum[i] = sum[i - 1] + a[i].num;
		if (i >= 2) {
			if (a[i].name == a[i - 1].name) {
				a[i].num += a[i - 1].num;
				a[i - 1].num = 0;
			}
		}

	}
	for (int i = 1; i <= n; i++) {

		if (a[i].num != 0) {
			m++;
			arr[m].num = a[i].num;
			arr[m].name = a[i].name;
		}

	}



	int ans = sum[n];
	int l = 1, r = m;
	int cnt = 0;
	while (l <= r) {


		if (arr[l].name == arr[r].name) {
			if (arr[r].num > arr[l].num) {
				arr[r - 1].num += arr[r].num - arr[l].num;
				cnt += arr[r].num - arr[l].num;
			} else if (arr[r].num < arr[l].num) {
				arr[l + 1].num += arr[l].num - arr[r].num;
				cnt += arr[l].num - arr[r].num;
			}
			l++, r--;
		} else {
			if (arr[r].num == arr[l].num) {
				cnt += arr[l].num;
				l++, r--;
			} else if (arr[r].num > arr[l].num) {
				cnt += arr[r].num - arr[l].num;
				arr[r].num -= arr[l].num;
				l++;

			} else if (arr[r].num < arr[l].num) {
				cnt += arr[l].num - arr[r].num;
				arr[l + 1].num += arr[l].num - arr[r].num;
				r--;
			}
		}

	}

	cout << cnt;

	return 0;
}
/*
7
123 a
234 b
234 r
122 r
212 b
123 a
323 d

3
2 a
2 b
1 c

2
2 a
3 a

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

5
2 b
5 a
1 c
2 a
5 b
*/
