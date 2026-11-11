#include <bits/stdc++.h>
using namespace std;

struct node {
	int num;
	char c;
} a[200001];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].num >> a[i].c;
	}
	int nl = a[1].num, nr = a[n].num;
	char cl = a[1].c, cr = a[n].c;
	long long ans = 0;
	for (int i = 1, j = n; i <= j;) {
		if (cl != cr) {
			if (nl < nr) {
				ans += nl;
				nr -= nl;
				nl = 0;
			} else if (nl > nr) {
				ans += nr;
				nl -= nr;
				nr = 0;
			} else {
				ans += nr;
				nr = 0, nl = 0;
			}
		} else {
			if (nl < nr) {
				nr -= nl;
				nl = 0;
			} else if (nl > nr) {
				nl -= nr;
				nr = 0;
			} else {
				nr = 0;
				nl = 0;
			}
		}
		if (nl == 0) {
			i++;
			nl = a[i].num;
			cl = a[i].c;
		}
		if (nr == 0) {
			j--;
			nr = a[j].num;
			cr = a[j].c;
		}
	}
	cout << ans;
	return 0;
}
