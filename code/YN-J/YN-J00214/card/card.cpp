#include <iostream>
using namespace std;
int a[500010];
int b[300010];
int ans;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[a[i]]++;

	}
	for (int i = 1; i <= m; i++) {
		ans += b[i];
		cout << ans << " ";
	}
	return 0;
}
