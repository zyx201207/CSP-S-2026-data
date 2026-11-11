#include <bits/stdc++.h>
using namespace std;
long long ans;

struct node {
	long long num;
	char w;
} a[200005];
int n;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;

	int len = 1;

	for (int i = 1; i <= n; i++) {
		cin >> a[i].num >> a[i].w;
	}
	int l = 1, r = n + 1 ;

	while (l < r) {


		if (a[l].w != a[r].w) {
			if (a[l].num < a[r].num) {
				ans += a[l].num;
				a[r].num -= a[l].num;
				l++;

			} else if (a[l].num > a[r].num) {
				ans += a[r].num;
				a[l].num -= a[r].num;
				r--;
			}

			else if (a[l].num == a[r].num) {
				ans += min(a[l].num, a[r].num);
				l++;
				r--;

			}
		} else {
			if (a[l].num < a[r].num) {

				a[r].num -= a[l].num;
				l++;

			} else if (a[l].num > a[r].num) {

				a[l].num -= a[r].num;
				r--;
			}

			else if (a[l].num == a[r].num) {

				l++;
				r--;

			}
		}



	}
	cout << ans;
	return 0;
}

