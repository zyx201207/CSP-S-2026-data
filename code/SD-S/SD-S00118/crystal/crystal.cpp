#include <bits/stdc++.h>
using namespace std;

#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define fore(x, v) for(const auto& x : (v))
#define trav(x, v) for(auto& x : (v))
#define pb push_back
#define fi first
#define se second
#define bug(x) do{ cout << #x << ':' << x << '\n'; }while(0)

using ll = long long;
using pii = pair<int, int>;

template<class T> inline bool chmax(T& a, T b) { if(a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if(a > b) { a = b; return 1; } return 0; }

const int N = 5e5 + 7;
int n;
ll m, b[N], a[N], s[N], s1[N];

ll gt(int l, int r) {
	return s1[r] - s1[l - 1] - s[l - 1] * (r - l + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	rep(i, 1, n) cin >> b[i];
	sort(b + 1, b + n + 1);
	for(int i = 1, j = n; i < j; i++, j--) swap(b[i], b[j]);
	b[0] = b[1];
	rep(i, 1, n) s[i] = s[i - 1] + b[i - 1] - b[i], s1[i] = s1[i - 1] + s[i];	
	int ans = 0, pr = 0;
	rep(i, 2, n) {
		chmax(pr, i - 1);
		while(pr < n && gt(i, pr + 1) <= m) pr++;
		chmax(ans, pr - i + 2);
	}
	cout << ans << '\n';
	
	return 0;
}
