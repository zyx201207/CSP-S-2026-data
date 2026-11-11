#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6;
typedef long long ll;
ll len, n, cnt, sum;
pair<ll, int> a[maxn];
int ans[maxn];

void jw(int u) {
	while (ans[u] >= 10) {
		ans[u] = ans[u] % 10;
		ans[u + 1] ++;
		if (len < u + 1)
			len = u + 1;
		u++;
	}
}

void gjd(ll num) {
//	cout << "))))))" << num << "{{{{{{";
	int zb = 0, base = 10;
	while (num) {
		int numm = num % 10;
		ans[++zb]  += numm;
		if (ans[zb] >= 10)
			jw(zb);
		num /= 10;
		if (zb > len)
			len = zb;
	}
}

void ret(ll nusss) {
	gjd((ll)nusss / (ll)2);
}



int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);


	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		ll num;
		char c;
		scanf("%lld %c", &num, &c);
		a[i] = {num, c - '0'};
	}
	if (n == 1) {
		cout << 0;
		return 0;
	} else if (n == 2) {
		if (a[1].second != a[2].second)
			cout << min(a[1].first, a[2].first);
		else
			cout << 0;
		return 0;
	}
	ll l = 1, r = n;
	while (n - cnt > 1) {
		ll lnum = a[l].first, rnum = a[r].first;
		int lc = a[l].second, rc = a[r].second;
//		cout << lc << "  " << rc << "   %%%%%%";
		if (lc == rc) {
//			cout << "))))";
			if (lnum > rnum) {
				cnt++;
				r--;
				a[l].first -= rnum;
			} else if (lnum < rnum) {
				cnt++;
				l++;
				a[r].first -= lnum;
			} else {
				cnt += 2;
				a[l].first = 0;
				a[r].first = 0;
				l++;
				r--;
			}
			continue;
		}
		//=======================================================
		if (lnum > rnum) {
//			cout << lnum << "  " << rnum << "   " << "***";
			cnt++;
			r--;
			a[l].first -= rnum;
			gjd( rnum);
		} else if (lnum < rnum) {
			cnt++;
			l++;
			a[r].first -= lnum;
			gjd(lnum);
		} else {
			cnt += 2;
			a[l].first = 0;
			a[r].first = 0;
			l++;
			r--;
			gjd(rnum);
		}
	}

//	cout << cnt;
	for (int i = 1; i <= len; i++) {
		if (ans[i] >= 10)
			jw(i);
	}
	for (int i = len; i >= 1; i--) {
		cout << ans[i];
	}
	return 0;
}