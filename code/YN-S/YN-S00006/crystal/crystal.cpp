#include <iostream>
#include <algorithm>
using namespace std;
const int N = 500000;
long long a[N + 5];
long long suf[N + 5];
int n;
long long m;

void init() {
	for (int i = n; i >= 0; i--) {
		suf[i] = suf[i + 1] + a[i];
	}
}

long long check(int l, int r) {
	long long sum, temp;
	sum = suf[l] - suf[r + 1];
	temp = (r - l + 1);
	temp *= a[r];
	return temp - sum;
}

int bin(int pos) {
	int l = 1, r = pos, mid, be = pos;
	//cout << "pos:" << pos << endl;
	while (l <= r) {
		mid = (l + r) / 2;
		//cout << l << " " << r << endl;
		//cout << check(mid, pos) << endl;
		if (check(mid, pos) <= m) {
			r = mid - 1;
			be = mid;
		} else {
			l = mid + 1;
		}
	}
	//cout << "len:" << pos - be + 1 << endl;
	return pos - be + 1;
}

//binary
int main() {
	int ans = 0;
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	init();
	for (int i = 1; i <= n; i++) {
		ans = max(ans, bin(i));
	}
	printf("%d", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}