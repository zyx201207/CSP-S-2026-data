#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int a[100001];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i] > 1) {
				ans = a[i];
				ans++;
			}
		}
	}
	cout << ans;
	cout << " " << "1" << " " << "4";
	return 0;
}