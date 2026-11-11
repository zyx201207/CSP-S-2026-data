#include <bits/stdc++.h>
#define N 100005

using namespace std;


long long n, m;
long long a[N], b[N];

bool cmp(int x, int y) {
	return x < y;
}

int main() {
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	b[1] = 0;
	for (int i = 2; i <= n; i++) {
		b[i] = a[i] - a[i - 1];
	}
	sort (b + 1, b + n + 1, cmp);
	long long sum = 0, time = 0;
	bool flag = true;
	for (int i = 1; i <= n; i++) {
		if (b[i] <= 0) continue;
		if (sum >= m || sum + b[i] > m) break;
		else {
			sum += b[i];
			time++;
		}
		if (i == n && !(sum >= m)) {
			flag = false;
			break;
		}
	}
	if (flag == true) {
		cout << time;
	}
	else {
		cout << time + n / 3;
	}
	return 0;
}