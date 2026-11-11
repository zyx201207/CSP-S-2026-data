#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 10;
int n, tail = 0;
ll ans = 0;

struct node {
	int x;
	char c;
} a[N];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].x >> a[i].c;
	}
	tail = n;
	int i = 1;
	while (i != tail) {
		if (a[i].x >= a[tail].x) {
			if (a[i].c != a[tail].c) {
				ans += a[tail].x;
			}
			a[i].x -= a[tail].x;
			tail--;
		} else if (a[i].x <= a[tail].x) {
			if (a[i].c != a[tail].c) {
				ans += a[i].x;
			}
			a[tail].x -= a[i].x;
			i++;
		}
	}
	cout << ans << '\n';

	return 0;
}