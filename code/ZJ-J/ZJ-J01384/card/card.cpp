#include <bits/stdc++.h>
using namespace std;
int n, m, a[500000];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	char b[500000];
	for(int i = 1; i <= n; i++) {
		cout <<(int)b[i] << " ";
		if(i==n) cout << n;
	}
	return 0;
}
