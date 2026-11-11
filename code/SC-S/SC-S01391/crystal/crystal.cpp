# include <bits/stdc++.h>
# define int LL
# define fr front
# define fir first
# define sec second
# define vec vector
# define lb lower_bound
# define ub upper_bound
# define all(x) x.begin(), x.end()
# define mem(a, b) memset(a, b, sizeof(a))

# define ls(p) (p << 1)
# define rs(p) (p << 1 | 1)
# define lson ls(p), l, mid
# define rson rs(p), mid + 1, r

# define sqr(x) ((x) * (x))
# define geti(x, i) (((x) >> (i)) & 1)
# define set1(x, i) ((x) | (1 << (i)))
# define set0(x, i) ((x) & (~(1 << (i))))

# define each1(x, a) for(auto x : a)
# define each2(x, a) for(auto &x : a)
# define rep(i, a, b) for(int i = (a); i <= (b); ++ i)
# define pre(i, a, b) for(int i = (a); i >= (b); -- i)
using namespace std;

using DB = double;
using LL = long long;
using LDB = long double;
using PII = pair<int, int>;
using ULL = unsigned long long;

const int N = 5e5 + 10;
const int INF1 = 0x3f3f3f3f, INF2 = INT_MAX;
const LL INF3 = (LL)1e18, INF4 = 0x3f3f3f3f3f3f3f3f, INF5 = LLONG_MAX;

int n, m, ans;
int a[N], sum[N];

bool check(int l, int r){
	if(sum[r - 1] - sum[l - 1] + m >= a[r] * (r - l)) return true;
	return false;
}

signed main(){
//	freopen("crystal4.in", "r", stdin);
//	freopen("my.out", "w", stdout);
//# ifndef LOCAL
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
//# endif
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	rep(i, 1, n) cin >> a[i];
	sort(a + 1, a + 1 + n);
	rep(i, 1, n) sum[i] = sum[i - 1] + a[i];
	rep(i, 1, n){
		int l = 1, r = i;
		while(l < r){
			int mid = l + r >> 1;
//			cerr << l << " " << mid << " " << r << "\n";
			if(check(mid, i)) r = mid;
			else l = mid + 1;
		}
		
		ans = max(ans, i - l + 1);
	}
	
	cout << ans;
	
	return 0;
}
/*
5 5
1 2 4 8 9

3
*/
/*
5 8
-3 -1 2 2 7

4
*/