#include <bits/stdc++.h>
using namespace std;

string a;
long long ans;
long long ai[200005];
char ci[200005];


int gys(int a, int b) {
	if (a % b == 0) {
		return b;
	} else if (b % a == 0) {
		return a;
	}
	return 1;
}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= 2; i++) {
		cin >> ai[i] >> ci[i];
	}
	int zd = gys(ai[1], ai[2]);
	for (int i = 3; i <= n; i++) {
		cin >> ai[i] >> ci[i];
		zd = gys(zd, ai[i]);
	}
	for (int i = 1; i <= n; i++) {
		ai[i] /= zd;
		for (int j = 1; j <= ai[i]; j++) {
			a += ci[i];
		}
	}
	int l = a.size();
	int l1 = l - 2;
	for (long long i = 0; i <= l - 1; i++) {
		if (a[i] != a[l1 + 1 - i]) {
			ans++;
		}
	}
	cout << (ans / 2)*zd;
	return 0;
}