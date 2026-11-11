#include <iostream>
#include <algorithm>
using namespace std;
#define int long long
const unsigned int MAXN = 5e5 + 10;
int n, m;
int a[MAXN];
int d[MAXN];
int tot;
int ans = 1;

bool merge(int x, int y) {
	if (a[x] < a[y]) {
		int cha = a[y] - a[x];
		if (m >= cha * x) {
			m = m - cha * x;
			//cout << "m:" << m << " x: " << x << " a[x]: " << a[x] << " a[y]: " << a[y] << endl;
			ans++;
			return true;
		} else {
			//cout << "m:" << m << " x:" << x << " a[x]:" << a[x] << " a[y]:" << a[y] << "END!!!!!!!!" << endl;
			return false;
		}
	} else if (a[x] == a[y]) {
		//cout << "m:" << m << " x: " << x << " a[x]: " << a[x] << " a[y]: " << a[y] << endl;
		ans++;
		return true;
	} else {
		return false;
	}
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	//cout << m << endl;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i < n; i++) {
		if (merge(i, i + 1)) {
			//cout << ans << " ";
		} else {
			break;
		}
	}
	cout << ans;
	//cout << endl << a[1] << endl;
	return 0;
}