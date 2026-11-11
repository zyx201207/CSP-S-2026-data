#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

const int N = 5e5 + 50;

int n, m, a[N], st[N], top, ans[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++) {
		top = 0;
		for (int j = i; j <= n; j++) {
			if (!top) {
				st[++top] = a[j];
			} else {
				bool flag = 0;
				for (int i = 1; i <= top; i++) {
					if (a[j] == st[i]) {
						flag = 1;
						break;
					}
				}
				if (flag == 1) {
					top = 1;
					st[top] = a[j];
				} else {
					st[++top] = a[j];
				}
			}
		}
		for (int j = 1; j <= top; j++) {
			ans[st[j]]++;
		}
	}
	for (int i = 1; i <= m; i++)
		cout << ans[i] << ' ';

	return 0;
}
