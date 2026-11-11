#include <iostream>
#include <cmath>
#define LCF using
#define AK namespace
#define CSP_J std
LCF AK CSP_J;
LCF ll = long long;
const int N = 200005;
int n;
ll a[N], s[N];
char c[N];
ll ch(ll l1, ll l2, ll r1, ll r2) {
	//l包含于r 
	if (l1 >= r1 && l2 <= r2) return l2 - l1 + 1;
	//r包含于l 
	if (l1 <= r1 && l2 >= r2) return r2 - r1 + 1;
	//l在左
	if (l1 <= r1 && l2 <= r2) return l2 - r1 + 1;
	//r在左 
	return r2 - l1 + 1; 
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	ll sum = 0;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i] >> c[i];
		sum += a[i];
		s[i] = s[i - 1] + a[i];
	}
	int l = 1, r = n;
	ll ans = 0;
	while (l < r) {
		//首先把右边的映射到左边来
		ll l1 = s[l - 1] + 1, l2 = s[l];
		ll r1 = s[r], r2 = s[r - 1] + 1;//跟l的编排是反的因为待会要往左边映射
		r1 = sum - r1 + 1, r2 = sum - r2 + 1;//对就是这个
		//左右端点的差值就是要修改的个数
		if (c[l] != c[r]) {
			ans += ch(l1, l2, r1, r2);//重合的部分 
		}
//		cout << l << ' ' << r << ' ' << ans << '\n';
		if (l2 == r2) {
			l ++, r --;
		}
		else if (l2 > r2) {
			r --;
		}
		else {
			l ++;
		}
	}
	cout << ans;
	return 0;
}
/*
8:48 打完T2框架
外国语好鬼畜的铃声 
咋做
双指针
按常理这题就应该是个模拟
那就写 
十年OI一场空，_______
但愿小何不会犯傻 
8:55 又来鬼屋铃声 
如果是
l  ----
r ---
那就r往前
如果
l----
r   --
那就l往前
如果
l-----
r -- 
那就r往前
所以这个是根据结尾看的 
那如果完全重合？那就都往前呗 
//9:13写完 
*/
