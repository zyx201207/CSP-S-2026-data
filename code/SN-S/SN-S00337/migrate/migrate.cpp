// by 0x0F
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 0x3f3f3f3f3f3f3f3fll;
int C;
int n, d;
int a[2000010];
int pl[2000010], pr[2000010];
int ke[5010], pk = 0;
void bf1() {
	int Ans = 0;
	for (int i = 1; i <= n; i++) {
		pl[i] = lower_bound(a + 1, a + n + 1, a[i] - d) - a;
		pr[i] = upper_bound(a + 1, a + n + 1, a[i] + d) - a - 1;
	}
	for (int i = 1; i <= n; i++) {
		pk = 1; ke[1] = i;
		int lst = i, ans = 1;
		for (int j = i + 1; j <= n; j++) {
			if (a[j] - a[j - 1] > d) break;
			if (a[j] - a[lst] > d) {
				lst = j - 1;
				ke[++pk] = j - 1;
				if (pk > 2) ans *= (pr[ke[pk - 2]] - pl[ke[pk]] + 1);
				if (ans > 2) break;
			}
			int nt = 1;
			if (pk > 1) nt = ans * (pr[ke[pk - 1]] - pl[j] + 1);
			if (nt == 2) Ans++;
		}
	}
	cout << Ans << endl;
}
void workA() {
	int D = d / (a[2] - a[1]);
	if (D <= 1) {cout << 0 << endl; return;}
	D = 2 * D - 1;
	int ans = 0;
	if (D <= n) ans += n - D;
	cout << ans << endl;
}
void workB() {
	
}
void workC() {
	
} 
void init() {
	for (int i = 1; i <= n; i++) a[i] = 0;
}
void solve() {
	cin >> n >> d;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (C >= 1 && C <= 10) bf1();
	else if (C == 11 || C == 12) workA();
	else if (C == 13 || C == 14) workB();
	else if (C >= 15 && C <= 18) workC();
	init();
}
signed main() {
	ios::sync_with_stdio(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int T = 1;
	cin >> C >> T;
	while (T--) solve();
	return 0;
}
