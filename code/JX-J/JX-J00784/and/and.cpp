#include <bits/stdc++.h>
#define ts to_string
#define ll long long
using namespace std;

void log(string cont) {
    cout << cont << "\n";
}

vector<bool> binary(ll n) {
    vector<bool> bin;
    while (n > 0) {
        bin.push_back(n&1);
        n >>= 1;
    }
    return bin;
}

signed main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m; cin >> n >> m; m = n-m;
    vector<ll> data(n);
    vector<vector<bool>> bins(n);
    int mxl = 0;
    // log("input start");
    for (int i = 0; i < n; i ++) {
        ll a; cin >> a;
        data[i] = a;
        auto bin = binary(a);
        bins[i] = bin;
        mxl = max(mxl, (int)bin.size());
        // log("round "+ts(i)+", mxl="+ts(mxl));
    }
    // log("input finish, preprocessing binaries");
    for (int i = 0; i < n; i ++) {
        // log("id="+ts(i)+", add "+ts(mxl-bins[i].size()));
        for (int j = 0; j < mxl-bins[i].size(); j ++) {
            bins[i].push_back(0);
        }
    }
    // log("preprocess finish, calc start");
    vector<bool> passed(n, 1);
    for (int i = mxl-1; i >= 0 && m > 0; i --) {
        // log("curr bit="+ts(i));
        vector<int> upsd;
        for (int j = 0; j < n; j ++) {
            if (passed[j]) {
                // log("curr id="+ts(j));
                if (!bins[j][i]) {
                    // log("you failed, thanks!");
                    upsd.push_back(j);
                }
            }
        }
        if (upsd.size() <= m) {
            m -= upsd.size();
            // log("size is less than m, curr m="+ts(m));
            for (int e : upsd) {
                passed[e] = 0;
            }
        }
    }
    // log("calc finish");
    ll tt = -1;
    for (int i = 0; i < n; i ++) {
        if(!passed[i]) continue;
        // log(ts(data[i])+" is survived");
        if (tt == -1) tt = data[i];
        else tt &= data[i];
    }
    cout << tt;
    return 0;
}