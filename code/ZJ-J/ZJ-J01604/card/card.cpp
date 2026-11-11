#include <bits/stdc++.h>

#define int long long
#define PII pair <int, int>

using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector <int> a(n), now;
    map <int, int> res;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int start = 0; start < n; start++) {
        now.clear(); 

        for (int i = start; i < n; i++) {
        	int it = now.size() - 1, rlast = now.size() - 1;
            for (int j = 0; j < now.size(); j++) 
				if (now[j] == a[i]) {
	        		it = j - 1;
					break;	
				}
			for (int last = rlast; last > it; last--)
				now.pop_back();
			now.push_back(a[i]);
//			for (int i = 0; i < now.size(); i++) 
//        		cout << now[i] << ' ';
//        	cout << '\n';
        }
        
        for (auto i : now)
            res[i] += 1;
    }
    for (int i = 1; i <= m; i++) {
        if (res.count(i)) cout << res[i] << ' ';
        else cout << 0 << ' ';
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}