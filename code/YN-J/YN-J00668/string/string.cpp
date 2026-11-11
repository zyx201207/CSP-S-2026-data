#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 2e5 + 7;
int n, tot;
int targ;
int l, r = tot, ans = 0;
int tx, mid;

struct node {
	int f, t, len;
	char p;
} a[N];

int check_ans(int x, int y, char z) {
	int x1, y1;
	for (int i = targ; i <= n + 1; i++)
		if (a[i].f <= x && a[i].t >= x)
			x1 = i;

	for (int i = targ; i <= n + 1; i++)
		if (a[i].f <= y && a[i].t >= y)
			y1 = i;
//	cout << x1 << " " << y1;
	if (x1 == y1 && (z != a[x1].p)) {
		return y - x + 1;
	}

	int res = 0;
	if (abs(x1 - y1) > 1) {
		for (int i = x1; i <= y1; i++) {
			if (z != a[i].p)
				res += a[i].len;
		}
	}
	if (z != a[x1].p)
		res += a[x1].t - x + 1;
	if (z != a[y1].p)
		res += y - a[y1].f + 1;
	return res;

}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	a[0].t = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		char y;
		cin >> x >> y;
		tot += x;//第i段是长度为len的，f位开始t位结束，字母为p
		a[i].len = x;
		a[i].f = a[i - 1].t + 1;
		a[i].t = a[i].f + a[i].len - 1;
		a[i].p = y;

	}
	tx = 1, mid = tot / 2 + (tot % 2);
	//对称中心在第targ段
	for (int i = 1; i <= n; i++) {
		if (a[i].f <= mid && a[i].t >= mid) {
			targ = i;
			break;
		}
	}
	a[n + 1].p = a[n].p;
	for (int i = n; i >= targ; i--) {
		a[i + 1].t = a[i].t;
		a[i + 1].f = a[i].f;
		a[i + 1].len = a[i].len;
		a[i + 1].p = a[i].p;
		if (tot % 2 == 0) {
			a[i + 1].t++;
			a[i + 1].f++;
		}
	}
//	cout << mid << "  " << targ << endl;
	if (tot % 2 == 0) {
		a[targ + 1].p = '#';
		a[targ + 1].f = a[targ].t + 1;
		a[targ + 1].t = a[targ + 1].f;
	} else {
		a[targ + 1].t = a[targ + 1].f = a[targ].t;
		a[targ].t--;
		a[targ].len--;
	}


	//更新左右区间
	r = tot;
	for (int i = 1; i < targ + 1; i++) {
		l = r - a[i].len + 1;
		ans += check_ans(l, r, a[i].p);
		r = l - 1;
	}
	cout << ans;
	return 0;
}
