#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ef else if

const int N(5e5+5);
int n;
ll m, a[N], d[N];

bool checkA() {
	for (int i=1; i<=n; i++) {
		if (a[i] != i) return false;
	}
	return true;
}

int checkB() {
	int d = a[2]-a[1];
	for (int i=3; i<=n; i++) {
		if (a[i]-a[i-1] != d) return false;
	}
	return d;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	if (checkA()) {
		ll l(1), r(1e9), mid;
		while (l < r) {
			mid = (l+r)>>1;
			if (((mid*(mid+1))>>1) >= m) r = mid;
			else l = mid+1;
		}
		if (((l*(l+1))>>1) == m) l++;
		cout << l;
	}
	ef (int d = checkB()) {
		ll l(1), r(1e9), mid;
		while (l < r) {
			mid = (l+r)>>1;
			if (((mid*(mid+1))>>1)*d >= m) r = mid;
			else l = mid+1;
		}
		if (((l*(l+1))>>1)*d == m) l++;
		cout << l;
	}
	else {
		for (int i=1; i<=n; i++) {
			d[i] = a[i]-a[i-1];
		}
	}
	return 0;
}
