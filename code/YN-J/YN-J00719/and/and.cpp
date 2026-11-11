#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int n, m;
long long a[200020];

int ans = 0;

int er(int x, int x2) {
	int b[100];
	int c[100];
	int ans = 0;
	while (x != 0) {
		if (x % 2 == 0) {
			b[++ans] = 0;
		}

		else {
			b[++ans] = 1;
		}

		x /= 2;
	}
	int b1[100];
	int c1[100];
	int ans1 = 0;
	while (x2 != 0) {
		if (x2 % 2 == 0) {
			b1[++ans1] = 0;
		}

		else {
			b1[++ans1] = 1;
		}

		x2 /= 2;
	}
	int anss1 = 0;
	int sum = 0;
	for (int i = 1; i <= max(ans, ans1); i++) {
		if (min(b[i], b1[i]) != 1)
			sum++;
	}
	return sum;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	long long maxx = INT_MIN;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			maxx = max(maxx, er(a[j],a[j - 1]));
		}
	}
	cout << maxx;
	return 0;
}