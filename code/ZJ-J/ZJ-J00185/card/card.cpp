#include <iostream>
using namespace std;
const int N = 5e5 + 10;
const int M = 3e5 + 10;
int n, m;
int a[N];
int p[M], l[M], cnt[M];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = n; i >= 1; i--) {
		p[a[i]] = i;
		if (!l[a[i]]) l[a[i]] = i;
		int x = i;
		while (x <= n) {
			cnt[a[x]]++;
			x = l[a[x]] + 1;
		}
	}
	for (int i = 1; i <= m; i++) cout << cnt[i] <<" ";
	return 0;
}
