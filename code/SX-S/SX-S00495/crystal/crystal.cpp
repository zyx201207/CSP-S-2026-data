#include <bits/stdc++.h>
using namespace std;
int n, ans;
long long m, a[500005], cha[500005], p[500005], zho, ji = pow(2, 62) - 1;

bool cmp(int c, int b) {
	return cha[c] < cha[b];
}

bool cmp1(int l, int r, int rr, int cal, int car) {
	if (l && r <= n)
		return rr >= min(cha[l] + cal, cha[r] + car);
	else if (l)
		return rr >= cha[l] + cal;
	else if (r <= n)
		return rr >= cha[r] + car;
	else
		return 0;
}

int find(int x) {
	int l = x - 1, r = x + 1, rr = m;
	long long car = cha[x], cal = cha[x];
	zho = 2;
	rr -= cha[x];
	while (cmp1(l, r, rr, cal, car)) {
		zho++;
		if (cha[l] + cal < cha[r] + car && l >= 1) {
			rr -= cha[l] + cal;
			cal += cha[l];
			l--;
		}

		else {
			if (r <= n)
				rr -= cha[r] + cal;
			cal += cha[l];
			r++;
		}
		if (cal > ji || car > ji)
			return 0;
	}
	ji = min(ji, max(cal, car));

	return zho;

}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		p[i] = i;
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++)
		cha[i] = abs( a[i] - a[i - 1]);
	sort(p + 1, p + n + 1, cmp);

	for (int i = 1; i <= n; i++) {
		ans = max(ans, find(p[i]));
	}
	cout << ans;
	return 0;
}
