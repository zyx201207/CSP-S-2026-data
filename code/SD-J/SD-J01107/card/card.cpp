#include <iostream>
#include <cstring>
#include <vector>
#define ll long long
using namespace std;
int n, m;
int ans[300050];
int pos[300050], a[500050];
int now[500050], nowi;
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	memset(pos, -1, sizeof(pos));
	for (int i = n; i; --i) {
		now[++nowi] = a[i];
		if (pos[a[i]] != -1) {
			nowi = n - pos[a[i]] + 1;
		}
		pos[a[i]] = max(pos[a[i]], i);
		for (int j = 1; j <= nowi; ++j)
			++ans[now[j]];
	}
	for (int i = 1; i <= m; ++i)
		cout << ans[i] << ' ';
	return 0;
}
