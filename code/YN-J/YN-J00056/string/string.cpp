#include <iostream>
#include <string>
using namespace std;
#define int long long
const int MAXN = 2e5 + 10;
int a[MAXN];
char c[MAXN];
string s;
int n, tot, mid;
int ncnt, lcnt;
int tmp = 0;
int ans;

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	//cout << n << " ";
	for (int i = 1; i <= n; i++) { //read
		cin >> a[i] >> c[i];
		tot += a[i];
		for (int j = 1; j <= a[i]; j++)
			s += c[i];
	}
	int len = s.size();
	//cout << len << " ";
	int l = 0, r = len - 1;
	while (l <= r) {
		if (s[l] != s[r])
			ans++;
		l++;
		r--;
	}
	cout << ans;

	return 0;
}