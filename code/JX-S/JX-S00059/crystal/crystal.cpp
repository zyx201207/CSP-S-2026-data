#include <bits/stdc++.h>
using namespace std;
long long a[500005];
int n, MAXN = -0x3f3f3f3f;
long long m;
void cmp(int y, int x, long long c, int s){
	if (c < 0 || x <= 0) {
		MAXN = max(MAXN, s - 1);
		return ;
	}
	if (a[x] == a[x - 1]) cmp(y, x - 1, c, s + 1);
	else {
		cmp(y, x - 1, c - abs(a[y] - a[x - 1]), s + 1);
		cmp(y, x - 1, c , s);
	}
	return ;
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    bool f = 0;
    for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (a[i] != a[i - 1] && a[i] != 1) f = 1;
	}
	if (f == 0) {
		cout << n;
		return 0;
	}
	sort(a + 1, a + n + 1);
	bool flag = 0;
	int d = a[2] - a[1];
	for (int i = 3; i < n; i++) {
		if (a[i] - a[i - 1] != d) {
			flag = 1;
			break;
		}
	}
	if (flag == 0) {
		int cur = 0;
		for (int i = 1; i <= n; i++) {
			if (m - abs(i * d) >= 0) {
				cur++;
				m -= abs(i * d);
			}
			else break;
		}
		cout << cur;
		return 0;
	}
	for (int i = n; i > 1; i--) {
		long long c = m;
		cmp(i ,i, c, 1);
	}
	cout << MAXN;
    return 0;
}
