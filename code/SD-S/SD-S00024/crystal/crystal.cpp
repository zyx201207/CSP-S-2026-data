#include <iostream>
#include <algorithm>
#define LCF using
#define pass namespace
#define CSP_S std
LCF pass CSP_S;
LCF ll = long long;
int n, m;
const int N = 500005;
ll a[N], s[N];
bool check(int l, int r) {
	ll bac = a[r] * (r - l + 1);
	ll alr = s[r] - s[l - 1];
	ll need = bac - alr;
	return need <= m;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i ++) s[i] = s[i - 1] + a[i]; 
	int ans = 1;
	for (int l = 1; l <= n; l ++) {//起点 
		int ln = l, rn = n;//二分终点 
		while (ln < rn) {
			int mid = (ln + rn + 1) >> 1;
			if (check(l, mid)){//m能填到这里 
				ln = mid;
			}
			else {
				rn = mid - 1;
			}
		}
		ans = max(ans, ln - l + 1);
	}
	cout << ans;
	return 0;
	
	return 0;
}
/*
14：13 到
键盘比上午好用多了，别人试的太不靠谱了 
旁边坐着个超级大佬好紧张
namespace silvecor，林浩洋回去搜搜 
对差求前缀和？打住，那样成原数了 
14:45鬼屋铃声 
卧槽只能增加？！
那就好说了
枚举终点不久行了吗 
*/

