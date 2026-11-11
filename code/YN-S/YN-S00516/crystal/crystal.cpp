#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 5e5 + 5;
ll n, m;
ll a[MAXN];

bool check(int mid) {
	int cz = 0;
	for (int i = 1; i < mid; i++) {
		cz += (a[mid] - a[i]);
	}
	return cz <= m;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	sort(a + 1, a + 1 + n);
	int l = 1;
	for (int i = 1; i <= n; i++) {
		if (a[i] - a[i - 1] > m / n + 1)
			l = i;
	}
	int ans = 0;
	int r = n;
	while (l < r) {
		int mid = (l + r) >> 1;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	cout << ans;
	return 0;
}
//本人也是非常有辛过了S组初赛
//但我是条区，只会T1还做不对，
//但多半不会爆零
//故今晚夜色入户，悻然打粥，念无与三排者，遂至隔壁寻队友
//队友亦未寝，相与步于机坝，电脑如炭火炙热，屏幕上枪林弹雨

//神秘luoguID : lou004