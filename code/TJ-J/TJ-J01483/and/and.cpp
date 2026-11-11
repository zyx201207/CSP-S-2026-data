// T3. and 
#include <iostream>

using namespace std;

typedef long long ll;

#define N 200005

ll m, n, a[N], t[N][35], ans[35], sum;
bool flag[N];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		for (int j = 0; j <= 30; j++) {
			if ((a[i] >> j) & 1) t[i][j] = 1;
		}
	}
	for (int j = 30; j >= 0; j--) {
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (t[i][j] == 1 && !flag[i]) cnt++;
		}
		if (cnt >= m) {
			ans[j] = 1;
			for (int i = 1; i <= n; i++) {
				if (t[i][j] == 0 && !flag[i]) flag[i] = true;
			}
		}
	}
	for (int j = 0; j <= 30; j++) sum += (ans[j] * (1 << j));
	cout << sum;
	return 0;
}
