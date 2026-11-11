#include <unordered_map>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long ll;

const ll maxn = 5e5 + 5;
void AB();
ll Read() {
	char c;
	ll num = 0, f = 1;
	c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') {
			f = -1;
		}
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		num = num * 10 + (c - '0');
		c = getchar();
	}
	return num * f;
}

unordered_map<ll, ll> s;
ll n, nn, mm;
pair<ll, ll> arr[maxn];
void Input() {
	nn = Read(), mm = Read();
	for (int i = 1; i <= nn; ++i) {
		ll z;
		z = Read();
		if (s.count(z) == true) {
			++arr[s[z]].second;
		} else {
			++n;
			arr[n].first = z;
			arr[n].second = 1;
		}
	}
	
	if (nn > 5000) {
		AB();
		return;
	}
	
	return;
}

ll Get(int p) {
	ll res = arr[p].second, m = mm;
	for (int i = p - 1; i > 0; --i) {
		ll w = arr[p].first - arr[i].first;//单个的代价
		ll cost = w * arr[i].second;//最大总代价
		
		if (m < w) {
			return res;
			/*连一个都得不到*/
		}
		if (m > cost) {
			m -= cost;
			res += arr[i].second;
		} else if (m == cost) {
			return (res + arr[i].second);
		} else {
			/*能得到一些，但不能全部得到*/
			ll l = 1, r = arr[i].second - 1, su;
			while (l <= r) {
				ll mid = (l + r) >> 1;//能得到mid个吗？
				ll tcost = w * mid;
				if (m >= tcost) {
					su = mid;
					l = mid + 1;
				} else {
					r = mid - 1;
				}
			}
			return (res + su);
		}
	}
	return res;
}

ll ans;
void Solve() {
	sort(arr + 1, arr + n + 1);
	for (int i = 1; i <= n; ++i) {
		ans = max(ans, Get(i));
	}
	return;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	Input();
	Solve();
	printf("%lld", ans);
	return 0;
}

void AB() {
	sort(arr + 1, arr + n + 1);
	ans = Get(n);
	return;
}

/*
[14:40]
显然，如果我想要得到最优解需要贪心一下——最终操作以后合成的数字一定是原有的数字中的一个，不用证明。
那么我们可以先尝试暴力枚举每一个原来有的数字作为答案。

[14:41]
样例全是升序输入，但是题目没有说，我们需要先排序一下。

[15:02]
arr[i].first 原元素的值
arr[i].second这个元素的个数

[15:19]
过样例1，耶~~~
[15:20]
过样例2，耶~~~
[15:24]
样例1,2,3都过了，样例4 TLE。俺不得劲儿~
让我想想，嗯，如果重复某一个位置的数特别多那么就会卡成n^2，所以可以二分数量优化一下。
还有可能就是要快读快写？

[15:47]
二分 + 快读快写写完了， 样例4还是不行（我是不会告诉你我快读快写写错的）

[16:59]
想不出来正解，其它题除了T3想暴力其它都不会。回来看一眼性质AB能得分，现在应该75pts了。（机器你看我那么可怜，给点分呗）
*/
//来吧，选一条向死之外的路。
//OTOI2026