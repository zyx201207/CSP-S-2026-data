#include <bits/stdc++.h>
using namespace std;
long long a[1000001];
long long b[1000001];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m, j = 0, mi, sum = 0, Ans = 1;
	cin >> n >> m;
	map<long long, bool> B;
	map<long long, long long> A;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		A[a[i]]++;
		if (A[a[i]] != 1) {
			j++;
			b[j] = i;
		}
	}
	sort(a + 1, a + 1 + n);
	mi = n % 2 ? n / 2 + 1 : n / 2;
	long long l = 1, r = n;
	for (int I = 1; I <= j; I++) {
		long long ANs = A[a[b[I]]];
		for (int i = b[I] - 1; i >= 1; i--) {
			if (b[I] == 1) {
				break;
			}
			sum += a[b[I]] - a[i];
			if (sum <= m && a[i] != a[b[I]]) {
				ANs++;
			} else {
				break;
			}
		}
		Ans = max(Ans, ANs);
	}
	while (mi > 0 && mi <= n) {
		B[mi] = true;
		long long ans = A[a[mi]];
		for (int i = mi - 1; i >= 1; i--) {
			if (mi == 1) {
				break;
			}
			sum += a[mi] - a[i];
			if (sum <= m && a[i] != a[mi]) {
				ans++;
			} else {
				break;
			}
		}
		Ans = max(Ans, ans);
		if ((B[a[mi - 1]] == true && B[a[mi + 1]] == true) || mi == n || mi == 1) {
			break;
		}
		if (sum < m) {
			l = mi;
			mi = (r - l) / 2;
		} else {
			r = mi;
			mi = (r - l) / 2;
		}
	}
	cout << Ans;
	return 0;
}