#include <bits/stdc++.h>
using namespace std;
#define int long long
int tong[300010];
int a[300010];
int flag[300010];
int now[300010];
map<int, int>exist;

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++) {
		exist.clear();
		memset(flag, 0, sizeof flag);
		memset(now, 0, sizeof now);
		int tail = i - 1;
		for (int j = i; j <= n; j++) {
			if (exist.count(a[j]) == 1) {
				for (int k = exist[a[j]]; k <= j - i; k++)
					tail--;
			}
			tail++;
			now[tail] = a[j];
			exist[a[j]] = tail;
		}
		for (int j = i; j <= tail; j++) {
			if (!flag[now[j]]) {
				tong[now[j]]++;
				flag[now[j]] = 1;
			}
		}
	}
	for (int i = 1; i <= m; i++)
		cout << tong[i] << " ";
	return 0;
}