#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define debug cout << "ok" << endl

const int N = 2e5 + 10;
const int inf = 1e18;
const int mod = 1e9 + 7;

pair<int, char> a[N];

int pre[N];

void solve() {
    int n, tot = 0;
    cin >> n;
    string s;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].first >> a[i].second;
        string t;
        for (int j = 1; j <= a[i].first; ++j) t += a[i].second;
        s += t;
    }
    int ans = 0;
    for (int i = 0, j = s.size() - 1; i <= j; ++i, --j) {
        if (s[i] != s[j]) ++ans;
    }
    cout << ans;
    return ;
}

signed main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1; // cin >> T;
    while (T--) solve();
    return 0;
}
// g++ -o string string.cpp -O2 -std=c++14 -static
/*
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define debug cout << "ok" << endl

const int N = 2e5 + 10;
const int inf = 1e18;
const int mod = 1e9 + 7;

pair<int, char> t[N];

int pre[N];

pair<int, char> a[N], b[N];

void solve() {
    int n, tot = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> t[i].first >> t[i].second;
        tot += t[i].first;
    }
    bool flg = 1;
    int tmp = 0, cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= n; ++i) {
        if (tmp + t[i].first < (tot + 1) / 2) {
            a[++cnt1] = {t[i].first, t[i].second};
        } else if (tmp + t[i].first >= (tot + 1) / 2 && flg) {
            a[++cnt1] = {tmp + t[i].first - (tot + 1) / 2, t[i].second};
            b[++cnt2] = {t[i].first - (tmp + t[i].first - (tot + 1) / 2), t[i].second};
        } else {
            b[++cnt2] = {t[i].first, t[i].second};
        }
        tmp += t[i].first;
    }
    int ans = 0;
    if (tot % 2 == 0) {
        int i = 1, j = cnt2;
        for (; i <= cnt1 && j >= 1;) {
            if (a[i].second == b[j].second) {
                if (a[i].first > b[j].first) {
                    --j;
                    a[i].first = a[i].first - b[j].first;
                } else if (a[i].first == b[i].first) {
                    ++i;
                    --j;
                } else {
                    ++i;
                    b[j].first = b[j].first - a[i].first;
                }
            } else {
                if (a[i].first > b[j].first) {
                    --j;
                    a[i].first = a[i].first - b[j].first;
                    ans += abs(a[i].first - b[j].first);
                } else if (a[i].first == b[i].first) {
                    ++i;
                    --j;
                } else {
                    ++i;
                    b[j].first = b[j].first - a[i].first;
                    ans += abs(a[i].first - b[j].first);
                }
            }
        }
        cout << ans;
    } else {
        //cout << cnt1 <<" " << cnt2;
        int i = 1, j = cnt2;
        for (; i <= cnt1 && j >= 1;) {
            if (a[i].second == b[j].second) {
                if (a[i].first > b[j].first) {
                    --j;
                    a[i].first = a[i].first - b[j].first;
                } else if (a[i].first == b[i].first) {
                    ++i;
                    --j;
                } else {
                    ++i;
                    b[j].first = b[j].first - a[i].first;
                }
            } else {
                if (a[i].first > b[j].first) {
                    --j;
                    a[i].first = a[i].first - b[j].first;
                    ans += b[j].first;
                } else if (a[i].first == b[i].first) {
                    ++i;
                    --j;
                    ans += a[i].first;
                } else {
                    ++i;
                    b[j].first = b[j].first - a[i].first;
                    ans += a[i].first;
                }
            }
        }
        //cout << i <<" " << j;
        cout << ans;
    }
    return ;
}

signed main() {
    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
    // ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1; // cin >> T;
    while (T--) solve();
    return 0;
}
*/
