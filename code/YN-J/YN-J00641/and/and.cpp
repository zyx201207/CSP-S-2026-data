#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;

struct Node {
	ll int c;
	int len1 = 0;
} a[N];

bool cmp1(Node a, Node b) {
	if (a.len1 == b.len1) {
		return a.c > b.c;
	} else {
		return a.len1 > b.len1;
	}
}

bool cmp(Node a, Node b) {
	return a.c > b.c;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].c;
	}
	for (int i = 1; i <= n; i++) {
		ll int x;
		x = a[i].c;
		if (x == 0) {
			a[i].len1 = 0;
		}
		while (x != 0) {
			if (x % 2 == 1) {
				a[i].len1++;
			}
			x = x >> 1;
		}
	}
	sort(a + 1, a + n + 1, cmp);
	ll int sum = a[1].c;
	for (int i = 2; i <= m; i++) {
		sum = sum & a[i].c;
	}

	sort(a + 1, a + n + 1, cmp1);
	ll int sum1 = a[1].c;
	for (int i = 2; i <= m; i++) {
		sum1 = sum1 & a[i].c;
	}
	cout << max(sum, sum1);
	return 0;
}