#include<bits/stdc++.h>
using namespace std;

#define int long long
using P = pair<int, int>;

const int N = 5e5+5;
int n, m;
int a[N];
int ans[N];
bitset<N>vis;
bitset<N>lif;
stack<P>st;
void bl(int sta) {

	while (!st.empty()) {
		st.pop();
	}
	vis = 0;
	lif = 0;

	for (int i = sta; i <= n; i++) {
		while (vis[a[i]]) {
			vis[st.top().first] = 0;
			lif[st.top().second] = 1;
			st.pop();
		}
		vis[a[i]] = 1;
		lif[i] = 0;
		st.push({a[i], i});
	}
	for (int i = 1; i <= m; i++) {
		ans[i] += vis[i];
	}
}
int lst_in[N];
void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {
		bl(i);
	}

	for (int i = 1; i <= m; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
}

int t_;
signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	t_ = 1;
//	cin>>t_;
	while (t_--) {
		solve();
	}

	cout.flush();

	return 0;
}
