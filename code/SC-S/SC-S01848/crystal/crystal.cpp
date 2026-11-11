#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 5e5 + 5;
int n , m;
int a[MAXN];
struct node {
	int whats_point;
	int cha;
}b[MAXN];
signed main () {
	ios::sync_with_stdio (false);
	cin.tie (0);
	freopen ("crystal.in" , "r" , stdin);
	freopen ("crystal.out" , "w" , stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort (a + 1 , a + 1 + n);
	int ave = 0;
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += a[i];
	}
	ave = sum / n;
	for (int i = 1; i <= n; i++) {
		if (ave > a[i]) {
			b[i].cha = ave - a[i];
			b[i].whats_point = i;
		}
		else {
			b[i].cha = a[i] - ave;
			b[i].whats_point = i;
		}
	}
	int minn = 1e18;
	for (int i = 1; i <= n; i++) {
		minn = min (minn , b[i].cha);
	}
	int pos = 0;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (b[i].cha == minn) {
			pos = b[i].whats_point;
			cnt ++;
		}
	}
	int p = 0;
	for (int i = 1; i <= n; i++) {
		if (p < m) {
			if (a[pos] > a[i]) {
				p += a[pos] - a[i];
				cnt++;
			}
			else {
				p += a[i] - a[pos];
				cnt++;
			}
		}
	}
	cout << cnt << endl;
}