//#include <bits/stdc++.h>















//using namespace std;
//#define ll long long
//const ll N = 2e5 + 10;
//
//struct stu {
//	ll idx;
//	ll len;
//	char x;
//} a[N];
//ll n;
//
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	//freopen("travel.in", "r", stdin);
//	//freopen("travel.out", "w", stdout);
//
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		a[i].idx = i;
//		cin >> a[i].len >> a[i].x;
//	}
//	ll l = 1, r = n;
//	ll diff = 0;
//	ll ans = 0;
//	ll pos = 0, neg = 0;
//	while (l < r) {
//		while (pos == neg) {
//			pos += a[l].len;
//			neg += a[r].len;
//			if (a[l].x != a[r].x)
//				ans += min(pos, neg);
//			diff = (pos - neg);
//			l++;
//			r--;
//		}
//		if (diff > 0) {
//			if (a[l].x != a[r].x) {
//				ans += diff;
//			}
//			a[r].len -= diff;
//		}
//		if (diff < 0) {
//			if (a[l].x != a[r].x) {
//				ans -= diff;
//			}
//			a[l].len += diff;
//		}
//
//		while (pos < neg) {
//			if (a[l].x != a[r].x) {
//				ans += min(a[l].len, a[r].len);
//
//			}
//			pos += a[l].len;
//			l++;
//		}
//		diff = pos - neg;
//		if (diff > 0) {
//			if (a[l].x != a[r].x) {
//				ans += diff;
//			}
//			a[r].len -= diff;
//		}
//		if (diff < 0) {
//			if (a[l].x != a[r].x) {
//				ans -= diff;
//			}
//			a[l].len += diff;
//		}
//
//
//		while (pos > neg) {
//			if (a[l].x != a[r].x) {
//				ans += min(a[l].len, a[r].len);
//			}
//			neg += a[r].len;
//			r++;
//		}
//		diff = pos - neg;
//		if (diff > 0) {
//			if (a[l].x != a[r].x) {
//				ans += diff;
//			}
//			a[r].len -= diff;
//		}
//		if (diff < 0) {
//			if (a[l].x != a[r].x) {
//				ans -= diff;
//			}
//			a[l].len += diff;
//		}
//
//
////3 2 a 2 b 1 c
//
//	}
//	cout << ans;
//
//
//	return 0;
//}
#include <bits/stdc++.h>
using namespace std;
#define ll long long
string a;
ll n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		ll t1;
		char t2;
		cin >> t1 >> t2;
		for (int j = 1; j <= t1; j++) {
			a += t2;
		}
	}
	//cout << a;
	ll ans = 0;
	for (int i = 0, j = a.length() - 1; i < j; i++, j--) {
		if (a[i] != a[j]) {
			ans++;
		}
	}
	cout << ans;

	return 0;
}





//
//#include <bits/stdc++.h>
//using namespace std;
//#define ll long long
//ll n;
//const ll N = 2e5 + 10;
//struct stu {
//	ll len;
//	char x;
//} a[N];
//
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	freopen("string6.in", "r", stdin);
//	//freopen("string.out", "w", stdout);
//
//	cin >> n;
//	ll l = 1, r = 1;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i].len >> a[i].x;
//	}
//	ll id1 = 1, id2 = n;
//	ll ans = 0;
//	while (l <= r) {
//		l += a[id1].len;
//		r += a[id2].len;
//		if (a[id1].x != a[id2].x) {
//			ans += min(a[id1].len, a[id2].len);
//		}
//		id1++;
//		id2++;
//		while (l < r) {
//			l += min(a[id1].len, a[id2].len);
//			if (a[id1].x != a[id2].x) {
//				ans += min(a[id1].len, a[id2].len);
//			}
//
//		}
//	}
//	return 0;
//}