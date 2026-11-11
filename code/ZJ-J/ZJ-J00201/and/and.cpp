#include<bits/stdc++.h>
using namespace std;
int n, m, t[35], op, cnt, ppt[35];
struct st{
	int x;
	int su[35];
}a[200010];
bool cmp(st x, st y) {
	for (int i = 1; i <= cnt; i++) {
		if (x.su[ppt[i]] != y.su[ppt[i]]) {
			return x.su[ppt[i]] > y.su[ppt[i]];
		}
	}
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].x;
		op = a[i].x, cnt = 1;
		while(op) {
			if (op % 2) {
				t[cnt]++;
				a[i].su[cnt] = 1;
			}
			op /= 2;
			cnt++;
		}
	}
	cnt = 0;
	for (int i = 30; i >= 1; i--) {
		if(t[i] >= m) ppt[++cnt] = i;
	}
	sort(a + 1, a + n + 1, cmp);
	for (int i = 2; i <= m; i++) {
		a[1].x &= a[i].x;
	}
	cout << a[1].x;
	return 0;
}

