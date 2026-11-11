#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5;
long long a[N];

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int n;
	cin >> n;
	int yy = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		for (int j = 1; j + 1 <= n; j++) {
			if (a[i] == a[j]) {
				yy++;
			}
		}
	}
	cout << yy;
}