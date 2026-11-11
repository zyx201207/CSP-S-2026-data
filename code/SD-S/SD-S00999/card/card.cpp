#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = a; i >= b; --i)
const int maxn = 5e5 + 5;
const int maxm = 3e5 + 5;
const int inf = 0x3f3f3f3f3f3f3f3f;
const int start = (1 << 30) - 1;
int n, m, a[maxn], ans[maxm];
namespace djrsnamespace {
	bool pan() {
		bool flg = 1;
		rep(i, 1, n-1) {
			flg &= (a[i] <= a[i+1]);
		}
		return flg;
	}
	void solve() {
		rep(i, 1, n) {
			ans[a[i]] = i;
		}
	} 
}
signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	rep(i, 1, n) {
		cin >> a[i];
//		cout << num[i] << ' ';
	}
//	cout << endl;
	if (djrsnamespace::pan()) {
		djrsnamespace::solve();
	} else {
		rep(game, 1, n) {
			vector<int> vec;
			rep(i, game, n) {
				vector<int>::iterator it1 = find(vec.begin(), vec.end(), a[i]), it2 = vec.begin();
				vec.resize((int) (it1 - it2));
				vec.push_back(a[i]);
			} for (int x : vec) {
				++ans[x];
			}
		} 
	}
	rep(i, 1, m) {
		if (i == m) {
			cout << ans[i];
			return 0;
		}
		cout << ans[i] << ' ';
	}
}
/*
//freopen
frepoen
froepen
SD-S00999¼À¡£
goal£ºJ 300+, S 1= 
ÍËÒÛ¿ìÀÖ£¡
password£º Trick||Treat!
O(n^2)µÄ¡£48pts¡£
100+100+85+40 = 325 
*/
