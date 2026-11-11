#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 2e5 + 5;
int n, m;
ll ans;
ll num[N];
ll sq[31];

bool cmp(ll a, ll b) {
	if (a == b)
		return false;
	ll mia = 1e10, mib = 1e10;
	for (int i = 0; i <= 30; ++i) {
		if (abs(sq[i] - a) < mia) {
			mia = abs(sq[i] - a);
		}
		if (abs(sq[i] - b) < mib) {
			mib = abs(sq[i] - b);
		}
	}
	if (mia != mib)
		return mia < mib;
	return a > b;
}

ll zh(ll a, ll b) {
	int ejza[31] = {0}, ejzb[31] = {0}, ejzjg[31] = {0};
	int x = 30, y = 30;
	while (a != 0) {
		ejza[x] = (a % 2);
		a /= 2;
		x--;
	}
	while (b != 0) {
		ejza[y] = (b % 2);
		b /= 2;
		y--;
	}
	int be = min(x, y);
	for (int i = be; i <= 30; --i) {
		if (ejza[i] == 1 && ejzb[i] == 1) {
			ejzjg[i] = 1;
		} else {
			ejzjg[i] = 0;
		}
	}
	int SQ = 1;
	ll r = 0;
	for (int i = 30; i >= be; --i) {
		r += SQ * ejzjg[i];
		SQ *= 2;
	}
	return r;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);

	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		cin >> num[i];
	}

	sq[0] = 1;

	for (int i = 1; i <= 30; ++i) {
		sq[i] = sq[i - 1] * 2;
	}

	sort(num + 1, num + n + 1, cmp);

	for (int i = 1; i <= m; i++) {
		ans = zh(num[i], num[i + 1]);
		num[i + 1] = ans;
	}

	cout << ans;
	return 0;
}