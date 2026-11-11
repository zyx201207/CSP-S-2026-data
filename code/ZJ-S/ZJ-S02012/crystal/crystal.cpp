#include<bits/stdc++.h>
using namespace std;
const long long N = 5e5 + 5;
long long a[N];
long long f[N], sum[N];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n, m;
	cin >> n >> m;
	bool flagA = true;
	for (long long i = 1;i <= n; i++) {
		
		cin >> a[i];
		if (a[i] != i) flagA = false;
	}
	if (flagA) {
		cout << m / 2 + 1;
		return 0;
	}
	long long da = a[1] - 1;
	for (int i = 1;i <= n; i++) {
		a[i] -= da;
	}

	long long d = a[2] - a[1];
	//sum[0] = a[1];
	long long x = d - 1;
	for (int i = 2;i <= m + 5; i++) {
		x += i * d;
		if (x == m) cout << i;
		if (x > m) {
			cout << i - 1;
			return 0;
		}
	}
	cout << n;
}
//5 3
//2 4 8 9
/*
从i变j
0 2 5 5 10
0 0 3 3 8
0 0 0 0 5
0 0 0 0 5
0 0 0 0 0

0 2 5 5 10
0 0 8 8 18
0 0 0 8 23
0 0 0 0 28
0 0 0 0 0
*/