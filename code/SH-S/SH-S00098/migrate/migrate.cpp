#include <bits/stdc++.h>

using namespace std;

int n, d;
int x[2000005];

void solve() {
    cin >> n >> d;
    
    // target, distance
    vector<vector<pair<int, int>>> rr;
    rr.resize(n);
    
    for (int k = 1; k <= n; ++k) {
        cin >> x[k];
        
        for (int j = k - 1; j >= 1; --j) {
            int dd = x[k] - x[j];
            
            if (dd > d) break;
            rr[j].push_back({k, dd});
        }
    }
    
    
    
    cout << "-------------" << endl;
}

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t;
    
    cin >> c >> t;
    
    for (int _ = 0; _ < t; ++_) {
        solve();
    }

    cout << 1 << endl;
    cout << 2 << endl;
}
