#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int n, ans = 0;
long long m;
long long a[N];
int chongfu[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	memset(chongfu, 0, sizeof chongfu);
	memset(a, 0, sizeof a);
	long long maxx = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		chongfu[a[i]]++;
		if (chongfu[a[i]] > maxx) {
			maxx = chongfu[a[i]];
		}
	}

	sort(a + 1, a + 1 + n);
	long long l = a[1];
	long long r = a[n];
	while (l <= r) {
		long long mid = (l + r) / 2;
		int i = 1;
		long long res = 0;
		while (a[i] < mid) {
			res  = res + abs(a[i] - mid);
			i++;
			if (i > n) {
				break;
			}
		}
		if (res < m) {
			l = mid + 1;
		} else if (res > m) {
			r = mid - 1;
		} else {
			r = (l + r) / 2 ;
			break;
		}
	}
	int i = 1;
	while (a[i] <= r) {
		ans++;
		i++;
		if (i > n) {
			break;
		}
	}
	int anss = 0;
	if (maxx > ans) {
		anss = maxx;
	} else {
		anss = ans;
	}
	cout << anss << endl;
	return 0;
}
