#include <bits/stdc++.h>
#define int long long

using namespace std;
const int N = 5e5;
int n, m, a[N + 5], maxn = -1, d;
bool flag1, flag2;
signed main(){
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i){
		cin >> a[i];
		if (i == 2) d = a[i] - a[i - 1];
		if (a[i] != i) flag1 = 1;
		else if (i > 1 && d != a[i] - a[i - 1]) flag2 = 1;
	}
	if (!flag1){
		int nn = (int)sqrt(2 * m);
		if (nn * (nn + 1) / 2 <= m) cout << nn + 1 << "\n";
		else cout << nn << "\n";
		return 0;
	}
	if (!flag2){
		int nn = ((int)sqrt(2 * m) + d - 1) / d;
		if (nn * (nn + 1) / 2 * d <= m) cout << nn + 1 << "\n";
		else cout << nn << "\n";
		return 0;
	}
	sort (a + 1, a + 1 + n);
	for (int i = 1; i <= n; ++ i){
		int sum = 0, tot = 1;
		for (int j = i - 1; j >= 1; -- j){
			sum += (a[i] - a[j]);
			if (sum > m){
				break;
			}
			tot ++;
			maxn = max (maxn, tot);
		}
	}
	cout << maxn << "\n";
	return 0;
}
/*
 5 5
 1 2 4 8 9
 
 5 8
 -3 -1 2 2 7
 */
