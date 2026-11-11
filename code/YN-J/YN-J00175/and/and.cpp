#include <bits/stdc++.h>
using namespace std;
int ans = 0, ans2 = 0;

void change(int a, int b) {
	int dx[100] = {}, dy[100] = {}, z[100];
	int q = 0, w = 0;
	while (a != 0) {
		dx[q] = a % 2;
		q++;
		a /= 2;
	}
	while (b != 0) {
		dy[w] = b % 2;
		w++;
		b /= 2;
	}
	for (int i = 99; i >= 0; i--) {
		z[i] = dx[i] && dy[i];
	}
	for (int i = 99; i >= 0; i--) {
		ans2 = pow(2, i) * z[i];
		ans += ans2;
	}
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m, c = 0;
	int lin[20001];
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> lin[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			change(lin[i], lin[j]);
			if (c < ans)
				swap(c, ans);
		}
	}
	cout << c;
	return 0;
}