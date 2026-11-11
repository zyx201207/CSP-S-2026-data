#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define debug cout << "ok" << endl

const int N = 5e5 + 10;
const int mod = 1e9 + 7;
const int inf = 1e9 + 10;

int n;
unsigned long long m;

int a[N];

// bool check(int x) {
//     for (int i = 1; i <= n; ++i) {

//     }
// }

void solve() {
    cin >> n >> m;
    int mx = -1e12 - 1, mn = 1e12 + 1;
    bool subA = 1, subB = 1;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
    }
    if ((mx - mn) <= m / n) {
        cout << n;
        return ;
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) {
        if (a[i] != i) subA = 0;
        if (i >= 3) if (a[i] - a[i - 1] != a[2] - a[1]) subB = 0;
    }
    if (subA) {
        int x = 0, ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (x + i > m) break ;
            x += i;
            ++ans;
            if (x == m) break ;
        }
        cout << ans + 1;
        return ;
    }
    if (subB) {
        int x = 0, ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (x + (a[2] - a[1]) * i > m) break ;
            x += (a[2] - a[1]) * i;
            ++ans;
            if (x == m) break ;
        }
        cout << ans + 1;
        return ;
    }
    deque<int> q;
    int ans = 1;
    unsigned long long sum = 0;
    for (int i = 1; i <= n; ++i) {
        // cout << a[q.front()] <<" "<< q.front() <<" "<<q.size()<<" "<<sum << " "<<i<<" ";
        // cout << sum << " ";
        // cout << ans << " ";
        while (!q.empty() && sum + (unsigned long long)(a[i] - a[q.back()]) * (q.size()) > m) {
            // debug;
            sum += (unsigned long long)(a[i] - a[q.back()]) * (unsigned long long)(q.size() - 1) - (a[q.back()] - a[q.front()]);
            q.pop_front();
        }
        if (!q.empty()) sum += (unsigned long long)(a[i] - a[q.back()]) * (unsigned long long)(q.size());
        else sum = 0;
        q.push_back(i);
        ans = max(ans, (int)q.size());
    }
    cout << ans;
    /*
    5 8
    -3 -1 2 2 7
    */
    // int l = 1, r = n;
    // while (l <= r) {
    //     int mid = (l + r) >> 1;
    //     if (check(mid)) l = mid + 1;
    //     else r = mid - 1;
    // }
    // cout << l + 1;
    return ;
}

signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1; // cin >> T;
    while (T--) solve();
    return 0;
}

// g++ -o a crystal.cpp -O2 -std=c++14 -static
