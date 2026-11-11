#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[500005], mmin2 = LONG_LONG_MAX, cnt1, cnt2;

//朝老师别看了写的是错的已经力竭了不想再写了这是我的极限了---2026.10.31 16:40:43
//tmd一个mmin2的重置要了我快一个小时才发现  力竭了T_T  这60行估计还只能过样例，自己编的样例tm一个也过不了wcl我不学了
//感觉自己啥也不会呢说是  还是没好好学
//先睡了今晚要熬夜打游戏^_^---2026.10.31 16:44:27
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	while (m > 0) {
		cnt1 = 0, cnt2 = 0, mmin2 = LONG_LONG_MAX; //cnt1为第一小的个数,cnt2为第二小的个数
		sort(a + 1, a + n + 1); //排序小到大
		for (int i = 1; i <= n; i++) {
			if (a[i] == a[1]) {
				cnt1++;
			}
			if (a[i] <= mmin2 && a[i] != a[1]) {
				mmin2 = a[i];
				cnt2++;
			}
		}//找到第二小的数mmin2
		//cout << cnt1 << " " << cnt2 << "\n";
		if (m >= (mmin2 - a[1]) * cnt1) {//最小数全部变mmin2
			m -= (mmin2 - a[1]) * cnt1;
			for (int i = 1; i <= cnt1; i++) {
				a[i] = mmin2;
			}
		} else if (m < (mmin2 - a[1]) * cnt1) {
			cnt1 -= m;
			cnt2 += m;
			m = 0;
			for (int i = cnt1 + 1; i <= cnt1 + cnt2; i++) {
				a[i] = mmin2;
			}
		}
		/*cout << m << "\n";
		for (int i = 1; i <= n; i++) {
			cout << a[i];
		}
		cout << "\n";*/
	}
	sort(a + 1, a + n + 1);
	int mmaxx = 1, ans = 1;
	for (int i = 2; i <= n; i++) {
		if (a[i] == a[i - 1]) {
			ans++;
		} else {
			if (ans >= mmaxx) {
				/*cout << ans << "\n";*/
				mmaxx = ans;
			}
			ans = 1;
		}
	}
	cout << mmaxx;
	return 0;
}












