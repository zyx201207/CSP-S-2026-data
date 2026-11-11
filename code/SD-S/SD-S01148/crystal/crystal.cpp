#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 5e5 + 10;

ll n, a[N], m, s[N];

ll cost(ll i, ll j) {
	ll res = a[j] * (j - i + 1) - (s[j] - s[i - 1]);
	return res;
}

bool check(ll mid) {
	for (ll i = 1; i + mid - 1 <= n; i ++) {
		if (cost(i, i + mid - 1) <= m) return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	cin >> n >> m;
	for (ll i = 1; i <= n; i ++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (ll i = 1; i <= n; i ++) s[i] = s[i - 1] + a[i];
	
	ll l = 1, r = n;
	while (l < r) {
		ll mid = l + r + 1 >> 1;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	cout << l << endl;
	return 0;
}

// 答案有单调性 

// 氧化钙 我是【数据删除】
// 我读假题了 我以为可以减1
// 糖丸了

// 20min 我是人啊

// 可以上迷惑行为大赏了   <- 球球了 

// 18:15 算了 懒得拍了
// 我没写暴力 感觉这题不难 我就不拍了
// 而且我不会自动化对拍（ 


// 加油 相信自己
// 只要能过掉 T1 就行
// RP ++ for Cute_zsz（洛谷名） 


// 上午那个写歌词的也是我 

