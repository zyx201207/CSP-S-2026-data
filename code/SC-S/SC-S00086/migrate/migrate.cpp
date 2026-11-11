/*
希望出题人不要搞非完全联通的情况
感觉会炸得很惨
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c, tim, n, d;
const ll maxn = 4e6+10;
ll a[maxn];
ll f_consider_lst[maxn];
ll from_end_tim[maxn];//不包含自己 注意！！
ll nxt_idx[maxn];//d区域以内的最大编号
ll ans = 0;
void init() {
	for (ll i = 1; i <= n; i++)f_consider_lst[i] = 0, from_end_tim[i] = 0, nxt_idx[i] = 0;
	ans = 0;
}
void get_from_end_tim() {
	ll fstpot = n, secpot = n;
	for (ll i = n - 1; i >= 2; i--) {
		while (a[fstpot] - a[i] > d)fstpot--;
		while (a[secpot] - a[i - 1] > d)secpot--;
		if (fstpot != secpot)from_end_tim[i] = from_end_tim[fstpot] + fstpot - secpot;
		else from_end_tim[i] = 0;
	}
}
void get_nxt_idx() {
	ll pot = n;
	for (ll i = n; i >= 1; i--) {
		while (a[pot] - a[i] > d)pot--;
		nxt_idx[i] = pot;
	}
}
void solve() {
	cin >> n >> d;
	for (ll i = 1; i <= n; i++)cin >> a[i];
	init();
	get_from_end_tim();
	get_nxt_idx();
	for (ll i = n - 3; i >= 1; i--) {//计算他作为分叉点或准分叉点的利益
		ll nxt = nxt_idx[i];
		if (nxt - i >= 2) {
			ans += nxt_idx[nxt - 1] - nxt_idx[nxt - 2];
			if (nxt_idx[nxt] == nxt_idx[nxt - 1] && nxt_idx[nxt - 1] - nxt_idx[nxt - 2] != 0) {
				ans += from_end_tim[nxt_idx[nxt]];
//				cout << "This:ans: " << ans << " " << i << " " << nxt << " " << nxt_idx[nxt] << "\n";
			}
		}
		ans += f_consider_lst[nxt]; //当前不选，计算后续
		//计算consider
		if (i == 1)break;
		ll res = 0, lst_nxt = nxt_idx[i - 1];
		if (nxt - lst_nxt == 0) {
			f_consider_lst[i] = 0;
			continue;
		}
		if (nxt - lst_nxt >= 2) {
			res += nxt_idx[nxt - 1] - nxt_idx[nxt - 2];
			if (nxt_idx[nxt] == nxt_idx[nxt - 1] && nxt_idx[nxt - 1] - nxt_idx[nxt - 2] != 0) {
				res += from_end_tim[nxt_idx[nxt]];
			}
		}
		res += f_consider_lst[nxt];
		f_consider_lst[i] = res;
	}
	cout << ans << '\n';
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> tim;
	while (tim--) {
		solve();
	}
}
/*
0 1
6 3
0 1 2 3 4 7
*/