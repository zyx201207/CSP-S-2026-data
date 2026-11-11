#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = a; i >= b; --i)
const int maxn = 2e5 + 5;
const int inf = 0x3f3f3f3f3f3f3f3f;
struct node {
	int x;
	char ch;
} q[maxn];
int n; 
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	rep(i, 1, n) {
		cin >> q[i].x >> q[i].ch;
	}
	int l = 1, r = n, ans = 0;
	while (l < r) {
		/*
		如果q[l].x < q[r].x，即l长度小于r长度 
		*/
		if (q[l].x < q[r].x) {
			// 若l与r字符不同
			if (q[l].ch != q[r].ch) {
				// 将l所有改掉。
				ans += q[l].x;
				q[r].x -= q[l].x;
			} else {
				q[r].x -= q[l].x;
			}
			++l;
		} else if (q[l].x > q[r].x) {
			if (q[l].ch != q[r].ch) {
				// 将l所有改掉。
				ans += q[r].x;
				q[l].x -= q[r].x;
			} else {
				q[l].x -= q[r].x;
			}
			--r;
		} else {
			if (q[l].ch != q[r].ch) {
				ans += q[l].x;
				q[l].x = 0;
				q[r].x = 0;
			} else {
				q[l].x = 0;
				q[r].x = 0;
			}
			++l, --r;
		}
	}
	cout << ans;
}
/*
//freopen
frepoen
froepen
SD-S00999祭。
goal：J 300+, S 1= 
退役快乐！
password： Trick||Treat! 
考虑双指针。 
牛逼牛逼，T2就这么做完了。O(n)的。 
*/
