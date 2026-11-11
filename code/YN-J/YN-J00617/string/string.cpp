#include <bits/stdc++.h>
using namespace std;
#define int long long

struct d {
	int num;
	char a;
};
d arr[1000000];
int cnt, n;

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i].num >> arr[i].a;
	}
	int l = 1, r = n;
	while (l < r) {
		int s = min(arr[l].num, arr[r].num);
		if (arr[l].a != arr[r].a)
			cnt += s;
		if (arr[l].num > arr[r].num) {
			arr[l].num -= s;
			r--;
		} else if (arr[l].num == arr[r].num) {
			l++;
			r--;
		} else {
			arr[r].num -= s;
			l++;
		}
	}

	cout << cnt;
	return 0;
}