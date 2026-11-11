#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 10;
int n, cs = 1, m = 1, ms, wrt;
string c;
struct node {
	int x;
	string s;
}a[N];

void so() {
	cin >> n;
	for (int i = 1 ; i <= n ; i++) cin >> a[i].x >> a[i].s;
	c = a[1].s, ms = a[1].x;
	for (int i = 2 ; i <= n ; i++) {
		if (a[i].s != c) cs++;
		if (a[i].x != ms) m++;
	}
	if (cs == 1) {
		cout << "0\n";
		return ;
	}
	if (m == 1) {
		if (n % 2 == 0) {
			for (int i = n / 2 + 1 ; i <= n ; i++)
				if (a[i].s != a[i - n / 2].s) wrt += a[i].x;
			cout << wrt << "\n";
			return ;
		}
		else {
			for (int i = n / 2 + 2 ; i <= n ; i++)
				if (a[i].s != a[i - n / 2 - 1].s) wrt += a[i].x;
			cout << wrt << "\n";
			return ;
		}
	}
//	int mid = a[1].x, j = 1;
//	for (int i = n ; i > 1 && i > j ; i--) {
//		if (mid - a[i].x <= 0) j++, mid += a[j].x;
//	}
//	for (int i = j + 1 ; i <= n ; i++) mid -= a[i].x;
//	if (mid == 0) {
//		for (int i = j + 1 ; i <= n ; i++) 
//	}
//	cout << a[j].s << " " << mid;
	string sl = "";
	int mx = 0;
	for (int i = 1 ; i <= n ; i++) mx += a[i].x;
	for (int i = 1 ; i <= n ; i++)
		for (int j = 1 ; j <= a[i].x ; j++)
			sl = sl + a[i].s;
	if (mx % 2 == 0) {
		for (int i = 1 ; i <= mx / 2 ; i++) {
			if (sl[i] != sl[mx / 2 + i]) wrt++;
		}
	}
	else {
		for (int i = 1 ; i <= mx / 2 + 1 ; i++) {
			if (sl[i] != sl[n - i + 1]) wrt++;
		}
	}
	cout << wrt << "\n";
}

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
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
3
2 a
2 b
1 c

*/



