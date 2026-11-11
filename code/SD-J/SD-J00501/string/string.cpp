#include <bits/stdc++.h>
typedef long long ll;
const int N = 2e5 + 5;
#define endl '\n'

using namespace std;

struct plc {
	ll x;
	char c;
};

int n;

int main () {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	vector <plc> a (n), _a (n);
	vector <ll> prei (n), prej (n);
	for (auto & _ : a) cin >> _.x >> _.c;
	for (int i = 0; i < n; ++i) {
		int j = n - i - 1;
		_a[j] = a[i];
	}
	for (int i = 0; i < n; ++i) {
		ll pref = (i == 0 ? 0 : a[i - 1].x);
		prei[i] = pref + a[i].x;
		pref = (i == 0 ? 0 : _a[i - 1].x);
		prej[i] = pref + _a[i].x;
	}
	ll i = 0, j = 0, posi = 0, posj = 0, ans = 0;
	// ij组，pos组内位置，ans 
	while (i < n && j < n) {
		ll u = (i == 0 ? 0 : prei[i - 1]); // i曾经的完整段 
		ll v = (j == 0 ? 0 : prej[j - 1]); // j曾经的完整段 
		ll idxi = u + posi, idxj = v + posj; // ij总位置 
		ll diffi = a[i].x - posi, diffj = _a[j].x - posj; // 距离此完整段结束还有 
		ll munn = min(diffi, diffj);
		if (a[i].c != _a[j].c) {
			ans += munn;
		}
		posi += munn, posj += munn;
		if (posi == a[i].x) i++, posi = 0;
		if (posj == _a[j].x) j++, posj = 0;
	}
	cout << ans / 2 << endl;
	return 0;
}
/*
  3
  2 a
  2 b
  1 c
*/
