#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
int n;
long long m;
long long p[maxn];
long long a[maxn], x;
int ans, num;
int lx, ly;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> p[i];
	sort(p + 1, p + 1 + n);
	for(int i = 1; i < n; i++) {
		a[i] = p[i + 1] - p[i];
	}
	lx = 1, ly = 1;
	x = 0, num = 0;
	while(1) {
		if(ly >= n || lx >= n) break;
		if(x + a[ly] * (ly - lx + 1) <= m) {
			num++;
			ans = max(ans, num);
			x = x + a[ly] * (ly - lx + 1);
			//cout << lx << ' ' << ly << ' ' << x << '\n';
			ly++;
			continue;
		}
		else {
			while(1) {
				if(lx == ly) {
					lx++, ly++;
					break;
				}
				else {
					num--;
					x -= p[ly] - p[lx];
					lx++;
				}
				if(x + a[ly] * (ly - lx + 1) <= m) break;
			}
		}
	}
	cout << ans + 1;
	return 0;
}
