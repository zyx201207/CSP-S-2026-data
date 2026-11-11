#include <bits/stdc++.h>
using namespace std;
int a1[200005];
bool  vis[200005];
int a, b, maxx = -1;

void aand(int n, int p) {
	if (n == b)
		return;
	else {
		for (int i = 1; i <= a; i++) {
			int k = a1[i] & p;
			if (k >= maxx && vis[i] == 0) {
				maxx = k;
				vis[i] = 1;
			}
			if (n - 1 == a)
				return;
			aand(n + 1, maxx);
		}
	}
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> a >> b;
	for (int i = 1; i <= a; i++) {
		cin >> a1[i];
	}
	int c, d;
	for (int i = 1; i <= a; i++) {
		for (int j = i + 1; j <= a; j++) {
			int l = a1[i] & a1[j];

			if (l >= maxx) {
				maxx = l;
				c = i;
				d = j;
			}

		}
	}
	vis[c] = 1;
	vis[d] = 1;
	if (a == 2) {
		cout << maxx;
		return 0;
	}
	aand(2, maxx);
	cout << maxx;
	return 0;
}