#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e9 + 1;
char s[N];/*







*/
//思路：输入之后，用数字和字符数组存储，之后用l,r指针让第l项和第r项进行对比，一致就l++r--,不一致cnt+=l项和r项的差的绝对值
//bool hw(ll l, ll r) {
//	bool f = 1;
//	while (l <= r) {
//		if (l == r) {
//			f = 1;
//			return true;
//		} else if (s[l] != s[r]) {
//			f = 0;
//			return false;
//		}
//		l++;
//		r--;
//	}
//	if (f) {
//		return true;
//	} else {
//		return false;
//	}
//}
ll cnt = 0;

ll ms[10000001] = {0};

int main() {
	freopen("string.in", "r", stdin);
	freopen("log.out", "w", stdout);

	ll n;

	cin >> n;
	for (ll i = 0; i < n; i++) {
		cin >> ms[i];
		cin >> s[i];
//		cout << ms[i] << s[i];
	}
	ll r = n - 1, l = 0;
	while (l <= r) {
		if (l == r || s[l] == s[r] && l + 1 == r) {
			cout << "Over" << endl;
			break;
		} else if (ms[l] == ms[r] && s[l] == s[r]) {
//			cout << "JUMP" << ms[l]  << ' ' << ms[r] << ' ' << s[l] << ' ' << s[r] << ' ' << l << ' ' << r  << endl;
		} else if (s[r] == s[l]) {
			cout << "uop131"  << ' ' << ms[l]  << ' ' << ms[r] << ' ' << s[l] << ' ' << s[r] << ' ' << l << ' ' << r << endl;
			cnt += abs(ms[l] - ms[r]);
		} else {
			cout << "uop2"  << ' ' << ms[l]  << ' ' << ms[r] << ' ' << s[l] << ' ' << s[r] << ' ' << l << ' ' << r << endl;
			cnt += min(ms[l], ms[r]);
			ms[l + 1] += max(ms[l], ms[r]) - min(ms[l], ms[r]);
//			bool f = 0;
//			cout << "waring" << endl;
//			int k = max(ms[l], ms[r]) - min(ms[l], ms[r]);
//			if (ms[l] > ms[r])
//				f = 1;//l大
//			for (int i = 0; i < n; i++) {
//				if (f) {
//					if (s[i] == s[l])
//						ms[i] += k;
//				} else {
//					if (s[i] == s[r])
//						ms[i] += k;
//				}
//
//			}
		}
		cout << cnt << endl;
		l++;
		r--;
	}
	cout << cnt;
	return 0;
}