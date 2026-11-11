#include<iostream>
#include<cstring>
using namespace std;
const int N = 100;
int n, d, ans, num[N], a[N];
void dfs(int step, int zhongdian, int k) {
	if (step == zhongdian) {
		num[k]++;
		return;
	}
	for (int i = step + 1 ; i <= zhongdian ; ++i) {
		if (a[i] - a[step] > d) break;
		dfs(i, zhongdian, k + 1);
	}
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--) {
		ans = 0;
		cin >> n >> d;
		for (int i = 1 ; i <= n ; ++i) cin >> a[i];
		for (int i = 1 ; i <= n ; ++i)
		for (int j = 1 ; j < i ; ++j) {
			memset(num, 0, sizeof num);
			dfs(j, i, 0);
			int maxx = 0;
			for (int i = 1 ; i <= n ; ++i) {
				if (num[i]) {
					maxx = num[i];
					break;
				}
			}
			if (maxx == 2) ans++;
		}	
		cout << ans << "\n";
	}

	return 0;
}
