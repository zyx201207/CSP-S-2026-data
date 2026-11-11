#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m;
const int maxn = 5e5;
int a[maxn];
int c[maxn], ans[maxn], tong[maxn];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {

		memset(c, 0, sizeof(c));
		memset(tong, 0, sizeof(tong));

		for (int j = i; j <= n; j++) {

			c[j] = a[j];
		}

		for (int j = 1; j <= n; j++) {

			c[j] = c[j] - c[j - 1];
		}

		for (int j = i; j <= n; j++) {

			if (tong[a[j]] != 0 && c[tong[a[i]]] > 0) {
				c[tong[a[j]]] -=  (m + 1);
				c[j] += (m + 1);
			}

			tong[a[j]] = j;
		}

		for (int  j = i; j <= n; j++) {

			c[j] = c[j - 1] + c[j];
		}

		for (int j = i; j <= n; j++) {

			if (c[j] > 0) {
				ans[a[j]]++;
			}
		}
	}

	for (int i = 1; i <= m; i++) {

		cout << ans[i] << " ";
	}

	return 0;
}
