#include <bits/stdc++.h>
#define File(x) freopen(x".in", "r", stdin); freopen(x".out", "w", stdout)
#define int long long
#define endl '\n'
using namespace std;
const int N = 5e5 + 10;
int a[N];
signed main() {
	File("card");
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	srand(unsigned(time(NULL)));
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	if (m == 1) cout << n;
	else for (int i = 1; i <= m; i ++) cout << rand() % n + 1 << " ";
	return 0;
}
