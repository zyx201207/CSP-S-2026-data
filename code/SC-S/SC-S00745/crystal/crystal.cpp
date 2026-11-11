#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 5e5;
const ll inf = 1e18;
namespace Elaina {
	int n;
	ll a[maxn + 5],m;
	ll sum[maxn + 5];
	ll f(int l,int r,int c) { // [l,r] 选取中心为 c 的答案
		ll l1 = c - l + 1,l2 = r - c;
		return (sum[r] + sum[l - 1] - 2ll * sum[c]) + (l1 - l2) * a[c];
	}
	bool check(int l,int r) { // 检查区间 [l,r] 是否可行
		return f(l,r,r) <= m;
	}
	void main() {
		cin >> n >> m;
		for (int i = 1;i <= n;i ++) cin >> a[i];
		sort(a + 1,a + n + 1);
		sum[0] = 0ll;
		for (int i = 1;i <= n;i ++) sum[i] = sum[i - 1] + a[i];
//		for (int i = 1;i <= n;i ++) cout << "c = " << i << ": f(1,n,c) = " << f(1,n,i) << "\n";
		int ans = 1,l = 1; // 当前选取的 l
		for (int r = 2;r <= n;r ++) {
			// 加入 r 的影响-> c 左移
			while (l < r && !check(l,r)) l ++;
			ans = max(ans,r - l + 1);
		}
		cout << ans << "\n";
	}
}
int main() {
	ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr);
	freopen("crystal.in","r",stdin),freopen("crystal.out","w",stdout);
	Elaina::main();
	return 0;
}