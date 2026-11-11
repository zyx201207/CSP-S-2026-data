// RP ++;
// by MLE_Automaton
// subscribe MLE_Automaton please
// jodio9 yao bao sha wo le
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a),END##i=(b);i<=END##i;++i)
#define pre(i,a,b) for(int i=(a),END##i=(b);i>=END##i;--i)
#define pb push_back
using namespace std;
typedef long long ll;
template<typename T> inline void chmin(T &x, T y) { x = min(x, y); }
template<typename T> inline void chmax(T &x, T y) { x = max(x, y); }
// 20 min T1! Wow!
// difficulty prediction: yellow
constexpr int N = 5e5 + 5;
int n, ans; ll m, a[N], s[N];
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	rep(i, 1, n) scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	rep(i, 1, n) s[i] = s[i - 1] + a[i];
	rep(i, 1, n)
	{
		int l = 0, r = i;
		while (l < r)
		{
			int mid = (l + r) >> 1;
			if ((i - mid) * a[i] - (s[i] - s[mid]) <= m) r = mid;
			else l = mid + 1;
		}
		chmax(ans, i - l);
	}
	printf("%d\n", ans);
	return 0;
}

