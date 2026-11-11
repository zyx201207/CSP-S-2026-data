#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m, a[100005], b[100005];
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			b[i] = a[j];
		}
	}cout << m << n << a[1];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
