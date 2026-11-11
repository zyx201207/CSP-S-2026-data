//
#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

#define N 5005

int n, m, a[N], cnt[N][N], ans, b[N], p[N];
bool flag[200005], A;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] < a[i - 1]) A = true;
	}
	if (!A) {
		for (int i = n; i >= 1; i--) {
			if (!flag[a[i]]) {
				flag[a[i]] = true, p[a[i]] = i;
			}
		}
		for (int i = 1; i <= m; i++) cout << p[i] << ' ';
		return 0;
	}
	if (m <= 2) {
		int sum = 0;
		for (int i = 1; i <=n; i++) sum += (a[i] == 2);
		if (a[n] == 1) cout << n << ' ' << sum;
		else cout << n - sum << ' ' << n;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		memset(flag, false, sizeof(flag));
		memset(b, 0, sizeof(b));
		int st = i, t = 0;
		for (int j = i; j <= n; j++) {
			if (!flag[a[j]]) {
				b[++t] = a[j], flag[a[j]] = true;
			} else {
				int idx = t;
				while (b[idx] != a[j]) idx--;
				for (int k = idx + 1; k <= t; k++) flag[b[k]] = false, b[k] = 0;
				t = idx;
			}
		}
		for (int i = 1; i <= m; i++) cnt[i][1] += flag[i];
	}
	for (int i = 1; i <= m; i++) cout << cnt[i][1] << ' ';
	return 0;
}

/*



*/


