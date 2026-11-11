#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;

struct node {
	long long a, n;
} t[N];
int tmp = 1, vis[N];
long long n;
long long m, a[N];
long long maxi = 0;
int q[N];

bool cmp(node a1, node b) {
	return a1.a < b.a;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		if (a[i] != a[i - 1] || i == 1) {
			tmp++;
			t[tmp].a = a[i];
		}
		t[tmp].n++;
	}


	for (int i = tmp; i >= 1; i--) {
		long long m1 = m, sum = t[i].n;
		for (int j = i - 1; j >= 1; j--) {
			int cha = t[i].a - t[j].a;
			if (t[j].n * cha <= m1) {
				sum += t[j].n;
				m1 -= t[j].n * cha;
			} else {
				sum += m1 / cha;
				break;
			}
		}

		if (maxi < sum)
			maxi = sum;
	}
	cout << maxi;

	return 0;
}
