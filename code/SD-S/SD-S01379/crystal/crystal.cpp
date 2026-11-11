//#include<bits\stdc++.h>
#include<bits/stdc++.h>
using namespace std;
/*====================*/
using lnt = long long;
using pii = pair<int, int>;
/*====================*/
const int INF = 0x3F3F3F3F;
const lnt LNF = 0x3F3F3F3F3F3F3F3F;
/*====================*/
bool Check(int x, lnt m, int mid, vector<lnt>& pre) {
	int len = x - mid;
	return (pre[x] - pre[x - 1]) * len - (pre[x - 1] - pre[mid - 1]) <= m;
}

int Find(int x, lnt m, vector<lnt>& pre) {
	int l = 1, r = x, ans = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (Check(x, m, mid, pre)) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return x - ans + 1;
}

void Solve() {
	int n; lnt m; cin >> n >> m;
	
	vector<lnt> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	sort(a.begin() + 1, a.end());
	vector<lnt> pre(n + 1);
	for (int i = 1; i <= n; i++)
		pre[i] = pre[i - 1] + a[i];
		
	int ans = 1;
	for (int i = 2; i <= n; i++) 
		ans = max(ans, Find(i, m, pre));
	cout << ans << '\n';
}

// int mian() {
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	//freopen("crystal.in", "r", stdin);
	//freopen("crystal.out", "w", stdout);
	//freopen("crytsal.in", "r", stdin);
	//freopen("crytsal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T = 1; //cin >> T;
	while (T--) Solve();
	return 0;
}
// 14:52
