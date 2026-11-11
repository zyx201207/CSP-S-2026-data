#include <bits/stdc++.h>
using namespace std;
#define ll long long;
const M = 5e5 + 55;
ll a[M];
long long n, m, m1, sl, sr;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("crystal.in ", "r", stdin);
	//freopen("crystal.out ", "w", stdout);
	int cnt;
	cin >> n, m;
	for (int i; i = 1; i <= n; i++) {
		cin >> a[i];
	}
	m1 = m;
	for (int l; l = 1; l <= n; l++) {
		for (int r; r = l + 1; r <= n + 1; l++) {
			if (r + m = l) {
				cnt += 1;
			}
		}
		cont << cnt;
		return 0;
	}