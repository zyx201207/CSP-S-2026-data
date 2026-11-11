#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 5e5 + 5;
ll n, m, a[MAXN];
void solveAB(int x) {
	int ans = 1;
	while(ans < n && x * ans <= m) {
		m -= x * ans;
		ans++;
	}
	cout << ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i]; 
	bool AB = true, x = a[2] - a[1];
	for(int i = 3; i <= n; i++) {
		if(a[i] - a[i - 1] != x) AB = false;
	}
	sort(a + 1, a + n + 1);
	if(AB) {solveAB(x); return 0;}
	int ans = 0;
	for(int i = n; i >= 1; i--) {
		if(i <= ans) break;
		int now = m, j = i;
		while(j >= 1 && a[i] - a[j - 1] <= now) {
			now -= a[i] - a[j - 1];
			j--;
		}
		ans = max(ans, i - j + 1);
	}
	cout << ans;
	return 0;
}
