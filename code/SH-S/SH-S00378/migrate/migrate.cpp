#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void FileIO(const char * inf, const char * ouf) {
	freopen(inf, "r", stdin);
	freopen(ouf, "w", stdout);
}

constexpr int MAXN = 2000010;

int n;
ll d;
ll x[MAXN], dpzl[MAXN];
pair<ll, ll> dp[MAXN];

pair<ll, ll> seg[8000010];

pair<ll,ll> unite(pair<ll,ll> X, pair<ll,ll> Y) {
	if (X.first == Y.first) {
		return {X.first, X.second + Y.second};
	} else if (X.first < Y.first) {
		return X;
	} else {
		// >
		return Y;
	}
}

void push_up(int id) {
	seg[id] = unite(seg[id<<1], seg[id<<1|1]);
}

void build(int L, int R, int id) {
	if (L == R) {
		seg[id] = dp[L];
		return;
	}
	int mid = (L + R) >> 1;
	build(L, mid, id<<1);
	build(mid+1, R, id<<1|1);
	push_up(id);
}

void change(int L, int R, int id, int pos, pair<ll,ll> val) {
	if (L == R) {
		seg[id] = val;
		return;
	}
	int mid = (L + R) >> 1;
	if (pos <= mid) change(L, mid, id<<1, pos, val);
	else change(mid+1, R, id<<1|1, pos, val);
	push_up(id);
}

pair<ll,ll> query(int L, int R, int id, int l, int r) {
	if (l > r) {
		return {1ll<<60, 0};
	}
	if (l <= L && R <= r) {
		return seg[id];
	}
	int mid = (L + R) >> 1;
	if (r <= mid) return query(L, mid, id<<1, l, r);
	else if (l > mid) return query(mid+1, R, id<<1|1, l, r);
	return unite(query(L, mid, id<<1, l, r), query(mid+1, R, id<<1|1, l, r));
}

void solve() {
	cin>>n>>d;
	for (int i=1;i<=n;i++) {
		cin>>x[i];
		int l = 0, r = i;
		while (l + 1 < r) {
			int mid = (l + r) >> 1;
			if (x[i] - x[mid] <= d) r = mid;
			else l = mid;
		}
		dpzl[i] = r;
	}
	// for (int i=1;i<=n;i++) cout<<dpzl[i]<<" \n"[i==n];
	
	ll ans = 0;
	for (int S = 1; S <= n; S++) {
		for (int i=1;i<=n;i++) dp[i]={1ll<<60, 0};
		dp[S] = {0, 1}; 
		build(1, n, 1);
		for (int i=S+1;i<=n;i++) {
			pair<ll,ll> rt = query(1, n, 1, dpzl[i], i-1);
			rt.first += 1;
			dp[i] = rt;
			change(1, n, 1, i, rt);
		}
		// for (int i=1;i<=n;i++) cout<<((dp[i].first < (1<<30))?dp[i].first:-1)<<","<<dp[i].second<<" \n"[i==n];
		for (int i=1;i<=n;i++) if (dp[i].first < (1<<30) && dp[i].second == 2) ans++;
	}
	cout<<ans<<endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	FileIO("migrate.in", "migrate.out");
	int c, T;
	cin>>c>>T;
	while (T--) solve(); 
	return 0;
}
