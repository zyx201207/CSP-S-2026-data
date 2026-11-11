/*
t1 crystal
 n 颗水晶，
第 i (1 ≤ i ≤ n) 颗的能量值为整数 ai。
用其中若干颗能量水晶合成一颗大水晶
用于合成的水晶必须具有相同的能量值
希望参与合成的水晶尽可能多。
他可以进行至多m 次操作。每次操作可
以任选一颗水晶，将其能量值增加 1
同一颗水晶可以被重复选择。
进行至多 m 次操作后，
最多能用多少颗能量水晶合成

17min EXP Ac
*/

#include <bits/stdc++.h>
using namespace std;
#define _for(i, a, b) for(int i = (a); i <= (b); ++i)
#define _rfo(i, a, b) for(int i = (a); i >= (b); --i)
using LL = long long;
using VI = vector<int>;
const int NN = 5E5 + 5;
LL A[NN];

void solve() {
	int n;
	LL m;
	cin >> n >> m;
	_for(i, 1, n) cin >> A[i];
	sort(A + 1, A + 1 + n);
	int L = 1, R = 1, ans = 1, res = 0, lst = A[1];
	auto Pt = [&]() {
		cout << L << " " << R << "\n";
		_for(i, L, R) cout << A[i] << " ";
		cout << "\n";
	};
//	Pt();
	_for(i, 2, n) {
		LL &ai = A[i];
		res += (R - L + 1) * (ai - lst), ++R, lst = ai;
		while (res > m)
			res -= (ai - A[L]), ++L;
//		Pt();
		ans = max(ans, R - L + 1);
	}
	cout << ans << "\n";
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int T = 1;
//	cin >> T;
	while (T--)
		solve();
	return 0;
}