#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5, V = 31;
int n, m, a[N];
bool mk[N][V];
typedef long long ll;
ll ans = 0;
vector<int> ch;
bool chd[N];
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i=1; i<=n; ++i) {
		cin >> a[i];
	}
	for(int i=0; i<=30; ++i) {
		for(int j=1; j<=n; ++j) {
			int base = (1 << i);
			if(a[j] & base) mk[j][i] = 1;
		}
	}
	for(int i=30; i>=0; --i) {
		for(int j=1; j<=n; ++j) {
			if(!chd[j] && mk[j][i] && ch.size() < m) {
				chd[j] = 1, ch.push_back(j);
			}	
		}
	}
	/*
	5 3
	31 3 1 15 7
	*/
	ans = a[ch[0]];
	for(int i=1; i<ch.size(); ++i) {
		ans = (ans & a[ch[i]]);
	}
	cout << ans << '\n';
	return 0;
}
