#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = a; i >= b; --i)
const int maxn = 5e5 + 5;
const int inf = 0x3f3f3f3f3f3f3f3f;
int n, m, ans = -inf, a[maxn], sum[maxn];
signed main() {
//	freopen("crystal.in", "r", stdin);
//	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	rep(i, 1, n) {
		cin >> a[i];
	}
	sort(a+1, a+1+n);
	rep(i, 1, n) {
		sum[i] = sum[i-1] + a[i];
		int j = i;
		while (j < n and a[j] == a[j+1]) {
			++j;
		}
		int l = 1, r = i-1;
		// 特判[1,i-1]
		if (abs(sum[r] - sum[l-1] - (r-l+1) * a[i]) <= m) {
			ans = max(ans, r-l+1+j-i+1);
		} else {
			l = 2, r = i-1;
			while (!(abs(sum[r] - sum[l-1] - (r-l+1) * a[i]) <= m and abs(sum[r] - sum[l-2] - (r-l+2) * a[i]) > m)) {
				if (abs(sum[r] - sum[l-1] - (r-l+1) * a[i]) <= m) {
					
						l = (2 + l + 1) >> 1;
					
				} else {
						l = (l + r + 1) >> 1;
				}
			}
			ans = max(ans, r-l+1+j-i+1);
		}
	}
	cout << ans;
} 
/*
//freopen
frepoen
frpoene
退役快乐！
SD-S00999祭。
owo qwq TwT ovo qvq TvT o_o q_q T_T qoq ToT
password:  
差点忘了在代码里用那种语言会被休息三年了。——at 18:21 
很明显做这个一定要先sort。这样好做一些。 
-3 -1 2 2 7
对于每一个i，先知道哪一段等于i。
然后开始维护1~i-1。 
*/
