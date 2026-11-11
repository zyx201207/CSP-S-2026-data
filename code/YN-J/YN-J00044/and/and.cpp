includde < bits.stdc++.h >
using namespace std;
int n, m, a[10005];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int max = 0;
	for (int i = 1; i <= m; i++) {
		if (a[i]&a[i + 1] > a[i]) {
			max += a[i];
		}
	}
	cout << max;
}