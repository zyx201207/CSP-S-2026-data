#include <bits/stdc++.h>
#define int unsigned long long
#define ve vector<int>
#define pii pair<int, int>
#define vi vector<int, int>
#define endl '\n'
using namespace std;
const int N = 1e8 + 10;
const int INF = 0x3f3f3f3f;
int a[N];
void solve() {
	int n, d;
	cin >> n >> d;
	int ok = 0;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	int cha = a[2] - a[1];
	for (int i = 3; i <= n; i ++) {
		if (a[i] - a[i - 1] != cha) {
			ok = 1;
		}
	}
	if (ok == 0) {
		if (cha >= d) {
			cout << 0 << endl;
			return;
		}
		int sum = 0;
		for (int i = 1; i <= n - 2; i ++) {
			sum += i;
		}
		cout << sum << endl;
		return;
	}
	int cnt = 0;
	for (int i = 1; i <= n - 3; i ++) {
		for (int j = i + 3; j <= n; j ++) {
			if (d >= (a[j - 1] - a[i]) && d >= (a[j] - a[i + 1])) {
				cnt ++;
			}
		}
	}
	cout << cnt << endl;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c;
	cin >> c;
	int t = 1;
	cin >> t;
	while(t --) {
		solve();
	}
	return 0;
}