#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 10;
int a[N];

void so() {
	int n, m; cin >> n >> m;
	for (int i = 1 ; i <= n ; i++) cin >> a[i];
	for (int i = 1 ; i <= m ; i++) cout << a[i];
}

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T = 1;
//	cin >> T;
	while (T--) so();
	return 0;
}
/*
abcdefghijklmnopqrstuvwxyz
ABCDEFGHIJKLMNOPQRSTUVWXYZ
!@#$%^&*()_+[]{}~`¡¤
1234567890
*/



