#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
long long n, lol, l[maxn], ll[maxn], l1[maxn], l2[maxn];
long long k1 = 1, k2 = 1, k, p, k3, k4, ans;
char c, z[maxn], zz[maxn], z1[maxn], z2[maxn];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%lld", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%lld", &lol);
		cin >> c;
		if (c == z[k2 - 1]) {
			l[k1 - 1] += lol;
		} else {
			l[k1] = lol;
			z[k2] = c;
			k1++;
			k2++;
		}
		k += lol;
	}
	p = k / 2;
	if (k % 2 == 1) {
		long long b = 0;
		for (int i = 1; i <= k1 - 1; i++) {
			if (b + l[i] >= k / 2 + 1) {
				if (b + l[i] == k / 2 + 1) {
					l[i] --;
					break;
				}
				b += l[i];
				long long j = b - (k / 2 + 1);
				l[i] -= j;
				break;
			} else {
				b += l[i];
			}
		}
	}
	long long kk = 1;
	for (int i = 1; i <= k1 - 1; i ++) {
		if (l[i] != 0) {
			ll[kk] = l[i];
			zz[kk] = z[i];
			kk++;
		}
	}

	long long cnt = 0;
	long long f = 0;
	for (int i = 1; i <= kk - 1; i++) {
		if (cnt == p) {
			break;
		}
		if (cnt + l[i] <= p) {
			l1[i] = ll[i];
			z1[i] = zz[i];
			cnt += ll[i];
			ll[i] = 0;
		} else {
			long long y = p - l1[i - 1];
			l1[i] = y;
			z1[i] = zz[i];
			cnt += y;
			ll[i] -= y;
		}
		k3++;
	}
	cnt = 0;
	for (int i = 1; i <= kk - 1; i++) {
		if (cnt == p) {
			break;
		}
		if (ll[i] == 0) {
			f++;
			continue;
		}
		if (cnt + l[i] <= p) {
			l2[i - f] = ll[i];
			z2[i - f] = zz[i];
			cnt += ll[i];
			ll[i] = 0;
		} else {
			long long y = p - l2[i - 1 - f];
			l2[i - f] = y;
			z2[i - f] = zz[i];
			cnt += y;
			ll[i] -= y;
		}
		k4++;
	}

	long long int len = min(k3, k4);
	long long d2 = 1;
	long long d3 = 1;
	long long int g = max(k3, k4);
	while (len - d3 + 1 != 0) {
		if (z1[len - d3 + 1] != z2[d2]) {
			long long j = min(l1[len - d3 + 1], l2[d2]);
			l2[d2] -= j;
			l1[len - d3 + 1] -= j;
			ans += j;
			if (l1[len - d3 + 1] == 0 and l2[d2] == 0) {
				d3 ++;
				d2 ++;
			} else if (l1[len - d3 + 1] == 0 and l2[d2] != 0) {
				d3++;
			} else if (l1[len - d3 + 1] != 0 and l2[d2] == 0) {
				d2++;
			}
		} else {
			d2++;
			d3++;
		}
	}
	cout << ans;

	return 0;
}