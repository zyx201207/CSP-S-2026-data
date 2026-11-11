#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5e5 + 5, M = 3e5 + 5;
int n, m;
int arr[N];
int frt[M], T[M], ans[M];

bool check() {
    bool res = 1;
    for (int i = 2; i <= n; ++ i) {
        res &= (arr[i] >= arr[i - 1]);
    }
    return res;
}
bool check2() {
    return m == 2;
}

signed main () {
    ios :: sync_with_stdio (0); cin.tie(0); cout.tie(0);
    freopen ("card.in", "r", stdin);
    freopen ("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i) cin >> arr[i];

    if (check()) {
        for (int i = n; i >= 1; -- i) {
            ans[arr[i]] = max(ans[arr[i]], i);
        }
        for (int i = 1; i <= m; ++ i) cout << ans[i] << ' ';
        return 0;
    }
    if (m == 1) {
        cout << n;
        return 0;
    }
    if (check2()) {
        if (arr[n] == 1) {
            int tans = 0;
            for (int i = 1; i <= n; ++ i) {
                if (arr[i] == 2) tans ++;
            }
            cout << n << ' ' << tans;
        }
        else {
            int tans = 0;
            for (int i = 1; i <= n; ++ i) {
                if (arr[i] == 1) tans ++;
            }
            cout << n << ' ' << tans;
        }
        return 0;
    }


    for (int i = 1; i <= n; ++ i) {
        ////cerr << i << ":\n";
        int idx = 1;
        for (int j = 1; j <= m; ++ j) {
            frt[j] = 0;
        }
        for (int j = i; j <= n; ++ j) {
            if (frt[arr[j]] != 0) {
                idx = frt[arr[j]];
                for (int k = 1; k <= m; ++ k) {
                    if (frt[k] > idx) frt[k] = 0;
                }
            }
            if (!frt[arr[j]]) {
                frt[arr[j]] = idx;
            }
            ////cerr << frt[1] << ' ';
            idx ++;
        }
        ////cerr << '\n';
        for (int k = 1; k <= m; ++ k) {
            ////cerr << frt[k] << ' ';
            if (frt[k] <= idx && frt[k] != 0) {
                ans[k] ++;
            }
        }
        ////cerr << '\n';
    }
    for (int i = 1; i <= m; ++ i) {
        cout << ans[i] << ' ';
        ////cerr << ans[i] << ' ';
    }
    return 0;
}
