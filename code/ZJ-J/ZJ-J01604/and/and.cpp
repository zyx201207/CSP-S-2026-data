#include <bits/stdc++.h>

#define int long long
#define PII pair <int, int>

using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    vector < vector<int> > bits(n + 1, vector <int> (35, 0));
    for (int i = 0; i < n; i++) for (int j = 1; j < 35; j++) 
        bits[i][j] = ( (a[i] >> (j - 1)) & 1);
    
//    for (int i = 0; i < n; i++) { 
//		for (int j = 1; j < 35; j++) 
//    		cout << bits[i][j] << ' ';
//    	cout << '\n';
//	}
	
    set <int> pos;
    for (int i = 0; i < n; i++) 
        pos.insert(i);
    for (int j = 34; j >= 1; j--) {
        if (pos.size() == m) continue;
        int cnt = 0;
        for (int i : pos) cnt += bits[i][j];
//        cout << cnt << '\n';
        if (cnt >= m) {
            auto newpos = pos;
            for (auto i : newpos) if (bits[i][j] == 0)
            	pos.erase(i);
        }
    }
    int res = (1ll << 34) - 1;
    for (auto i : pos) res = res & a[i];
    cout << res << '\n';
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}